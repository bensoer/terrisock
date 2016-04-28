//
// Created by bensoer on 20/12/15.
//

#include <netinet/in.h>
#include <ostream>
#include <netdb.h>
#include <string.h>
#include <iostream>
#include <arpa/inet.h>
#include "SocketAddress.h"

using namespace terrisock;

SocketAddress::~SocketAddress() {
    freeaddrinfo(this->DNSResolution);
}

SocketAddress::SocketAddress() {

}

SocketAddress::SocketAddress(addrinfo address) {
    struct addrinfo * info = new addrinfo();
    memset(info, 0, sizeof(*info)); // may cause issues if supposed ot be pointer or resolved ?
    *info = address;
    this->DNSResolution = info;
}

SocketAddress::SocketAddress(string address, unsigned short port) {


    struct addrinfo hints;
    struct addrinfo * res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = 0;
    hints.ai_flags = AI_NUMERICSERV;
    if(getaddrinfo(address.c_str(), to_string(port).c_str() , &hints, &res) != 0){
        cerr << "SocketAddress::SocketAddress - The DNS Resolution Could Not Resolve the Passed In Address" << endl;
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

addrinfo * SocketAddress::getAddressOf(int family, int type) {
    struct addrinfo * temp = new addrinfo();

    for(temp = this->DNSResolution; temp != NULL; temp = temp->ai_next){

        if(temp->ai_family == family && temp->ai_socktype == type){

            //cout << "Found Match:" << endl;
            //struct sockaddr_in * addr4 = (sockaddr_in*)temp->ai_addr;
            //cout << inet_ntoa(addr4->sin_addr) << ":" << to_string(ntohs(addr4->sin_port)) << endl;
            return temp;
        }

    }

    delete(temp);
    return NULL;
}

sockaddr* SocketAddress::getSocketAddress(int family, int type) {

    struct addrinfo * info = this->getAddressOf(family, type);
    if(info == NULL){
        return nullptr;
    }else{
        return info->ai_addr;
    }


}

socklen_t SocketAddress::getSocketAddressLength(int family, int type) {

    struct addrinfo * info = this->getAddressOf(family, type);
    if(info == NULL){
        return 0;
    }else{
        return info->ai_addrlen;
    }
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

