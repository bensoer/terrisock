//
// Created by bensoer on 27/10/16.
//

#ifndef TERRISOCK_TCPHEADER_H
#define TERRISOCK_TCPHEADER_H


#include "Payload.h"
#include <netinet/tcp.h>

namespace terrisock {

    class TCPHeader: public Payload {

    private:
        char * payload = nullptr;
        struct tcphdr * tcp = nullptr;
    public:

        TCPHeader();

        void setSourcePort(short sourcePort);
        void setDestinationPort(short destinationPort);

        void setSequenceNumber(int sequenceNumber);
        void setAcknowledgementNumber(int acknowledgementNumber);

        void setWindowSize(short windowSize);
        void setChecksum(short checksum);

        void setUrgentPointer(short urgentPointer);


    };
}



#endif //TERRISOCK_TCPHEADER_H
