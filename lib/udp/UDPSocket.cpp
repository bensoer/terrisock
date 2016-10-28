//
// Created by bensoer on 19/12/15.
//

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
        //delete(server);
        return bytesSent;

    }

}

long UDPSocket::recvfrom(string *messageBuffer, SocketAddress *sourceAddress) {

    const int BUFFERSIZE = SocketOptions::getReceiveBufferSize(this);
    struct sockaddr messageSource;
    socklen_t messageSourceSize = sizeof(messageSource);

    char inbuf[BUFFERSIZE];

    long bytesRead = ::recvfrom(this->socket, inbuf, BUFFERSIZE-1, 0, &messageSource, &messageSourceSize);
    //remove whatever they sent, we need to reconstruct one
    delete(sourceAddress);
    sourceAddress = new SocketAddress(&messageSource);

    string content(inbuf);
    long contentLength = content.length();
    bool acceptCharacter = false;
    for_each(content.begin(), content.end(), [&acceptCharacter, &messageBuffer, &contentLength](char character){

        if(acceptCharacter){
            messageBuffer->push_back(character);
            acceptCharacter = false;
        }else{

            char slash = '\\';
            char openBrace = '{';
            char closeBrace = '}';

            if(character == slash){
                acceptCharacter = true;
                contentLength--;
            }else if(character == openBrace){
                contentLength--;
            }else if(character == closeBrace){
                contentLength--;
            }else{
                messageBuffer->push_back(character);
            }
        }
    });

    return contentLength;
}

long UDPSocket::recv(string *messageBuffer) {

    SocketAddress * sourceAddress = new SocketAddress();
    long bytesReceived =  this->recvfrom(messageBuffer, sourceAddress);
    delete(sourceAddress);
    return bytesReceived;
}

void UDPSocket::connect(SocketAddress *address) {

    struct sockaddr * server = address->getSocketAddress(this->family, this->type);
    if(server == nullptr){
        cerr << "UDPSocket::connect - An Address Does Not Exist For The Given Location. Cannot Ensure Resolvable Address" << endl;
    }else{
        //cout << "Connection Successful" << endl;

        //struct sockaddr_in * server4 = (sockaddr_in *) server;
        //cout << inet_ntoa(server4->sin_addr ) << ":" << (int)server4->sin_port << endl ;
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