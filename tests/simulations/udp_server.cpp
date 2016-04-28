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
    long bytesRecieved = server->recv(message);

    cout << "Bytes Received: " << to_string(bytesRecieved) << endl;
    cout << "Mesage Received: >" << (*message) << "<" << endl;



    return 0;

}