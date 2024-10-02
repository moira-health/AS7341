
cmake_minimum_required(VERSION 3.10)

project(Adafruit_AS7341 VERSION 1.0)

add_library(Adafruit_AS7341 STATIC
    src/Adafruit_AS7341.cpp
)

target_sources(Adafruit_AS7341 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/hal/Adafruit_I2CDevice.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/hal/Adafruit_BusIO_Register.cpp
)

target_include_directories(Adafruit_AS7341 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include 
)

# TODO: Ideally this should be private but won't compile if so.. work out what's happening here
target_include_directories(Adafruit_AS7341 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/hal  
)