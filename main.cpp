#include <iostream>
#include"Reading/ReadingModule.h"
#include "Reading/Lexer.h"

int main() {
    std::vector<BYTE> testProgram = {
            0x1,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x0, 0x3,
            0x1,  0x0, 0x0, 0x0, 0x1,  0x0, 0x0, 0x0, 0x3,
            0x1,  0x0, 0x0, 0x0, 0x2,  0x0, 0x0, 0x0, 0x3,
            0x4,  0x1, 0x0, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x0, 0x1,
            0x4,  0x0, 0x0, 0x0, 0x1,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x0, 0x1,
            0x8,  0x0, 0x0, 0x0, 0x2,  0x0, 0x0, 0x0, 0x1,  0x0, 0x0, 0x0, 0x0,
            0x15, 0x0, 0x0, 0x0, 0x2};
    VM::READING::Lexer lexer = VM::READING::Lexer(testProgram);
    lexer.print();
}
