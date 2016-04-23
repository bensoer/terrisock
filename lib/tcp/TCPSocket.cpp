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

TCPSocket::TCPSocket() : Socket(AF_INET, SOCK_STREAM) {

}

TCPSocket::TCPSocket(int version) : Socket(version, SOCK_STREAM){

}


void TCPSocket::getIStream() {

}

void TCPSocket::getOStream() {

}

void TCPSocket::connect(SocketAddress address){

        struct sockaddr * server = address.getSocketAddress(this->family, this->type);
        if(server == nullptr){
            cerr << "TCPSocket::connect - An Address Does Not Exist For The Given Location. Connection Failed" << endl;
            exit(1);
        }else{

            if(::connect(this->socket, server , address.getSocketAddressLength(this->family, this->type)) == -1){
                cerr << "TCPSocket::connect - Failed To Connect To Server" << endl;
                perror("TCPSocket::connect - ");
                exit(1);
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

