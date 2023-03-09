#include <iostream>
#include"Reading/ReadingModule.h"
#include "Reading/Lexer.h"
#include "Machine/Executor.h"

int main() {
    /*std::vector<BYTE> testProgram = {

            0x1C, 0x0, 0x0, 0x0, 0x1,
            0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
            0x1, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x3,
            0x1, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x3,
            0x1, 0x0, 0x0, 0x0, 0x3, 0x0, 0x0, 0x0, 0x3,
            0x1, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x0, 0x3,
            0x1, 0x0, 0x0, 0x0, 0x5, 0x0, 0x0, 0x0, 0x0,
            0x1, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x3,
            0x1, 0x0, 0x0, 0x0, 0x7, 0x0, 0x0, 0x0, 0x3,
            0x1, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x3,
            0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x4, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1,
            0x4, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            //0x4, 0x0, 0x0, 0x0, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xE8, //SET 3 1000
            0x4, 0x0, 0x0, 0x0, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xA, //SET 3 10
            0x4, 0x0, 0x0, 0x0, 0x7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1,
            0x4, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2,
            0x4, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x1A, 0x0, 0x0, 0x0, 0x9,
            0x8, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1,
            0x7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1,
            0x7, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x2,
            0x9, 0x0, 0x0, 0x0, 0x3, 0x0, 0x0, 0x0, 0x3, 0x0, 0x0, 0x0, 0x1,
            0x9, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x0, 0x3, 0x0, 0x0, 0x0, 0x8,
            0x14, 0x0, 0x0, 0x0, 0x5, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x0, 0x6,
            0x19, 0x0, 0x0, 0x0, 0x9, 0x0, 0x0, 0x0, 0x5,
            0x15, 0x0, 0x0, 0x0, 0x2,
            0x1D, 0x0, 0x0, 0x0, 0x1,
            0x1F,
            0x17, 0x0, 0x0, 0x0, 0x1,
            0x20
    };*/
    VM::READING::ReadingModule reader = VM::READING::ReadingModule("../byteCode.nvm");
    reader.run();
    std::vector<BYTE> testProgram = reader.getRawProgram();
    VM::READING::Lexer lexer = VM::READING::Lexer(testProgram);
    std::cout << "Code:" << "\n";
    lexer.printCommands();
    VM::MACHINE::Executor executor = VM::MACHINE::Executor();
    executor.init(lexer.getCommands());
    std::cout << "\nResult: \n";
    executor.run();
}
