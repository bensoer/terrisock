//
// Created by bensoer on 27/04/16.
//

#include <tcp/TCPListenerSocket.h>
#include <udp/UDPSocket.h>
#include <SocketOptions.h>
#include "gtest/gtest.h"
#include "TCPSocket.h"

using namespace terrisock;

TEST(options_check, test_reuse_addr){

    TCPSocket * socket = new TCPSocket();
    bool state1 = SocketOptions::getReuseAddressState(socket);

    EXPECT_FALSE(state1);

    SocketOptions::setAddressReusable(socket);
    bool state = SocketOptions::getReuseAddressState(socket);

    EXPECT_TRUE(state);

    delete(socket);
}

TEST(options_check, test_send_lowat){

    TCPSocket * socket = new TCPSocket();
    int init = SocketOptions::getSendLowWaterMark(socket);

    EXPECT_GT(init, 0);

    bool setStatus = SocketOptions::setSendLowWaterMark(socket, 10);
    int after = SocketOptions::getSendLowWaterMark(socket);

    if(setStatus == true){
        EXPECT_EQ(10, after);
    }else{
        EXPECT_EQ(init, after);
    }

    delete(socket);

}

TEST(options_check, test_recv_lowat){

    TCPSocket * socket = new TCPSocket();
    int init = SocketOptions::getReceiveLowWaterMark(socket);

    EXPECT_GT(init, 0);

    bool setStatus = SocketOptions::setReceiveLowWaterMark(socket, 10);
    int after = SocketOptions::getReceiveLowWaterMark(socket);

    if(setStatus == true){
        EXPECT_EQ(10, after);
    }else{
        EXPECT_EQ(init, after);
    }

    delete(socket);

}

TEST(options_check, test_snd_buf){

    TCPSocket * socket = new TCPSocket();
    int init = SocketOptions::getSendBufferSize(socket);

    EXPECT_GT(init, 0);

    int setSize = init + 2000;

    bool setStatus = SocketOptions::setSendBufferSize(socket, setSize);
    EXPECT_TRUE(setStatus);

    int after = SocketOptions::getSendBufferSize(socket);

    //kernel will double the amount that is set
    EXPECT_EQ((setSize * 2), after);

    delete(socket);

}

TEST(options_check, test_recv_buf){

    TCPSocket * socket = new TCPSocket();
    int init = SocketOptions::getReceiveBufferSize(socket);

    EXPECT_GT(init, 0);

    int setSize = init + 2000;

    bool setStatus = SocketOptions::setReceiveBufferSize(socket, setSize);
    EXPECT_TRUE(setStatus);

    int after = SocketOptions::getReceiveBufferSize(socket);

    //kernel will double the amount that is set
    EXPECT_EQ((setSize * 2), after);

    delete(socket);

}

TEST(options_check, test_oob_data){

    TCPSocket * socket = new TCPSocket();
    bool init = SocketOptions::getOutOfBandDataInlineState(socket);

    EXPECT_FALSE(init);

    SocketOptions::setOutOfBandDataInline(socket);

    bool after = SocketOptions::getOutOfBandDataInlineState(socket);
    EXPECT_TRUE(after);

    delete(socket);
}