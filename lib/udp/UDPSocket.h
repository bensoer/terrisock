//
// Created by bensoer on 19/12/15.
//

#ifndef TERRISOCK_UDPSOCKET_H
#define TERRISOCK_UDPSOCKET_H

#include <Socket.h>
#include <SocketAddress.h>
#include "UDPPacket.h"

namespace terrisock {
    class UDPSocket: public Socket {

    private:

        struct sockaddr * destination = nullptr;

    public:
        UDPSocket();
        UDPSocket(int version);

        int getSocket();
        void setSocket(int socket);

        long send(string message);
        long recv(string * messageBuffer);
        void connect(SocketAddress * address);

        long sendto(string message, SocketAddress * address);

        virtual void shutdown();
        virtual void shutdown(int how);
        virtual void close();
    };
}



#endif //TERRISOCK_UDPSOCKET_H
