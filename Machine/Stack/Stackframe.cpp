//
// Created by robin on 02.03.23.
//

#include "Stackframe.h"

#include <utility>

void VM::MACHINE::Stackframe::init(VM::MACHINE::Function function, VM::MACHINE::Executor *executor) {
    this->m_executor = executor;
    this->m_function = std::move(function);
    this->m_programCounter = 0;
    this->fillLabels();

}

VM::READING::Command& VM::MACHINE::Stackframe::getCurrentCommand() {
    m_programCounter++;
    return m_function.m_commands[m_programCounter - 1];
}

std::uint64_t VM::MACHINE::Stackframe::getProgramCounter() {
    return m_programCounter;
}

void VM::MACHINE::Stackframe::fillLabels() {
    std::pair<std::uint32_t, std::uint32_t> currentLabel;
    for(std::size_t i = 0; i < m_function.m_commands.size(); i++){
        if(m_function.m_commands[i].m_opCode == 26){
            currentLabel.first = *(reinterpret_cast<std::uint32_t*>(m_function.m_commands[i].m_argReferences[0].m_content.get()));
            currentLabel.second = i;
            m_labels.push_back(currentLabel);
        }
    }
}
