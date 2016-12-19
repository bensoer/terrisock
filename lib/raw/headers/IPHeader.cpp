//
// Created by bensoer on 27/10/16.
//

#include <dnet.h>
#include "IPHeader.h"

using namespace terrisock;

IPHeader::IPHeader() {
    size_t size = sizeof(iphdr);
    this->payload = new char[size];
    this->ip = (iphdr *)this->payload;
}

void IPHeader::setVersion(u_int16_t version) {
    this->ip->version = version;
}

void IPHeader::setChecksum(u_int16_t checksum) {
    this->ip->check = checksum;
}

void IPHeader::setDestinationAddress(string destinationAddress) {
    this->ip->daddr = inet_addr(destinationAddress.c_str());
}

void IPHeader::setSourceAddress(string sourceAddress) {
    this->ip->saddr = inet_addr(sourceAddress.c_str());
}

void IPHeader::setFragmentOffset(u_int16_t fragmentOffset) {
    this->ip->frag_off = fragmentOffset;
}

void IPHeader::setHeaderLength(u_int16_t headerLength) {
    this->ip->tot_len = headerLength;
}

void IPHeader::setTypeOfService(u_int16_t typeOfService) {
    this->ip->tos = typeOfService;
}

void IPHeader::setID(int id) {
    this->ip->id = htonl(id);
}

void IPHeader::setTotalLength(u_int16_t totalLength) {
    this->ip->tot_len = totalLength;
}

void IPHeader::setProtocol(u_int8_t protocol) {
    this->ip->protocol = protocol;
}

char* IPHeader::getRawHeader() {
    return this->payload;
}

unsigned short* IPHeader::generatePseudoHeader() {
    //return this->payload;
}