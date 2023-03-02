//
// Created by robin on 02.03.23.
//

#include "Function.h"

namespace VM::MACHINE {
    void Function::print() {
        std::cout << "Function " << std::hex << (int)m_id << "\n";
        for(auto& command : m_commands){
            std::cout << "\t";
            command.print();
        }
        std::cout << "\n";
    }

    void Function::init(std::uint32_t id, std::vector<READING::Command> commands, Machine* machine) {
        this->m_id = id;
        this->m_commands = commands;
        this->m_machine = machine;
    }
} // MACHINE