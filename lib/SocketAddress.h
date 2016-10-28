//
// Created by bensoer on 20/12/15.
//

#ifndef TERRISOCK_SOCKETADDRESS_H
#define TERRISOCK_SOCKETADDRESS_H

#include <netinet/in.h>
#include <ostream>
#include <netdb.h>
#include <string.h>
#include <iostream>
#include <arpa/inet.h>
#include <string>

#include "InetAddress.h"

using namespace std;

namespace terrisock {
    class SocketAddress {

    private:

        void resolveAndInit(string address, unsigned short port);

        struct addrinfo* DNSResolution = nullptr;

        addrinfo * getAddressOf(int family, int type);

    public:

        SocketAddress(string address, unsigned short port);
        SocketAddress();
        SocketAddress(addrinfo address);
        SocketAddress(sockaddr * address);

        sockaddr* getSocketAddress(int family, int type);
        socklen_t getSocketAddressLength(int family, int type);

        ~SocketAddress();

    };
}



#endif //TERRISOCK_SOCKETADDRESS_H
