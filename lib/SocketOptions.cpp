//
// Created by bensoer on 23/04/16.
//

#include "SocketOptions.h"


using namespace std;
using namespace terrisock;

bool SocketOptions::setAddressReusable(Socket *socket) {

    int arg = 1;
    if(setsockopt(socket->getSocket(),SOL_SOCKET, SO_REUSEADDR, &arg, sizeof(arg)) == -1){
        return false;
    }else{
        return true;
    }
}

bool SocketOptions::getReuseAddressState(Socket *socket) {

    int result;
    socklen_t resultsize = sizeof(result);
    if(getsockopt(socket->getSocket(), SOL_SOCKET, SO_REUSEADDR, &result, &resultsize) == -1){
        cerr << "SocketOptions::getReuseAddressState - There Was An Error Fetching The Socket Option State" << endl;
    }

    if(result == 1){
        return true;
    }else{
        return false;
    }

}

bool SocketOptions::setPortReusable(Socket *socket) {

    int arg = 1;
    if(setsockopt(socket->getSocket(),SOL_SOCKET, SO_REUSEPORT, &arg, sizeof(arg)) == -1){
        return false;
    }else{
        return true;
    }
}

bool SocketOptions::getReusePortState(Socket *socket) {

    int result;
    socklen_t resultsize = sizeof(result);
    if(getsockopt(socket->getSocket(), SOL_SOCKET, SO_REUSEPORT, &result, &resultsize) == -1){
        cerr << "SocketOptions::getReuseAddressState - There Was An Error Fetching The Socket Option State" << endl;
    }

    if(result == 1){
        return true;
    }else{
        return false;
    }
}

bool SocketOptions::setOutOfBandDataInline(Socket *socket) {


    int arg = 1;
    if(setsockopt(socket->getSocket(),SOL_SOCKET, SO_OOBINLINE, &arg, sizeof(arg)) == -1){
        return false;
    }else{
        return true;
    }

}

bool SocketOptions::getOutOfBandDataInlineState(Socket *socket) {

    int result;
    socklen_t resultsize = sizeof(result);
    if(getsockopt(socket->getSocket(), SOL_SOCKET, SO_OOBINLINE, &result, &resultsize) == -1){
        cerr << "SocketOptions::getOutOfBandDataInlineState - There Was An Error Fetching The Socket Option State" << endl;
    }

    if(result == 1){
        return true;
    }else{
        return false;
    }
}

bool SocketOptions::setReceiveBufferSize(Socket *socket, int size) {

    if(setsockopt(socket->getSocket(),SOL_SOCKET, SO_RCVBUF, &size, sizeof(size)) == -1){
        return false;
    }else{
        return true;
    }

}

int SocketOptions::getReceiveBufferSize(Socket *socket) {

    int result;
    socklen_t resultsize = sizeof(result);
    if(getsockopt(socket->getSocket(), SOL_SOCKET, SO_RCVBUF, &result, &resultsize) == -1){
        cerr << "SocketOptions::getReceiveBufferSize - There Was An Error Fetching The Socket Option State" << endl;
        return 0;
    }else{
        return result;
    }
}

bool SocketOptions::setSendBufferSize(Socket *socket, int size) {

    if(setsockopt(socket->getSocket(),SOL_SOCKET, SO_SNDBUF, &size, sizeof(size)) == -1){
        return false;
    }else{
        return true;
    }

}

int SocketOptions::getSendBufferSize(Socket *socket) {

    int result;
    socklen_t resultsize = sizeof(result);
    if(getsockopt(socket->getSocket(), SOL_SOCKET, SO_SNDBUF, &result, &resultsize) == -1){
        cerr << "SocketOptions::getSendBufferSize - There Was An Error Fetching The Socket Option State" << endl;
        return 0;
    }else{
        return result;
    }

}

bool SocketOptions::setReceiveLowWaterMark(Socket *socket, int size) {

    if(setsockopt(socket->getSocket(),SOL_SOCKET, SO_RCVLOWAT, &size, sizeof(size)) == -1){
        return false;
    }else{
        return true;
    }
}

int SocketOptions::getReceiveLowWaterMark(Socket *socket) {

    int result;
    socklen_t resultsize = sizeof(result);
    if(getsockopt(socket->getSocket(), SOL_SOCKET, SO_RCVLOWAT, &result, &resultsize) == -1){
        cerr << "SocketOptions::getReceiveLowWaterMark - There Was An Error Fetching The Socket Option State" << endl;
        return 0;
    }else{
        return result;
    }
}

bool SocketOptions::setSendLowWaterMark(Socket *socket, int size) {

    if(setsockopt(socket->getSocket(),SOL_SOCKET, SO_SNDLOWAT, &size, sizeof(size)) == -1){
        return false;
    }else{
        return true;
    }

}

int SocketOptions::getSendLowWaterMark(Socket *socket) {

    int result;
    socklen_t resultsize = sizeof(result);
    if(getsockopt(socket->getSocket(), SOL_SOCKET, SO_SNDLOWAT, &result, &resultsize) == -1){
        cerr << "SocketOptions::getSendLowWaterMark - There Was An Error Fetching The Socket Option State" << endl;
        return 0;
    }else{
        return result;
    }
}