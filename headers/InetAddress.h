//
// Created by bensoer on 20/12/15.
//

#ifndef TERRISOCK_INETADDRESS_H
#define TERRISOCK_INETADDRESS_H


#include <netinet/in.h>

namespace terrisock {
    class InetAddress {

        //TODO Any important implementations needed have to be here


    public :
        virtual void setAddress(in_addr_t address) = 0;
        virtual ~InetAddress(){};
    };
}



#endif //TERRISOCK_INETADDRESS_H
