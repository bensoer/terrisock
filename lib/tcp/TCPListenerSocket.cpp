//
// Created by bensoer on 19/12/15.
//

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include "TCPListenerSocket.h"

using namespace std;
using namespace terrisock;

TCPListenerSocket::TCPListenerSocket() {

    //create a TCP socket
    if((this->socket = ::socket(AF_INET, SOCK_STREAM, 0)) == -1){
        cerr << "TCPListenerSocket::createSocket - Failed To Create A Socket" << endl;
        perror("TCPListenerSocket::createSocket - ");
        exit(1);
    }
}

void TCPListenerSocket::accept() {
    //TODO: Use of client created by this accept will likely break. Need better solution for SocketAddress

    socklen_t client_len = this->client.getSocketAddressLength();
    if((this->socketSession = ::accept(this->socket, this->client.getSocketAddress(), &client_len)) == -1){
        cerr << "TCPListenerSocket::accept - Failed To Accept Connection" << endl;
        //exit(1);
    }

}

void TCPListenerSocket::listen(int maxRequestQueue) {

    if(::listen(this->socket, maxRequestQueue) == -1){
        cerr << "TCPListenerSocket::listen - Failed To Start Listening For Connections" << endl;
        perror("TCPListenerSocket::listen - ");
        exit(1);
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