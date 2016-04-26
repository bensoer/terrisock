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
        int socketSession = -1;

        SocketAddress * client = nullptr;

    protected:

        void setSocket(int socket);
        int getSocket();


    public:

        TCPListenerSocket();
        TCPListenerSocket(int version);

        ~TCPListenerSocket();

        long send(string message);
        long recv(string * messageBuffer);


        void shutdown();
        void shutdown(int how);
        void close();

        void accept(bool exitOnFail = false);
        void listen(int maxRequestQueue);
    };
}



#endif //TERRISOCK_TCPLISTENERSOCKET_H
