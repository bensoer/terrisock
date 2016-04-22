//
// Created by bensoer on 19/12/15.
//

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
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

TCPListenerSocket::~TCPListenerSocket(){
    delete(this->client);
}

TCPListenerSocket::TCPListenerSocket(int socket) {
    this->socket = socket;
}

void TCPListenerSocket::accept(bool exitOnFail) {

    struct sockaddr * client;
    socklen_t client_len = sizeof(*client);

    if((this->socketSession = ::accept(this->socket, client, &client_len)) == -1){
        cerr << "TCPListenerSocket::accept - Failed To Accept Connection" << endl;
        if(exitOnFail){
            exit(1);
        }
    }

    //create a SocketAddress object with client information
    if(client->sa_family = AF_INET){
        //this is an inet4 address

        struct sockaddr_in * client4 = (struct sockaddr_in *)client;

        //using inet_nto for backwards compatability on old systems only using IPv4
        this->client = new SocketAddress(inet_ntoa(client4->sin_addr), client4->sin_port);

    }else{
        //this is an inet6 address

        struct sockaddr_in6 * client6 = (struct sockaddr_in6 *)client;

        char buffer[INET6_ADDRSTRLEN];
        inet_ntop(AF_INET6, &(client6->sin6_addr), buffer, INET6_ADDRSTRLEN);
        this->client = new SocketAddress(string(buffer), client6->sin6_port);

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