//
// Created by bensoer on 27/10/16.
//

#include <cstddef>
#include <cstring>
#include "TCPHeader.h"

using namespace terrisock;

TCPHeader::TCPHeader() {
    size_t size = sizeof(tcphdr);
    this->payload = new char[size];
    memset(this->payload,0,size);
    this->tcp = (tcphdr *)this->payload;
}