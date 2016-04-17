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

InetAddress* SocketAddress::getInetAddress() {
    return this->inetAddress;
}

unsigned short SocketAddress::getPort() {
    return ntohs(this->socketAddress.sin_port);
}

void SocketAddress::setFamily(short family) {
    this->socketAddress.sin_family = (sa_family_t)family;
}

void SocketAddress::setPort(unsigned short port) {
    this->socketAddress.sin_port = htons(port);
}

void SocketAddress::setAddress(string address) {

    if ((this->DNSResolution = gethostbyname(address.c_str())) == NULL)
    {
        cerr << "SocketAddress::setAddress - The DNS Resolution Could Not Resolve the Passed In Address" << endl;
        exit(1);
    }

    //TODO: Implement something more graceful. This works but is ugly
    bcopy(this->DNSResolution->h_addr, (char *)&(this->socketAddress.sin_addr), this->DNSResolution->h_length);
    this->inetAddress->setAddress(this->socketAddress.sin_addr.s_addr);

}

void SocketAddress::setZero() {

}