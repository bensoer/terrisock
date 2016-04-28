//
// Created by bensoer on 26/04/16.
//

#include <iostream>
#include <SocketAddress.h>
#include <tcp/TCPSocket.h>
#include <udp/UDPSocket.h>


using namespace std;
using namespace terrisock;

int main(){


    cout << "Setting Up UDP Socket" << endl;
    UDPSocket * socket = new UDPSocket();

    SocketAddress * address = new SocketAddress("localhost", 8001);

    //cout << "Connecting" << endl;
    //socket->connect(address);

    cout << "Sending" << endl;
    socket->sendto("Hello World!", address);

    cout << "Sent" << endl;


    return 0;

}