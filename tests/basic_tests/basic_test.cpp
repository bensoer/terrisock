//
// Created by bensoer on 12/04/16.
//

#include "gtest/gtest.h"
#include "TCPSocket.h"



TEST(basic_check, test_eq){

    terrisock::TCPSocket * socket = new terrisock::TCPSocket();

    int result = socket->getNumber();

    EXPECT_EQ(5,result);
}
