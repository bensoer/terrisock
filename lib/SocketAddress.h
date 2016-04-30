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

        InetAddress* inetAddress;

        //struct sockaddr_in socketAddress;
        struct sockaddr socketAddress;
        //struct sockaddr_storage socketAddress;
        //struct hostent* DNSResolution;

        struct addrinfo* DNSResolution = nullptr;

        addrinfo * getAddressOf(int family, int type);

    public:

        SocketAddress(string address, unsigned short port);
        SocketAddress();
        SocketAddress(addrinfo address);
        SocketAddress(sockaddr * address);

        InetAddress* getInetAddress();


        sockaddr* getSocketAddress(int family, int type);
        socklen_t getSocketAddressLength(int family, int type);


        int getFamily();
        int getSocketType();




        ~SocketAddress();

    };
}



#endif //TERRISOCK_SOCKETADDRESS_H
