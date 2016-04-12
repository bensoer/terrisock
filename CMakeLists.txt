cmake_minimum_required(VERSION 3.0)
project(terrisock)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_definitions(-std=gnu++0x)

set(SOURCE_FILES lib/Socket.cpp lib/Socket.h lib/udp/UDPSocket.cpp lib/udp/UDPSocket.h lib/tcp/TCPListenerSocket.cpp lib/tcp/TCPListenerSocket.h lib/tcp/TCPSocket.cpp lib/tcp/TCPSocket.h tests/main.cpp lib/udp/UDPPacket.cpp lib/udp/UDPPacket.h lib/SocketAddress.cpp lib/SocketAddress.h lib/inet/InetAddress.cpp lib/inet/InetAddress.h lib/inet/InetAddress4.cpp lib/inet/InetAddress4.h lib/inet/InetAddress6.cpp lib/inet/InetAddress6.h)
add_executable(terrisock ${SOURCE_FILES})

include_directories(lib lib/inet lib/tcp lib/udp)

add_subdirectory(lib)
add_subdirectory(tests)

target_link_libraries(terrisock lib)