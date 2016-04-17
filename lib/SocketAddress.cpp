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

sockaddr* SocketAddress::getSocketAddress() {
    return (struct sockaddr *)&(this->socketAddress);
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
//http://stackoverflow.com/questions/11453390/setting-ipv4-ipv6-address-and-port-to-a-sockaddr-storage-structure
// http://long.ccaba.upc.edu/long/045Guidelines/eva/ipv6.html

    //TODO: inet objects should be involved in this functionality. So as to assign InetAddress object something

    //IPV4
/*    if ((this->DNSResolution = gethostbyname(address.c_str())) == NULL)
    {
        cerr << "SocketAddress::setAddress - The DNS Resolution Could Not Resolve the Passed In Address" << endl;
        exit(1);
    }
*/
    struct addrinfo hints;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if(getaddrinfo(address.c_str(), NULL, &hints, &(this->DNSResolution)) != 0){

        cerr << "SocketAddress::setAddress - The DNS Resolution Could Not Resolve the Passed In Address" << endl;
        exit(1);
    }


    //IPV4
    //memcpy((char *)&(this->socketAddress.sin_port), this->DNSResolution->h_addr, this->DNSResolution->h_length);

    //IPVNEUTRAL
    memcpy(&(this->socketAddress), this->DNSResolution->ai_addr, this->DNSResolution->ai_addrlen);


    //set the intetaddress object
    //this->inetAddress->setAddress(this->socketAddress.sin_addr.s_addr);

}

void SocketAddress::setZero() {
    cerr << "SockAddress:setZero - This Function Has Not Been Implemented. Please Do Not Use";
    exit(1);
}