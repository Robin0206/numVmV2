//
// Created by robin on 02.03.23.
//

#ifndef NUMVMV2_FUNCTION_H
#define NUMVMV2_FUNCTION_H

#include <vector>
#include "../Reading/Command.h"



namespace VM::MACHINE {
    class Machine;
    class Function {
        std::uint32_t m_id;
        std::vector<VM::READING::Command> m_commands;
        Machine* m_machine;
    public:
        explicit Function() = default;
        void print();
        void init(std::uint32_t id, std::vector<READING::Command> commands, Machine* machine);
    };
} // MACHINE

#endif //NUMVMV2_FUNCTION_H
