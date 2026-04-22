cmake_minimum_required(VERSION 4.1)
project(VehicleSimulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(VehicleSimulator
        main.cpp
        Vehicle.h
        Vehicle.cpp
        Exceptions.h
        SportCar.h
        SportCar.cpp
        Motorcycle.h
        Motorcycle.cpp
        Truck.h
        Truck.cpp)