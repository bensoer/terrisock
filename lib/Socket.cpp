//
// Created by bensoer on 19/12/15.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <iostream>
#include "Socket.h"

using namespace terrisock;
using namespace std;


void Socket::bind(int port) {

    //setup the network struct to bind to
    this->server.sin_family = AF_INET;
    this->server.sin_port = htons(port);
    this->server.sin_addr.s_addr = htonl(INADDR_ANY);

    //check the socket has been bound correctly
    if(!this->socketIsValid()){
        cerr << "Socket::bind - The Socket Is Invalid. A Socket Must Be Created Before It Can Be Bound To A Port" << endl;
        exit(1);
    }

    if (::bind(this->socket, (struct sockaddr *)&(this->server), sizeof(this->server)) == -1)
    {
        string message("Socket::bind - Failed to Bind Port: " + to_string(port) + " To Socket: " + to_string(this->socket));
        cerr << message << endl;
        exit(1);
    }else{
        cout << "Socket::bind - Successfully Bound Port " + to_string(port) + " To Socket" << endl;
    }
}

bool Socket::socketIsValid() {
    return this->socket != INT_MAX;
}