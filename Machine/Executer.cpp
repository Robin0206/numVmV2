//
// Created by Robin on 01.03.2023.
//

#include "Executer.h"

void VM::MACHINE::Executer::fillFunctions(std::vector<VM::READING::Command> &rawProgram) {
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

void VM::MACHINE::Executer::setMain(std::vector<VM::READING::Command> &rawProgram) {
    bool inMain = false;
    std::vector<VM::READING::Command> commands;
    for(auto& command : rawProgram){
        if(command.m_opCode == 0x1E){
            break;
        }
        if(inMain){
            commands.push_back(command);
        }
        if(command.m_opCode == 0x1F){
            inMain = true;
        }
    }
    Function main = Function();
    main.init(255,commands,this);
    m_main = Stackframe();
    m_main.init(main, this);
}

void VM::MACHINE::Executer::init(std::vector<VM::READING::Command> &rawProgram) {
    this->generateReferences(rawProgram);
    this->fillFunctions(rawProgram);
    this->setMain(rawProgram);
    this->m_stack.push_back(this->m_main);
}

void VM::MACHINE::Executer::run() {
    READING::Command currentCommand;
    while(!m_stack.empty()){
        currentCommand = m_stack[m_stack.size() - 1].getCurrentCommand();
        currentCommand.print();
    }
}

void VM::MACHINE::Executer::printFunctions() {
    for(auto& function : m_functions){
        function.print();
    }
}

void VM::MACHINE::Executer::generateReferences(std::vector<READING::Command>& commands) {
    for(auto& command : commands){
        command.fillReferences();
    }
}
