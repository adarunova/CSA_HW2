cmake_minimum_required(VERSION 3.16)
project(CSA_HW2)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        # Headers
        Headers/random.h
        Headers/triangle.h
        Headers/rectangle.h
        Headers/shape.h
        Headers/container.h
        Headers/circle.h

        # Sources
        Sources/triangle.cpp
        Sources/rectangle.cpp
        Sources/shape.cpp
        Sources/container.cpp
        Sources/main.cpp
        Sources/circle.cpp
        )

add_executable(CSA_HW1 Sources/main.cpp Headers/container.h Headers/random.h Headers/triangle.h Headers/rectangle.h Headers/shape.h Headers/circle.h Sources/container.cpp Sources/triangle.cpp Sources/rectangle.cpp Sources/circle.cpp Sources/shape.cpp)
