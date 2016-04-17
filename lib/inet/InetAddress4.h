//
// Created by bensoer on 20/12/15.
//

#ifndef TERRISOCK_INETADDRESS4_H
#define TERRISOCK_INETADDRESS4_H

#include "InetAddress.h"
#include <string>
#include <netinet/in.h>

using namespace std;

namespace terrisock {

    /**
     * InetAddress4 functions as an Object Oriented wrapper around the in_addr struct and is configured
     * to functiona with the use of IPv4 addresses
     */
    class InetAddress4: public InetAddress {

    private:
        //struct for 32 bit address (IPv4)
        struct in_addr address;

    public:

        void setAddress(in_addr_t address);



    };
}



#endif //TERRISOCK_INETADDRESS4_H
