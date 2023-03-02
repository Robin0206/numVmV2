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

void VM::READING::Command::fillReferences() {

    TYPES::Reference currentReference;
    std::uint32_t intValue = 0;
    std::uint64_t longValue = 0;
    for(auto& byteVector : m_args){

        switch(byteVector.size()){
            case 1:
                currentReference = TYPES::Reference(byteVector[0], 0x1, 0x0);
                break;
            case 4:
                BYTE intArr[4];
                intArr[0] = byteVector[3];
                intArr[1] = byteVector[2];
                intArr[2] = byteVector[1];
                intArr[3] = byteVector[0];
                std::memcpy(&intValue, &intArr, 4);
                currentReference = TYPES::Reference(intValue, 0x1, 0x0);
                break;
            case 8:
                BYTE longArr[8];
                longArr[0] = byteVector[7];
                longArr[1] = byteVector[6];
                longArr[2] = byteVector[5];
                longArr[3] = byteVector[4];
                longArr[4] = byteVector[3];
                longArr[5] = byteVector[2];
                longArr[6] = byteVector[1];
                longArr[7] = byteVector[0];
                std::memcpy(&longValue, &longArr, 8);
                currentReference = TYPES::Reference(longValue, 0x1, 0x0);
                break;
            default:
                std::cout << "ERROR" << "\n";
                break;
        }
        m_argReferences.push_back(currentReference);
    }

}


