cmake_minimum_required(VERSION 3.23)
project(GreedySnake)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(GreedySnake
        src/main.cpp src/utils/Tools.cpp src/utils/Tools.h

        src/startinterface/StartInterface.cpp src/startinterface/StartInterface.h

        src/controller/Controller.cpp src/controller/Controller.h

        src/component/Food.cpp src/component/Food.h
        src/component/Map.cpp src/component/Map.h
        src/component/Point.cpp src/component/Point.h
        src/component/Snake.cpp src/component/Snake.h)

include_directories(src/component)
include_directories(src/controller)
include_directories(src/startinterface)
include_directories(src/utils)