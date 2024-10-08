//
// Created by robin on 01.03.23.
//

#ifndef NUMVMV2_COMMANDINFORMATION_H
#define NUMVMV2_COMMANDINFORMATION_H

#include <vector>
#include <string>
#include <array>

namespace VM::MISC {
    struct CommandInformation {
        std::array<std::string, 34> m_names;
        std::array<std::vector<std::uint8_t>, 34> m_argLengths;
        CommandInformation();
    };
} // MISC

#endif //NUMVMV2_COMMANDINFORMATION_H
