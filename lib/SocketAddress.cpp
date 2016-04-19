//
// Created by bensoer on 20/12/15.
//

#include <netinet/in.h>
#include <ostream>
#include <netdb.h>
#include <string.h>
#include <iostream>
#include "SocketAddress.h"

using namespace terrisock;

SocketAddress::~SocketAddress() {
    freeaddrinfo(this->DNSResolution);
}

SocketAddress::SocketAddress() {

}

SocketAddress::SocketAddress(string address, unsigned short port) {


    struct addrinfo hints;
    struct addrinfo * res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if(getaddrinfo(address.c_str(), to_string(port).c_str() , &hints, &res) != 0){
        cerr << "SocketAddress::setAddress - The DNS Resolution Could Not Resolve the Passed In Address" << endl;
        exit(1);
    }

    //IPV4
    //memcpy((char *)&(this->socketAddress.sin_port), this->DNSResolution->h_addr, this->DNSResolution->h_length);

    //IPVNEUTRAL
    //copy resolution info to DNSResolution
    //memcpy(&(this->DNSResolution), res, sizeof(res));
    this->DNSResolution = res;

    //copy address to the socket address
    memcpy(&(this->socketAddress), res->ai_addr, res->ai_addrlen);


    //freeaddrinfo(res);

    //bcopy(hp->h_addr, (char *)&(this->server.sin_addr), hp->h_length);


    //set the intetaddress object
    //this->inetAddress->setAddress(this->socketAddress.sin_addr.s_addr);
}

InetAddress* SocketAddress::getInetAddress() {
    return this->inetAddress;
}

sockaddr* SocketAddress::getSocketAddress() {
    return this->DNSResolution->ai_addr;
}

socklen_t SocketAddress::getSocketAddressLength() {
    return this->DNSResolution->ai_addrlen;
}

int SocketAddress::getFamily() {
    return this->DNSResolution->ai_family;
}

int SocketAddress::getSocketType() {
    return this->DNSResolution->ai_socktype;
}




/*
void SocketAddress::setAddress(string address, unsigned short port) {
//http://stackoverflow.com/questions/11453390/setting-ipv4-ipv6-address-and-port-to-a-sockaddr-storage-structure
// http://long.ccaba.upc.edu/long/045Guidelines/eva/ipv6.html

    //TODO: inet objects should be involved in this functionality. So as to assign InetAddress object something

    //IPV4
*//*    if ((this->DNSResolution = gethostbyname(address.c_str())) == NULL)
    {
        cerr << "SocketAddress::setAddress - The DNS Resolution Could Not Resolve the Passed In Address" << endl;
        exit(1);
    }
*//*
    struct addrinfo hints;
    struct addrinfo * res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if(getaddrinfo(address.c_str(), to_string(port).c_str() , &hints, &res) != 0){

        cerr << "SocketAddress::setAddress - The DNS Resolution Could Not Resolve the Passed In Address" << endl;
        exit(1);
    }


    //IPV4
    //memcpy((char *)&(this->socketAddress.sin_port), this->DNSResolution->h_addr, this->DNSResolution->h_length);

    //IPVNEUTRAL
    //copy resolution info to DNSResolution
    memcpy(&(this->DNSResolution), res, sizeof(res));

    //copy address to the socket address
    memcpy(&(this->socketAddress), res->ai_addr, res->ai_addrlen);


    freeaddrinfo(res);

    //bcopy(hp->h_addr, (char *)&(this->server.sin_addr), hp->h_length);


    //set the intetaddress object
    //this->inetAddress->setAddress(this->socketAddress.sin_addr.s_addr);

}
*/

