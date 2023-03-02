cmake_minimum_required(VERSION 3.24)
project(numVmV2)

set(CMAKE_CXX_STANDARD 17)

add_executable(numVmV2 main.cpp Reading/ReadingModule.cpp Reading/ReadingModule.h Misc/ConstMakr.h Reading/Lexer.cpp Reading/Lexer.h Misc/CommandInformation.cpp Misc/CommandInformation.h Reading/Command.cpp Reading/Command.h Machine/Executer.cpp Machine/Executer.h types/Reference.cpp types/Reference.h types/Reference.h Machine/Stack/Stackframe.cpp Machine/Stack/Stackframe.h Machine/Stack/Function.cpp Machine/Stack/Function.h Machine/DelegateTable/Delegate.cpp Machine/DelegateTable/Delegate.h Machine/DelegateTable/Memory.cpp Machine/DelegateTable/Memory.h Machine/DelegateTable/Arithmetic.cpp Machine/DelegateTable/Arithmetic.h Machine/DelegateTable/Binary.cpp Machine/DelegateTable/Binary.h Machine/DelegateTable/Comparison.cpp Machine/DelegateTable/Comparison.h Machine/DelegateTable/FunctionOperations.cpp Machine/DelegateTable/FunctionOperations.h Machine/DelegateTable/System.cpp Machine/DelegateTable/System.h)
