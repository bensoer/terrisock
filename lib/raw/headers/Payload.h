//
// Created by bensoer on 19/12/16.
//

#ifndef TERRISOCK_PAYLOAD_H
#define TERRISOCK_PAYLOAD_H


class Payload {

public:

    virtual char * getRawHeader() = 0;

    virtual unsigned short * generatePseudoHeader() = 0;
};


#endif //TERRISOCK_PAYLOAD_H
