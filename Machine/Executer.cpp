//
// Created by Robin on 01.03.2023.
//

#include "Executer.h"

void VM::MACHINE::Executer::fillFunctions(const std::vector<VM::READING::Command> &rawProgram) {
    std::vector<VM::READING::Command> currentFunction;
    std::uint32_t  currentFunctionId;
    BYTE funcIdBytes[4];
    for(auto& command : rawProgram){
        if(command.m_opCode == 0x1C){//if it is the start of a function
            //convert byte vector to uint32_t not confusing endianess
            funcIdBytes[0] = command.m_args[0][3];
            funcIdBytes[1] = command.m_args[0][2];
            funcIdBytes[2] = command.m_args[0][1];
            funcIdBytes[3] = command.m_args[0][0];
            std::memcpy(&currentFunctionId, funcIdBytes, 4);
        }else if(command.m_opCode == 0x1D){//if it is the end of a function
            m_functions.push_back(VM::MACHINE::Function());
            m_functions[m_functions.size() - 1].init(currentFunctionId, currentFunction, this);
            currentFunction = std::vector<VM::READING::Command>();
        } else{
            currentFunction.push_back(command);
        }
    }
}

void VM::MACHINE::Executer::setMain(const std::vector<VM::READING::Command> &rawProgram) {

}

void VM::MACHINE::Executer::init(const std::vector<VM::READING::Command> &rawProgram) {
    this->fillFunctions(rawProgram);
    this->setMain(rawProgram);
}

void VM::MACHINE::Executer::run() {

}

void VM::MACHINE::Executer::printFunctions() {
    for(auto& function : m_functions){
        function.print();
    }
}
