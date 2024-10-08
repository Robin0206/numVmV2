//
// Created by Robin on 01.03.2023.
//

#ifndef NUMVMV2_EXECUTOR_H
#define NUMVMV2_EXECUTOR_H

#include <vector>
#include "Stack/Stackframe.h"
#include "Stack/Function.h"
#include "../types/Reference.h"
#include "../Reading/Command.h"



namespace VM::MACHINE{
    namespace DELEGATES{
        class Delegate;
    }
    class Executor {
    public:
    std::array<VM::MACHINE::DELEGATES::Delegate*, 34> m_delegates{};
        std::vector<VM::MACHINE::Stackframe> m_stack;
        std::vector<VM::MACHINE::Function> m_functions;
        VM::MACHINE::Stackframe m_main;
        std::vector<VM::TYPES::Reference> m_argRegisters{};
        VM::TYPES::Reference m_returnRegister;
        void fillFunctions(std::vector<VM::READING::Command>& rawProgram);
        void setMain(std::vector<VM::READING::Command>& rawProgram);

        Executor() = default;
        void init(std::vector<VM::READING::Command>& rawProgram);
        void run();
        void printFunctions();
        void generateReferences(std::vector<READING::Command>& rawProgram);
        void fillDelegates();
    };
}



#endif //NUMVMV2_EXECUTOR_H
