//
// Created by bensoer on 12/04/16.
//

//#include <tcp/TCPListenerSocket.h>
//#include <udp/UDPSocket.h>
#include "gtest/gtest.h"
//#include "TCPSocket.h"
#include "terrisock.h"

using namespace terrisock;


TEST(basic_check, test_tcp_clnt_google_domain){


    TCPSocket * socket = new TCPSocket();

    SocketAddress * destination = new SocketAddress("google.com", 80);

    socket->connect(destination);

    EXPECT_EQ(5,5);

    delete(destination);
    delete(socket);

}

TEST(basic_check, test_tcp_clnt_google_num){


    TCPSocket * socket = new TCPSocket();

    SocketAddress * destination = new SocketAddress("216.58.216.142", 80);

    socket->connect(destination);

    EXPECT_EQ(5,5);

    delete(destination);
    delete(socket);

}

TEST(basic_check, test_tcp_eq_ipv6){

    TCPSocket * socket = new TCPSocket(AF_INET6);

    //int result = socket->getNumber();

    EXPECT_EQ(5,5);

    delete(socket);
}

/*
TEST(basic_check, test_clnt_google_domain_ipv6){


    TCPSocket * socket = new TCPSocket(AF_INET6);

    SocketAddress * destination = new SocketAddress("google.com", 80);

    socket->connect(*destination);

    EXPECT_EQ(5,5);

}

TEST(basic_check, test_clnt_google_num_ipv6){


    TCPSocket * socket = new TCPSocket(AF_INET6);

    SocketAddress * destination = new SocketAddress("216.58.216.142", 80);

    socket->connect(*destination);

    EXPECT_EQ(5,5);

}
*/
TEST(basic_check, test_tcp_srvr){


    TCPListenerSocket * server = new TCPListenerSocket();
    server->bind(8000);
    server->listen(10);
    //server->accept();

    EXPECT_EQ(5,5);

    delete(server);

}

TEST(basic_check, test_udp_clnt_google_num){

    UDPSocket * client = new UDPSocket();

    delete(client);
}
