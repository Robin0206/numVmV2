//
// Created by robin on 02.03.23.
//

#ifndef NUMVMV2_STACKFRAME_H
#define NUMVMV2_STACKFRAME_H

#include "Function.h"

namespace VM::MACHINE {
    class Stackframe {
        VM::MACHINE::Executer* m_executer;
        std::uint64_t m_programCounter;
    public:
    explicit Stackframe() = default;
        void init(Function function, Executer *executer);
        std::uint64_t getProgramCounter();
        READING::Command getCurrentCommand();

        Function m_function;
    };
}

#endif //NUMVMV2_STACKFRAME_H
