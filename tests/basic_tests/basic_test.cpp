//
// Created by bensoer on 12/04/16.
//

#include "gtest/gtest.h"
#include "TCPSocket.h"

using namespace terrisock;

TEST(basic_check, test_eq){

    TCPSocket * socket = new TCPSocket();

    int result = socket->getNumber();

    EXPECT_EQ(5,result);
}

TEST(basic_check, create_basic_client){

    TCPSocket * socket = new TCPSocket();

}