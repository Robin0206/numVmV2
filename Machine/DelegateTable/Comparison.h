//
// Created by Robin on 02.03.2023.
//

#ifndef NUMVMV2_COMPARISON_H
#define NUMVMV2_COMPARISON_H

#include "Delegate.h"

namespace VM::MACHINE {
    class LSS: public MACHINE::Delegate{
        virtual void run(MACHINE::Stackframe stackframe);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class GRT: public MACHINE::Delegate{
        virtual void run(MACHINE::Stackframe stackframe);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class LSE: public MACHINE::Delegate{
        virtual void run(MACHINE::Stackframe stackframe);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class GRE: public MACHINE::Delegate{
        virtual void run(MACHINE::Stackframe stackframe);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(MACHINE::Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
} // MACHINE

#endif //NUMVMV2_COMPARISON_H
