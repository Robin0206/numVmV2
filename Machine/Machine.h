//
// Created by Robin on 01.03.2023.
//

#ifndef NUMVMV2_MACHINE_H
#define NUMVMV2_MACHINE_H

#include <vector>
#include "Command.h"

namespace VM::MACHINE{
    class Machine {
        std::vector<VM::MACHINE::Command> commands;
    };
}



#endif //NUMVMV2_MACHINE_H
