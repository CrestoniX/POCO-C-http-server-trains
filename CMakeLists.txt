cmake_minimum_required(VERSION 3.5)

project(SWE_server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Poco REQUIRED Foundation Net Util XML)
enable_language(C)

add_executable(SWE_server main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/HTTP_Server.cpp ${CMAKE_CURRENT_SOURCE_DIR}/include/HTTP_Server.h)

target_link_libraries(SWE_server Poco::Net Poco::Foundation Poco::Util Poco::XML)

target_include_directories(SWE_server PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(SWE_server PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


install(TARGETS SWE_server DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
