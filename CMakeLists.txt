cmake_minimum_required(VERSION 3.6)
project(ExtractEmailAttributes)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ExtractFromFiles.cpp ExtractFromFiles.h GlobalSetting.h GlobalHeader.h GlobalSetting.cpp AttributesHolder.cpp AttributesHolder.h)
add_executable(ExtractEmailAttributes ${SOURCE_FILES})