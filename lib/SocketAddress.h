//
// Created by bensoer on 20/12/15.
//

#ifndef TERRISOCK_SOCKETADDRESS_H
#define TERRISOCK_SOCKETADDRESS_H

#include "InetAddress.h"
#include <string>

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
