//
// Created by robin on 01.03.23.
//

#ifndef NUMVMV2_LEXER_H
#define NUMVMV2_LEXER_H

#include <vector>
#include <iostream>
#include "../Misc/ConstMakr.h"
#include "../Misc/CommandInformation.h"
#include "Command.h"
#include <iomanip>


namespace VM::READING{
    class Lexer {
        VM::MISC::CommandInformation m_commandInformation;
        std::vector<BYTE> m_rawProgram;
        std::vector<std::vector<BYTE>> m_rawCommands;
        std::vector<Command> m_commands;


        void fillRawCommands();

        void fillCommands();
    public:
        explicit Lexer(const std::vector<BYTE>& rawProgram);
        std::vector<Command>& getCommands();
        void printCommands();
        void printRawCommands();
    };
}



#endif //NUMVMV2_LEXER_H
