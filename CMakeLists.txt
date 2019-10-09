cmake_minimum_required(VERSION 3.15)
project(delayed_queue)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS -pthread)

add_executable(delayed_queue main.cpp
        Message.cpp
        Message.h
        Timer.cpp
        Timer.h
        DelayedQueue.cpp
        DelayedQueue.h
        Dispatcher.cpp
        Dispatcher.h)