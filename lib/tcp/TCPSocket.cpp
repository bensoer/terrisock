//
// Created by bensoer on 19/12/15.
//

#include <iostream>
#include <netdb.h>
#include <unistd.h>
#include "TCPSocket.h"

using namespace terrisock;

void TCPSocket::setSocket(int socket) {
    this->socket = socket;
}

int TCPSocket::getSocket() {
    return this->socket;
}

TCPSocket::TCPSocket() {
    //create a TCP socket
    if((this->socket = ::socket(AF_INET, SOCK_STREAM, 0)) == -1){
        cerr << "TCPSocket::createSocket - Failed To Create A Socket" << endl;
        perror("TCPSocket::createSocket - ");
        exit(1);
    }
}


void TCPSocket::getIStream() {

}

void TCPSocket::getOStream() {

}

void TCPSocket::connect(SocketAddress address){

    if(::connect(this->socket, address.getSocketAddress(), sizeof(this->socket)) == -1){
        cerr << "TCPSocket::connect - Failed To Connect To Server" << endl;
        perror("TCPSocket::connect - ");
        exit(1);
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

