//
// Created by bensoer on 27/10/16.
//

#ifndef TERRISOCK_RAWSOCKET_H
#define TERRISOCK_RAWSOCKET_H

#include "../Socket.h"

namespace terrisock{
    class RawSocket: public Socket{

    public:

        RawSocket(int protocol);

        void setSocket(int socket);
        int getSocket();

        void shutdown();
        void shutdown(int how);
        void close();

        long send(string message);
    };
}



#endif //TERRISOCK_RAWSOCKET_H
