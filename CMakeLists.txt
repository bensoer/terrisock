cmake_minimum_required(VERSION 3.3)
project(terrisock)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(headers)

set(SOURCE_FILES src/Socket.cpp headers/Socket.h src/udp/UDPSocket.cpp headers/UDPSocket.h src/tcp/TCPListenerSocket.cpp headers/TCPListenerSocket.h src/tcp/TCPSocket.cpp headers/TCPSocket.h tests/main.cpp src/udp/UDPPacket.cpp headers/UDPPacket.h src/SocketAddress.cpp headers/SocketAddress.h src/inet/InetAddress.cpp headers/InetAddress.h src/inet/InetAddress4.cpp headers/InetAddress4.h src/inet/InetAddress6.cpp headers/InetAddress6.h )
add_executable(terrisock ${SOURCE_FILES})