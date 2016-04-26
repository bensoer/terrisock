//
// Created by bensoer on 26/04/16.
//

#include <iostream>
#include <tcp/TCPListenerSocket.h>

using namespace std;
using namespace terrisock;


int main(){

    TCPListenerSocket * server = new TCPListenerSocket();
    server->bind(8001);
    server->listen(10);

    server->accept();

    return 0;
}