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
        Function m_function;
    public:
    explicit Stackframe() = default;
        void init(Function function, Executer *executer);
        READING::Command getCurrentCommand();
    };
}

#endif //NUMVMV2_STACKFRAME_H
