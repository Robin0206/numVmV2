//
// Created by Robin on 01.03.2023.
//

#ifndef NUMVMV2_MACHINE_H
#define NUMVMV2_MACHINE_H

#include <vector>
#include "Stackframe.h"
#include "Function.h"
#include "../types/Reference.h"
#include "../Reading/Command.h"

namespace VM::MACHINE{
    class Machine {
        std::vector<VM::MACHINE::Stackframe> m_stack;
        std::vector<VM::MACHINE::Function> m_functions;
        VM::MACHINE::Stackframe m_main;
        std::vector<VM::TYPES::Reference> m_argRegisters;
        VM::TYPES::Reference m_returnRegister;
        void fillFunctions(const std::vector<VM::READING::Command>& rawProgram);
        void setMain(const std::vector<VM::READING::Command>& rawProgram);
    public:
        Machine() = default;
        void init(const std::vector<VM::READING::Command>& rawProgram);
        void run();
        void printFunctions();
    };
}



#endif //NUMVMV2_MACHINE_H
