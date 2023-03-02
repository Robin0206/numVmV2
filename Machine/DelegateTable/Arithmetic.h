//
// Created by Robin on 02.03.2023.
//

#ifndef NUMVMV2_ARITHMETIC_H
#define NUMVMV2_ARITHMETIC_H
#include "Delegate.h"

namespace VM::Machine {
    class ADD: public MACHINE::Delegate{
        virtual void run(MACHINE::Stackframe stackframe);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class SUB: public MACHINE::Delegate{
        virtual void run(MACHINE::Stackframe stackframe);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class MUL: public MACHINE::Delegate{
        virtual void run(MACHINE::Stackframe stackframe);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class DIV: public MACHINE::Delegate{
        virtual void run(MACHINE::Stackframe stackframe);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
} // Machine

#endif //NUMVMV2_ARITHMETIC_H
