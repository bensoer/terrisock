//
// Created by bensoer on 20/12/15.
//

#ifndef TERRISOCK_SOCKETADDRESS_H
#define TERRISOCK_SOCKETADDRESS_H

#include "inet/InetAddress.h"
#include <string>

using namespace std;

namespace terrisock {
    class SocketAddress {

    private:

        InetAddress* inetAddress;
        struct sockaddr_in socketAddress;
        struct hostent* DNSResolution;

    public:
        InetAddress* getInetAddress();
        unsigned short getPort();



        void setFamily(short family);
        void setPort(unsigned short port);

        void setAddress(string address);

        //TODO: research into sockaddr_in structure and purpose of sin_zero attribute
        void setZero();

    };
}



#endif //TERRISOCK_SOCKETADDRESS_H
