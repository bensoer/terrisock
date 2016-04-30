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



    UDPSocket * server = new UDPSocket();
    server->bind(8001);

    cout << "Finished Bind" << endl;

    cout << "Hanging on recv" << endl;

    string * message = new string();
    SocketAddress * source = new SocketAddress();


    long bytesRecieved = server->recvfrom(message, source);

    cout << "Bytes Received: " << to_string(bytesRecieved) << endl;
    cout << "Mesage Received: >" << (*message) << "<" << endl;

    cout << "Now Responding" << endl;

    long bytesSent = server->sendto("Hello Back UDP Client!", source);

    cout << "Bytes Sent: " << to_string(bytesSent) << endl;



    return 0;

}