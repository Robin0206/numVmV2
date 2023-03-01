cmake_minimum_required(VERSION 3.24)
project(numVmV2)

set(CMAKE_CXX_STANDARD 17)

add_executable(numVmV2 main.cpp Reading/ReadingModule.cpp Reading/ReadingModule.h Misc/ConstMakr.h Reading/Lexer.cpp Reading/Lexer.h Misc/CommandInformation.cpp Misc/CommandInformation.h Reading/Command.cpp Reading/Command.h Machine/Machine.cpp Machine/Machine.h Machine/Command.cpp Machine/Command.h types/Reference.cpp types/Reference.h types/Reference.h)
