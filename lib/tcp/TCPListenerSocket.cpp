//
// Created by bensoer on 19/12/15.
//

#include "TCPListenerSocket.h"

using namespace std;
using namespace terrisock;


TCPListenerSocket::TCPListenerSocket() : Socket(AF_INET, SOCK_STREAM) {

}

TCPListenerSocket::TCPListenerSocket(int version) : Socket(version, SOCK_STREAM) {

}

TCPListenerSocket::~TCPListenerSocket(){
    delete(this->client);
}


void TCPListenerSocket::accept(bool exitOnFail) {

    struct sockaddr * client = new sockaddr();
    socklen_t client_len = sizeof(*client);

    if((this->socketSession = ::accept(this->socket, client, &client_len)) == -1){
        cerr << "TCPListenerSocket::accept - Failed To Accept Connection" << endl;
        if(exitOnFail){
            exit(1);
        }
    }

    //create a SocketAddress object with client information
    this->client = new SocketAddress(client);
    delete(client);

}

void TCPListenerSocket::listen(int maxRequestQueue) {

    if(::listen(this->socket, maxRequestQueue) == -1){
        cerr << "TCPListenerSocket::listen - Failed To Start Listening For Connections" << endl;
        perror("TCPListenerSocket::listen - ");
        exit(1);
    }


}

long TCPListenerSocket::send(string message) {
    if(this->socketSession == -1){
        cerr << "TCPListenerSocket::send - Cannot Send Message. A Connection Must Be Established First" << endl;
        return 0;
    }else{
        string cleanedMessage = this->cleanMessage(message);
        string * fullMessage = new string("{" + cleanedMessage + "}");
        long bytesSent = ::send(this->socketSession, fullMessage->c_str(), fullMessage->length(), 0);
        delete(fullMessage);
        return bytesSent;
    }
}

long TCPListenerSocket::recv(string * messageBuffer) {

    const int BUFFERSIZE = 2;
    string * totalMessage = messageBuffer;
    long totalBytes = 0;

    bool acceptNextLetter = false;

    while(1){

        char inbuf[BUFFERSIZE];
        long bytesRead = ::recv(this->socketSession, inbuf, BUFFERSIZE-1, 0);

        if(bytesRead <= 0){
            //here we assume the conneciton has terminated. Return the total bytes
            return totalBytes;
        }else{
            inbuf[BUFFERSIZE-1] = '\0';

            string segment(inbuf);

            //cout << "Got segment: >" << segment << "<" << endl;

            //means an escape character was found. blindly accept the next character
            if(acceptNextLetter){

                totalBytes += bytesRead;
                (*totalMessage) += segment;
                acceptNextLetter = false; //revert back to normal for everything else

            }else{

                if(segment.compare("{") == 0){
                    //this is our extras, we don't want to include it
                    continue;

                }else if(segment.compare("}") == 0){
                    //here we assume the end of a message has arrived. Return the total bytes

                    return totalBytes;
                }else{

                    //this is a valid character. Unless it is an escape character

                    if(segment.compare("\\") == 0){
                        //an escape character was found, blindly accept the next character and do nothing with this
                        //escape character
                        //cout << "FOUND AN ESCAPE CHARACTER" << endl;
                        acceptNextLetter = true;
                        continue;
                    }else{
                        //not an escaped character, and not an opening or closing character, added it.
                        totalBytes += bytesRead;
                        (*totalMessage) += segment;
                    }

                }

            }

        }

    }

}

void TCPListenerSocket::setSocket(int socket) {
    this->socket = socket;
}

int TCPListenerSocket::getSocket() {
    return this->socket;
}

void TCPListenerSocket::shutdown() {
    ::shutdown(this->socketSession, SHUT_RDWR);
    ::shutdown(this->socket, SHUT_RDWR);
}

void TCPListenerSocket::shutdown(int how) {
    ::shutdown(this->socketSession, how);
    ::shutdown(this->socket, how);
}

void TCPListenerSocket::close() {
    ::close(this->socketSession);
    ::close(this->socket);
}