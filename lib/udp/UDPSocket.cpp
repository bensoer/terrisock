//
// Created by bensoer on 19/12/15.
//

#include <unistd.h>
#include <ostream>
#include <iostream>
#include "UDPSocket.h"

using namespace terrisock;

UDPSocket::UDPSocket(): Socket(AF_INET, SOCK_DGRAM) {

}

UDPSocket::UDPSocket(int version) : Socket(version, SOCK_DGRAM){

}

long UDPSocket::send(string message) {

    if(this->destination == nullptr){
        cerr << "UDPSocket::send - Can't Send Data Without A Resolvable Destination Address. Call UDPSocket::connect first or call UDPSocket::sendto" << endl;
    }else{

        string cleanedMessage = this->cleanMessage(message);
        string * fullMessage = new string("{" + cleanedMessage + "}");
        long bytesSent = ::sendto(this->socket, fullMessage->c_str(), fullMessage->length(), 0, this->destination, sizeof(*this->destination));
        delete(fullMessage);
        return bytesSent;
    }
}

long UDPSocket::sendto(string message, SocketAddress *address) {

    struct sockaddr * server = address->getSocketAddress(this->family, this->type);
    if(server == nullptr){
        cerr << "UDPSocket::sendto - A UDP Address Does Not Exist For The Given Endpoint. Failed To Send Message" << endl;
        return 0;
    }else{

        string cleanedMessage = this->cleanMessage(message);
        string * fullMessage = new string("{" + cleanedMessage + "}");
        long bytesSent = ::sendto(this->socket, fullMessage->c_str(), fullMessage->length(), 0, server, sizeof(*server));
        delete(fullMessage);
        delete(server);
        return bytesSent;

    }

}

long UDPSocket::recv(string *messageBuffer) {


    const int BUFFERSIZE = 2;
    string * totalMessage = messageBuffer;
    long totalBytes = 0;

    bool acceptNextLetter = false;

    struct sockaddr messageSource;
    socklen_t messageSourceSize = sizeof(messageSource);

    while(1){

        char inbuf[BUFFERSIZE];
        long bytesRead = ::recvfrom(this->socket, inbuf, BUFFERSIZE-1, 0, &messageSource, &messageSourceSize);

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

void UDPSocket::connect(SocketAddress *address) {

    struct sockaddr * server = address->getSocketAddress(this->family, this->type);
    if(server == nullptr){
        cerr << "UDPSocket::connect - An Address Does Not Exist For The Given Location. Cannot Ensure Resolvable Address" << endl;
    }else{
        this->destination = server;
    }
}

int UDPSocket::getSocket() {
    return this->socket;
}

void UDPSocket::setSocket(int socket) {
    this->socket = socket;
}

void UDPSocket::close() {
    ::close(this->socket);
}

void UDPSocket::shutdown(int how) {
    ::shutdown(this->socket, how);
}

void UDPSocket::shutdown() {
    ::shutdown(this->socket, SHUT_RDWR);
}