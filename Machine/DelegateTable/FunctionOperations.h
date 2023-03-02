//
// Created by Robin on 02.03.2023.
//

#ifndef NUMVMV2_FUNCTIONOPERATIONS_H
#define NUMVMV2_FUNCTIONOPERATIONS_H

#include "Delegate.h"

namespace VM::MACHINE {
    class RET: public Delegate{
        virtual void run(Stackframe stackframe);
        virtual void run(Stackframe stackframe, TYPES::Reference a);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class CALL: public Delegate{
        virtual void run(Stackframe stackframe);
        virtual void run(Stackframe stackframe, TYPES::Reference a);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class PARG: public Delegate{
        virtual void run(Stackframe stackframe);
        virtual void run(Stackframe stackframe, TYPES::Reference a);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class ARG: public Delegate{
        virtual void run(Stackframe stackframe);
        virtual void run(Stackframe stackframe, TYPES::Reference a);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class FST: public Delegate{
        virtual void run(Stackframe stackframe);
        virtual void run(Stackframe stackframe, TYPES::Reference a);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class FEN: public Delegate{
        virtual void run(Stackframe stackframe);
        virtual void run(Stackframe stackframe, TYPES::Reference a);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
} // MACHINE

#endif //NUMVMV2_FUNCTIONOPERATIONS_H
