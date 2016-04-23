//
// Created by bensoer on 23/04/16.
//

#ifndef TERRISOCK_SOCKETOPTIONS_H
#define TERRISOCK_SOCKETOPTIONS_H


class SocketOptions {

private:

    int reuseAddr = 0;

public:

    void setReuseAddress(bool enable);
    bool getReuseAddress();

};


#endif //TERRISOCK_SOCKETOPTIONS_H
