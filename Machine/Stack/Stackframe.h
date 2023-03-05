//
// Created by robin on 02.03.23.
//

#ifndef NUMVMV2_STACKFRAME_H
#define NUMVMV2_STACKFRAME_H

#include "Function.h"

namespace VM::MACHINE {
    class Stackframe {
    public:
        VM::MACHINE::Executor* m_executor;
        std::uint64_t m_programCounter;
        explicit Stackframe() = default;
        void init(Function function, Executor *executor);
        std::uint64_t getProgramCounter();
        READING::Command getCurrentCommand();
        std::vector<TYPES::Reference> m_references;
        std::vector<std::pair<std::uint32_t, std::uint32_t>> m_labels;
        Function m_function;
        std::vector<TYPES::Reference> m_arguments;
    };
}

#endif //NUMVMV2_STACKFRAME_H
