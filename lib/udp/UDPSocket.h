//
// Created by bensoer on 19/12/15.
//

#ifndef TERRISOCK_UDPSOCKET_H
#define TERRISOCK_UDPSOCKET_H

#include <Socket.h>

namespace terrisock {
    class UDPSocket: public Socket {

    public:
        UDPSocket();
        UDPSocket(int version);

        int getSocket();
        void setSocket(int socket);

        long send(string message);

        virtual void shutdown();
        virtual void shutdown(int how);
        virtual void close();
    };
}



#endif //TERRISOCK_UDPSOCKET_H
