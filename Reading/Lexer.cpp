//
// Created by robin on 01.03.23.
//

#include "Lexer.h"



VM::READING::Lexer::Lexer(const std::vector<unsigned char> &rawProgram) {
    this->m_rawProgram = rawProgram;
    this->m_commandInformation = MISC::CommandInformation();
    this->fillRawCommands();
    this->fillCommands();
}

void VM::READING::Lexer::fillRawCommands() {
    std::uint8_t currentLength;
    std::uint8_t counter;
    std::vector<BYTE> currentCommand;
    std::vector<BYTE> currentToken;
    for(std::size_t i = 0; i < m_rawProgram.size(); i++){
        //reinitialize
        currentCommand = std::vector<BYTE>();
        currentLength = 0;
        counter = 0;
        //calculate current length
        for(auto& tokenLength : m_commandInformation.m_argLengths[m_rawProgram[i]]){
            currentLength+=tokenLength;
        }
        currentLength++;
        //add bytes to rawProgram
        while(i < m_rawProgram.size() && counter < currentLength){
            currentCommand.push_back(m_rawProgram[i]);
            counter++;
            i++;
        }
        //add currentCommand to rawCommands
        m_rawCommands.push_back(currentCommand);
        i--;
    }
}

void VM::READING::Lexer::printRawCommands() {
    for(auto& rawCommand : m_rawCommands){
        std::cout << "\n";
        for(auto& byte : rawCommand){
            std::cout << "0x" << std::hex << (int)byte << " ";
        }
    }
}

void VM::READING::Lexer::printCommands() {
    for(auto& command : m_commands){
        command.print();
    }
}

void VM::READING::Lexer::fillCommands() {
    for(auto& command : m_rawCommands){
        m_commands.push_back(Command(command));
    }
}

std::vector<VM::READING::Command> &VM::READING::Lexer::getCommands() {
    return m_commands;
}




