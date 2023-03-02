//
// Created by robin on 01.03.23.
//

#include <complex>
#include "Command.h"

void VM::READING::Command::fillArgs() {
    std::vector<BYTE> currentArg;
    int counter = 1;
    for(BYTE i : m_commandInformation.m_argLengths[m_opCode]){
        currentArg = std::vector<BYTE>();
        for(int j = 0; j < i; j++){
            currentArg.push_back(m_rawCommand[counter]);
            if(counter == m_rawCommand.size()){
                break;
            }
            counter++;
        }
        m_args.push_back(currentArg);
    }
}

void VM::READING::Command::setOpCode() {
    m_opCode = m_rawCommand[0];
}

void VM::READING::Command::print() {
    std::cout << "" << m_commandInformation.m_names[m_opCode] << " ";
    for(auto& arg : m_args){
        std::cout << "";
        BYTE intArr[4];
        BYTE longArr[8];
        int intArg = 0;
        long longArg = 0;
        switch(arg.size()){
            case 1:
                std::cout << arg[0];
                break;
            case 4:
                for(int i = 0; i < arg.size(); i++){
                    intArr[i] = arg[arg.size()-1 - i];
                }
                std::memcpy(&intArg, intArr, 4);
                std::cout << intArg;
                break;
            case 8:
                for(int i = 0; i < arg.size(); i++){
                    longArr[i] = arg[arg.size()-1 - i];
                }
                std::memcpy(&longArg, longArr, 8);
                std::cout << longArg;
        }


        std::cout << " ";
    }
    std::cout << "\n";
}

VM::READING::Command::Command(const std::vector<BYTE> &input) {
    m_commandInformation = MISC::CommandInformation();
    this->m_rawCommand = input;
    this->setOpCode();
    this->fillArgs();
}

VM::READING::Command::Command(const VM::READING::Command &input) {
    this->m_rawCommand = input.m_rawCommand;
    this->m_opCode = input.m_opCode;
    this->m_commandInformation = input.m_commandInformation;
    this->m_args = input.m_args;
    this->m_argReferences = input.m_argReferences;
}


