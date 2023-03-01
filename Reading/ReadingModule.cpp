//
// Created by robin on 01.03.23.
//

#include "ReadingModule.h"

void VM::READING::ReadingModule::run() {
    std::ifstream input(m_path, std::ios::in | std::ios::binary);
    char x;
    char* x_ptr = &x;
    while(input.read(x_ptr, 1)){
        m_rawProgram.push_back(x);
    }
}

VM::READING::ReadingModule::ReadingModule(const std::string& path): m_path(path){}

std::vector<BYTE> &VM::READING::ReadingModule::getRawProgram() {
    return m_rawProgram;
}

