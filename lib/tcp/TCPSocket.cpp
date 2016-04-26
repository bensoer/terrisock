//
// Created by bensoer on 19/12/15.
//

#include <iostream>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
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


void TCPSocket::getIStream() {

}

void TCPSocket::getOStream() {

}

void TCPSocket::connect(SocketAddress address){

        struct sockaddr * server = address.getSocketAddress(this->family, this->type);

        //struct sockaddr_in * server4 = (sockaddr_in *)server;

        //cout << " TCPSocket::connect - Connecting To: " << inet_ntoa(server4->sin_addr) << endl;

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

long TCPSocket::send(string message) {

    string cleanedMessage = this->cleanMessage(message);
    string * fullMessage = new string("{" + cleanedMessage + "}");
    long bytesSent = ::send(this->socket, fullMessage->c_str(), fullMessage->length(), 0);
    delete(fullMessage);
    return bytesSent;
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

