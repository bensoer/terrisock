//
// Created by bensoer on 19/12/15.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <iostream>
#include <arpa/inet.h>
#include <string.h>
#include <algorithm>
#include "Socket.h"

using namespace terrisock;
using namespace std;

Socket::Socket(int family, int type) {

    this->family = family;
    this->type = type;

    if((this->socket = ::socket(family, type, 0)) == -1){
        cerr << "Socket::Socket - Failed To Create A Socket" << endl;
        perror("Socket::Socket - ");
        exit(1);
    }

}

void Socket::bind(int port) {

    //check the socket has been setup correctly
    if(!this->socketIsValid()){
        cerr << "Socket::bind - The Socket Is Invalid. A Socket Must Be Created Before It Can Be Bound To A Port" << endl;
        exit(1);
    }

    //setup the network struct to bind to
    if(this->family == AF_INET){

        struct sockaddr_in server4;

        memset(&server4, 0, sizeof(server4));
        server4.sin_family = AF_INET;
        server4.sin_port = htons(port);
        server4.sin_addr.s_addr = htonl(INADDR_ANY);

        if (::bind(this->socket, (struct sockaddr *)&(server4), sizeof(server4)) == -1)
        {
            string message("Socket::bind - Failed to Bind Port: " + to_string(port) + " To Socket: " + to_string(this->socket));
            cerr << message << endl;
            exit(1);
        }else{
            //cout << "Socket::bind - Successfully Bound Port " + to_string(port) + " To Socket" << inet_ntoa(server4.sin_addr) << endl;
        }

    }else if(this->family == AF_INET6){

        struct sockaddr_in6 server6;

        memset(&server6, 0, sizeof(server6));
        server6.sin6_family = AF_INET6;
        server6.sin6_port = htons(port);
        server6.sin6_addr = in6addr_any;

        if (::bind(this->socket, (struct sockaddr *)&(server6), sizeof(server6)) == -1)
        {
            string message("Socket::bind - Failed to Bind Port: " + to_string(port) + " To Socket: " + to_string(this->socket));
            cerr << message << endl;
            exit(1);
        }else{
            //cout << "Socket::bind - Successfully Bound Port " + to_string(port) + " To Socket" << endl;
        }

    }else{
        cerr << "Socket::bind - No Valid Family Is Set For The Socket. Bind Failed" << endl;
        exit(1);
    }
}

string Socket::cleanMessage(string message) {

    string finalString;

    for_each(message.begin(), message.end(), [&finalString](char character){

        if(strcmp(&character, "{")==0){

            finalString.push_back('\\');
            finalString.push_back(character);

        }else if(strcmp(&character, "}")==0){

            finalString.push_back('\\');
            finalString.push_back(character);

        }else if(strcmp(&character, "\\")==0){

            finalString.push_back('\\');
            finalString.push_back(character);

        }else{

            finalString += character;
        }

    });

    return finalString;

}

bool Socket::socketIsValid() {
    return this->socket != INT_MAX;
}