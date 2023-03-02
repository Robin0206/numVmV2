//
// Created by Robin on 02.03.2023.
//

#ifndef NUMVMV2_BINARY_H
#define NUMVMV2_BINARY_H

#include "Delegate.h"

namespace VM::MACHINE {
    class OR: public MACHINE::Delegate{
        virtual void run(MACHINE::Stackframe stackframe);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class AND: public MACHINE::Delegate{
        virtual void run(MACHINE::Stackframe stackframe);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class XOR: public MACHINE::Delegate{
        virtual void run(MACHINE::Stackframe stackframe);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class NOT: public MACHINE::Delegate{
        virtual void run(MACHINE::Stackframe stackframe);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class EQ: public MACHINE::Delegate{
        virtual void run(MACHINE::Stackframe stackframe);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
} // MACHINE

#endif //NUMVMV2_BINARY_H
