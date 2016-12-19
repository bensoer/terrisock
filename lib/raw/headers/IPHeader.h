//
// Created by bensoer on 27/10/16.
//

#ifndef TERRISOCK_IPHEADER_H
#define TERRISOCK_IPHEADER_H

#include <netinet/ip.h>
#include <string>
#include "Payload.h"

using namespace std;

namespace terrisock{
    class IPHeader : public Payload{

    private:
        char * payload = nullptr;
        struct iphdr * ip = nullptr;

    public:

        IPHeader();

        void setHeaderLength(u_int16_t headerLength);
        void setVersion(u_int16_t version);
        void setTypeOfService(u_int16_t typeOfService);
        void setTotalLength(u_int16_t totalLength);
        void setID(int id);
        void setFragmentOffset(u_int16_t fragmentOffset);
        void setProtocol(u_int8_t protocol);
        void setChecksum(u_int16_t checksum);
        void setSourceAddress(string sourceAddress);
        void setDestinationAddress(string destinationAddress);

        char * getRawHeader();
        unsigned short * generatePseudoHeader();
    };



}



#endif //TERRISOCK_IPHEADER_H
