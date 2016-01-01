//
// Created by bensoer on 20/12/15.
//

#include "InetAddress4.h"
#include <netinet/in.h>

using namespace std;


using namespace terrisock;

void InetAddress4::setAddress(in_addr_t address) {
    this->address.s_addr = address;
}

