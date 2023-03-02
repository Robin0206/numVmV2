//
// Created by robin on 02.03.23.
//

#ifndef NUMVMV2_DELEGATE_H
#define NUMVMV2_DELEGATE_H

#include "../Executer.h"

namespace VM::MACHINE {
    class Delegate {
        VM::MACHINE::Executer* executer;
        virtual void run(Stackframe stackframe) = 0;
        virtual void run(Stackframe stackframe, TYPES::Reference a) = 0;
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b) = 0;
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c) = 0;
    };
} // MACHINE

#endif //NUMVMV2_DELEGATE_H
