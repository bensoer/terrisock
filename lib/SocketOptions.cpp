//
// Created by bensoer on 23/04/16.
//

#include "SocketOptions.h"


void SocketOptions::setReuseAddress(bool enable) {
    this->reuseAddr = enable;
}

bool SocketOptions::getReuseAddress() {
    if(!this->reuseAddr == 0){
        return false;
    }else{
        return true;
    }
}