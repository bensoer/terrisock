//
// Created by bensoer on 19/12/15.
//

#ifndef TERRISOCK_TCPSOCKET_H
#define TERRISOCK_TCPSOCKET_H

#include <iostream>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>

#include "../Socket.h"
#include "../SocketAddress.h"

namespace terrisock {
    class TCPSocket: public Socket {

    private:

    protected:


    public:

        void setSocket(int socket);
        int getSocket();

        TCPSocket();
        TCPSocket(int version);

        void connect(SocketAddress * address);

        //void getIStream();
        //void getOStream();

        void shutdown();
        void shutdown(int how);
        void close();

        long send(string message);
        long recv(string * message);
    };
}



#endif //TERRISOCK_TCPSOCKET_H
