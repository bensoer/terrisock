//
// Created by bensoer on 27/10/16.
//

#include <SocketOptions.h>
#include "RawSocket.h"

using namespace terrisock;

RawSocket::RawSocket(int protocol) : Socket(AF_INET, SOCK_RAW, protocol){

    if(SocketOptions::setIPHeaderIncluded(this) == false){
        cerr << "RawSocket::RawSocket - Failed To Set IP_HDRINCL For Raw Socket" << endl;
    }

}

int RawSocket::getSocket() {
    return this->socket;
}

void RawSocket::setSocket(int socket) {

}

void RawSocket::close() {

}

long RawSocket::send(string message) {
    return 0;
}

void RawSocket::shutdown() {

}

void RawSocket::shutdown(int how) {

}

