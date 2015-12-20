cmake_minimum_required(VERSION 3.3)
project(terrisock)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/Socket.cpp headers/Socket.h src/udp/UDPSocket.cpp headers/UDPSocket.h src/tcp/TCPListenerSocket.cpp headers/TCPListenerSocket.h src/tcp/TCPSocket.cpp headers/TCPSocket.h main.cpp)
add_executable(terrisock ${SOURCE_FILES})