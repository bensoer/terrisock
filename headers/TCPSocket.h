//
// Created by bensoer on 19/12/15.
//

#ifndef TERRISOCK_TCPSOCKET_H
#define TERRISOCK_TCPSOCKET_H

#include "Socket.h"
#include "SocketAddress.h"

namespace terrisock {
    class TCPSocket: public Socket {

    private:

    protected:
        void setSocket(int socket);
        int getSocket();

    public:
        void connect(SocketAddress address);

        void getIStream();
        void getOStream();
    };
}



#endif //TERRISOCK_TCPSOCKET_H
