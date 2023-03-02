//
// Created by robin on 01.03.23.
//

#ifndef NUMVMV2_COMMAND_H
#define NUMVMV2_COMMAND_H

#include <vector>
#include <iostream>
#include "../Misc/ConstMakr.h"
#include "../Misc/CommandInformation.h"
#include "../types/Reference.h"
#include <cstring>

namespace VM::READING{
    class Command {
        MISC::CommandInformation m_commandInformation;
        BYTE m_opCode;
        std::vector<BYTE> m_rawCommand;
        void setOpCode();
        void fillArgs();

    public:
        std::vector<VM::TYPES::Reference> m_argReferences;
        std::vector<std::vector<BYTE>> m_args;
        explicit Command(const std::vector<BYTE>& input);
        void print();
    };
}



#endif //NUMVMV2_COMMAND_H
