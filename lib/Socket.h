//
// Created by bensoer on 19/12/15.
//

#ifndef TERRISOCK_SOCKET_H
#define TERRISOCK_SOCKET_H

#include <netinet/in.h>
#include <limits.h>

namespace terrisock {
    class Socket {

    private:
        struct sockaddr_in server;

        bool socketIsValid();

    protected:
        int socket = INT_MAX;

        virtual void setSocket(int socket) = 0;
        virtual int getSocket() = 0;

        virtual ~Socket(){};

    public:

        virtual void bind(int port);

        virtual void shutdown() = 0;
        virtual void shutdown(int how) = 0;
        virtual void close() = 0;

    };
}



#endif //TERRISOCK_SOCKET_H
