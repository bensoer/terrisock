//
// Created by bensoer on 19/12/15.
//

#ifndef TERRISOCK_TCPLISTENERSOCKET_H
#define TERRISOCK_TCPLISTENERSOCKET_H

#include <Socket.h>
#include <SocketAddress.h>

namespace terrisock {
    class TCPListenerSocket: public Socket {

    private:
        int socketSession;

        //SocketAddress client;

    protected:

        void setSocket(int socket);
        int getSocket();


    public:

        TCPListenerSocket();

        void shutdown();
        void shutdown(int how);
        void close();

        void accept();
        void listen(int maxRequestQueue);
    };
}



#endif //TERRISOCK_TCPLISTENERSOCKET_H
