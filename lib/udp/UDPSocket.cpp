//
// Created by bensoer on 19/12/15.
//

#include <unistd.h>
#include "UDPSocket.h"

using namespace terrisock;

UDPSocket::UDPSocket(): Socket(AF_INET, SOCK_DGRAM) {

}

UDPSocket::UDPSocket(int version) : Socket(version, SOCK_DGRAM){

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