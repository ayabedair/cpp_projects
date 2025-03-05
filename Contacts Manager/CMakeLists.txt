cmake_minimum_required(VERSION 3.30)
project(don_t_touch)

set(CMAKE_CXX_STANDARD 20)

add_executable(don_t_touch main.cpp
        Contacts.cpp
        Contacts.h
        FileIO.cpp
        FileIO.h
        App.cpp
        App.h)
