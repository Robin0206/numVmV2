//
// Created by Robin on 01.03.2023.
//

#include "Executor.h"
#include "./DelegateTable/Delegate.h"
void VM::MACHINE::Executor::fillFunctions(std::vector<VM::READING::Command> &rawProgram) {
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
            currentFunction.clear();
        } else{
            currentFunction.push_back(command);
        }
    }
}

void VM::MACHINE::Executor::setMain(std::vector<VM::READING::Command> &rawProgram) {
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

void VM::MACHINE::Executor::init(std::vector<VM::READING::Command> &rawProgram) {
    this->generateReferences(rawProgram);
    this->fillDelegates();
    this->fillFunctions(rawProgram);
    this->setMain(rawProgram);
    this->m_stack.push_back(this->m_main);
}

void VM::MACHINE::Executor::run() {
    READING::Command currentCommand;
    while(!m_stack.empty()){
        currentCommand = m_stack[m_stack.size() - 1].getCurrentCommand();
        switch(currentCommand.m_argReferences.size()){
            case 0:
                m_delegates[currentCommand.m_opCode]->run(
                        m_stack[m_stack.size() - 1]
                );
                break;
            case 1:
                m_delegates[currentCommand.m_opCode]->run(
                        m_stack[m_stack.size() - 1],
                        currentCommand.m_argReferences[0]
                );
                break;
            case 2:
                m_delegates[currentCommand.m_opCode]->run(
                        m_stack[m_stack.size() - 1],
                        currentCommand.m_argReferences[0],
                        currentCommand.m_argReferences[1]
                );
                break;
            case 3:
                m_delegates[currentCommand.m_opCode]->run(
                        m_stack[m_stack.size() - 1],
                        currentCommand.m_argReferences[0],
                        currentCommand.m_argReferences[1],
                        currentCommand.m_argReferences[2]
                );
                break;
        }
        if(m_stack[m_stack.size() - 1].getProgramCounter() == m_stack[m_stack.size() - 1].m_function.m_commands.size()){
            m_stack.pop_back();
            m_argRegisters.clear();
        }

    }
}

void VM::MACHINE::Executor::printFunctions() {
    for(auto& function : m_functions){
        function.print();
    }
}

void VM::MACHINE::Executor::generateReferences(std::vector<READING::Command>& commands) {
    for(auto& command : commands){
        command.fillReferences();
    }
}

void VM::MACHINE::Executor::fillDelegates() {
//memory
    m_delegates[0] = new VM::MACHINE::DELEGATES::NOOP();
    m_delegates[1] = new VM::MACHINE::DELEGATES::REFA();
    m_delegates[2] = new VM::MACHINE::DELEGATES::REFA();
    m_delegates[3] = new VM::MACHINE::DELEGATES::MOV();
    m_delegates[4] = new VM::MACHINE::DELEGATES::SET();
    m_delegates[5] = new VM::MACHINE::DELEGATES::ASET();
    m_delegates[6] = new VM::MACHINE::DELEGATES::AGET();
    m_delegates[7] = new VM::MACHINE::DELEGATES::CPY();
    //arithmetic
    m_delegates[8] = new VM::MACHINE::DELEGATES::ADD();
    m_delegates[9] = new VM::MACHINE::DELEGATES::SUB();
    m_delegates[10] = new VM::MACHINE::DELEGATES::MUL();
    m_delegates[11] = new VM::MACHINE::DELEGATES::DIV();
    //binary
    m_delegates[12] = new VM::MACHINE::DELEGATES::OR();
    m_delegates[13] = new VM::MACHINE::DELEGATES::AND();
    m_delegates[14] = new VM::MACHINE::DELEGATES::XOR();
    m_delegates[15] = new VM::MACHINE::DELEGATES::NOT();
    m_delegates[16] = new VM::MACHINE::DELEGATES::EQ();
    //logical
    m_delegates[17] = new VM::MACHINE::DELEGATES::LSS();
    m_delegates[18] = new VM::MACHINE::DELEGATES::GRT();
    m_delegates[19] = new VM::MACHINE::DELEGATES::LSE();
    m_delegates[20] = new VM::MACHINE::DELEGATES::GRE();
    //system/functions
    m_delegates[21] = new VM::MACHINE::DELEGATES::PRINT();//-
    m_delegates[22] = new VM::MACHINE::DELEGATES::RET();//-
    m_delegates[23] = new VM::MACHINE::DELEGATES::CALL();//-
    m_delegates[24] = new VM::MACHINE::DELEGATES::PARG();//-
    m_delegates[25] = new VM::MACHINE::DELEGATES::BRANCH();//-
    m_delegates[26] = new VM::MACHINE::DELEGATES::LABEL();//-
    m_delegates[27] = new VM::MACHINE::DELEGATES::REFF();//-
    m_delegates[28] = new VM::MACHINE::DELEGATES::FST();//-
    m_delegates[29] = new VM::MACHINE::DELEGATES::FEN();//-
    m_delegates[30] = new VM::MACHINE::DELEGATES::ARG();//-
    m_delegates[31] = new VM::MACHINE::DELEGATES::MAIN();//-
    m_delegates[32] = new VM::MACHINE::DELEGATES::MEND();//-
}
