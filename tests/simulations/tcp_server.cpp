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

    cout << "Hanging on accept" << endl;
    server->accept();

    cout << "Connection Accepted" << endl;

    string * message = new string();
    long bytes = server->recv(message);

    cout << "Data Recieved" << endl;
    cout << (*message) << endl;

    cout << "Now Responding" << endl;

    server->send("Hello Back Mr. Client!");

    return 0;
}