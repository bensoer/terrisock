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

    /*
    TCPSocket * socket = new TCPSocket();

    SocketAddress * address = new SocketAddress("localhost", 8001);

    socket->connect(address);

    cout << "Sending Greeting" << endl;
    long bytesSent = socket->send("{He}}llo Wor\\\\ld!}");

    cout << "Bytes sent: " << to_string(bytesSent) << endl;

    socket->shutdown();
    socket->close();

    delete(address);
    delete(socket);

    */

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