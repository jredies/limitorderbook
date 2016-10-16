cmake_minimum_required(VERSION 2.8)
project(pricer)

set (CMAKE_CXX_STANDARD 11)
FIND_PACKAGE( Boost REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
 
include_directories(include)
 
file(GLOB SOURCES "src/*.cpp")
 
add_executable(pricer ${SOURCES})

TARGET_LINK_LIBRARIES( pricer ${Boost_LIBRARIES} )
