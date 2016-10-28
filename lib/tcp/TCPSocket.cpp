//
// Created by bensoer on 19/12/15.
//

#include "TCPSocket.h"

using namespace std;
using namespace terrisock;

void TCPSocket::setSocket(int socket) {
    this->socket = socket;
}

int TCPSocket::getSocket() {
    return this->socket;
}

TCPSocket::TCPSocket() : Socket(AF_INET, SOCK_STREAM) {

}

TCPSocket::TCPSocket(int version) : Socket(version, SOCK_STREAM){

}

void TCPSocket::connect(SocketAddress * address){

        struct sockaddr * server = address->getSocketAddress(this->family, this->type);

        //struct sockaddr_in * server4 = (sockaddr_in *)server;

        //cout << " TCPSocket::connect - Connecting To: " << inet_ntoa(server4->sin_addr) << endl;

        if(server == nullptr){
            cerr << "TCPSocket::connect - An Address Does Not Exist For The Given Location. Connection Failed" << endl;
            exit(1);
        }else{

            if(::connect(this->socket, server , address->getSocketAddressLength(this->family, this->type)) == -1){
                cerr << "TCPSocket::connect - Failed To Connect To Server" << endl;
                perror("TCPSocket::connect - ");
                exit(1);
            }
        }


}

long TCPSocket::send(string message) {

    string cleanedMessage = this->cleanMessage(message);
    string * fullMessage = new string("{" + cleanedMessage + "}");
    long bytesSent = ::send(this->socket, fullMessage->c_str(), fullMessage->length(), 0);
    delete(fullMessage);
    return bytesSent;
}

long TCPSocket::recv(string * messageBuffer) {

    const int BUFFERSIZE = 2;
    string * totalMessage = messageBuffer;
    long totalBytes = 0;

    bool acceptNextLetter = false;

    while(1){

        char inbuf[BUFFERSIZE];
        long bytesRead = ::recv(this->socket, inbuf, BUFFERSIZE-1, 0);

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

void TCPSocket::shutdown() {
    ::shutdown(this->socket, SHUT_RDWR);
}

void TCPSocket::shutdown(int how) {
    ::shutdown(this->socket, how);
}

void TCPSocket::close() {
    ::close(this->socket);
}

