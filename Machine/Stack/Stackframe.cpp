//
// Created by robin on 02.03.23.
//

#include "Stackframe.h"

void VM::MACHINE::Stackframe::init(VM::MACHINE::Function function, VM::MACHINE::Executor *executor) {
    this->m_executor = executor;
    this->m_function = function;
    this->m_programCounter = 0;
}

VM::READING::Command VM::MACHINE::Stackframe::getCurrentCommand() {
    m_programCounter++;
    return m_function.m_commands[m_programCounter - 1];
}

std::uint64_t VM::MACHINE::Stackframe::getProgramCounter() {
    return m_programCounter;
}
