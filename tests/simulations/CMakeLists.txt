set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_definitions(-std=gnu++0x)

#add_library(libterrisock SHARED IMPORTED)
#set_target_properties(libterrisock PROPERTIES IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/Debug/ )

add_executable(sim_tcp_clnt tcp_client.cpp)
add_executable(sim_tcp_srvr tcp_server.cpp)

target_link_libraries(sim_tcp_clnt terrisock)
target_link_libraries(sim_tcp_srvr terrisock)