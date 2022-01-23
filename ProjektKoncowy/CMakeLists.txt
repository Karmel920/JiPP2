cmake_minimum_required(VERSION 3.16)

project(ProjektKoncowy)

include_directories(include)

add_executable(ProjektKoncowy src/main.cpp src/Wallet.cpp src/Account.cpp src/Card.cpp)