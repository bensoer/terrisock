//
// Created by bensoer on 19/12/15.
//

#ifndef TERRISOCK_TCPSOCKET_H
#define TERRISOCK_TCPSOCKET_H

#include "../Socket.h"
#include "../SocketAddress.h"

namespace terrisock {
    class TCPSocket: public Socket {

    private:

    protected:
        void setSocket(int socket);
        int getSocket();

    public:

        TCPSocket();
        TCPSocket(int version);

        void connect(SocketAddress * address);

        void getIStream();
        void getOStream();

        void shutdown();
        void shutdown(int how);
        void close();

        //temporary testing method
        int getNumber(){return 5;};

        long send(string message);
    };
}



#endif //TERRISOCK_TCPSOCKET_H
