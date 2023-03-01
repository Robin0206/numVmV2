//
// Created by robin on 01.03.23.
//

#ifndef NUMVMV2_COMMAND_H
#define NUMVMV2_COMMAND_H

#include <vector>
#include <iostream>
#include "../Misc/ConstMakr.h"
#include "../Misc/CommandInformation.h"
#include <cstring>

namespace VM::READING{
    class Command {
        MISC::CommandInformation m_commandInformation;
        BYTE m_opCode;
        std::vector<std::vector<BYTE>> m_args;
        std::vector<BYTE> m_rawCommand;
        void setOpCode();
        void fillArgs();
    public:
        explicit Command(const std::vector<BYTE>& input){
            m_commandInformation = MISC::CommandInformation();
            this->m_rawCommand = input;
            this->setOpCode();
            this->fillArgs();
        }
        void print();
    };
}



#endif //NUMVMV2_COMMAND_H
