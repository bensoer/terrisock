//
// Created by bensoer on 26/04/16.
//

#include <iostream>
#include <SocketAddress.h>
#include <tcp/TCPSocket.h>


using namespace std;
using namespace terrisock;

int main(){

    TCPSocket * socket = new TCPSocket();

    SocketAddress * address = new SocketAddress("localhost", 8001);

    socket->connect(address);

    cout << "Sending Greeting" << endl;
    long bytesSent = socket->send("{He}}llo Wor\\\\ld!}");

    cout << "Bytes sent: " << to_string(bytesSent) << endl;

    string * response = new string();
    long bytesRecvd = socket->recv(response);

    cout << "Bytes Recieved: " << to_string(bytesRecvd) << endl;
    cout << "Response: >" << *response << "<" << endl;

    socket->shutdown();
    socket->close();

    delete(address);
    delete(socket);



    return 0;

}