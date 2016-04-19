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

        InetAddress* inetAddress;

        //struct sockaddr_in socketAddress;
        struct sockaddr socketAddress;
        //struct sockaddr_storage socketAddress;
        //struct hostent* DNSResolution;

        struct addrinfo* DNSResolution;

    public:

        SocketAddress(string address, unsigned short port);

        InetAddress* getInetAddress();
        sockaddr* getSocketAddress();

        int getFamily();
        int getSocketType();

        socklen_t getSocketAddressLength();


        ~SocketAddress();

    };
}



#endif //TERRISOCK_SOCKETADDRESS_H
