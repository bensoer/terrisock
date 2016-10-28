//
// Created by bensoer on 23/04/16.
//

#ifndef TERRISOCK_SOCKETOPTIONS_H
#define TERRISOCK_SOCKETOPTIONS_H

#include <iostream>

#include "Socket.h"

namespace terrisock {
    class SocketOptions {

    private:



    public:

        static bool setAddressReusable(Socket * socket);
        static bool getReuseAddressState(Socket * socket);

        static bool setPortReusable(Socket * socket);
        static bool getReusePortState(Socket * socket);

        static bool setOutOfBandDataInline(Socket * socket);
        static bool getOutOfBandDataInlineState(Socket * socket);

        static bool setReceiveBufferSize(Socket * socket, int size);
        static int getReceiveBufferSize(Socket * socket);

        static bool setSendBufferSize(Socket * socket, int size);
        static int getSendBufferSize(Socket * socket);

        static bool setReceiveLowWaterMark(Socket * socket, int size);
        static int getReceiveLowWaterMark(Socket * socket);

        static bool setSendLowWaterMark(Socket * socket, int size);
        static int getSendLowWaterMark(Socket * socket);

        static bool setIPHeaderIncluded(Socket * socket);
        static int getIPHeaderIncludeState(Socket * socket);

    };
}




#endif //TERRISOCK_SOCKETOPTIONS_H
