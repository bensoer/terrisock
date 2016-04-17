include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicTests
        basic_test.cpp)

target_link_libraries(runBasicTests gtest gtest_main)
target_link_libraries(runBasicTests terrisock)