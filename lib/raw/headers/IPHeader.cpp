//
// Created by bensoer on 27/10/16.
//

#include <dnet.h>
#include "IPHeader.h"

using namespace terrisock;

void IPHeader::setVersion(u_int16_t version) {
    this->IPHeader.version = version;
}

void IPHeader::setChecksum(u_int16_t checksum) {
    this->IPHeader.check = checksum;
}

void IPHeader::setDestinationAddress(string destinationAddress) {
    this->IPHeader.daddr = inet_addr(destinationAddress.c_str());
}

void IPHeader::setSourceAddress(string sourceAddress) {
    this->IPHeader.saddr = inet_addr(sourceAddress.c_str());
}

void IPHeader::setFragmentOffset(u_int16_t fragmentOffset) {
    this->IPHeader.frag_off = fragmentOffset;
}

void IPHeader::setHeaderLength(u_int16_t headerLength) {
    this->IPHeader.tot_len = headerLength;
}

void IPHeader::setTypeOfService(u_int16_t typeOfService) {
    this->IPHeader.tos = typeOfService;
}

void IPHeader::setID(int id) {
    this->IPHeader.id = htonl(id);
}

void IPHeader::setTotalLength(u_int16_t totalLength) {
    this->IPHeader.tot_len = totalLength;
}

void IPHeader::setProtocol(u_int8_t protocol) {
    this->IPHeader.protocol = protocol;
}