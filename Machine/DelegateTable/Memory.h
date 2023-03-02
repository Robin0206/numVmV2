//
// Created by Robin on 02.03.2023.
//

#ifndef NUMVMV2_MEMORY_H
#define NUMVMV2_MEMORY_H

#include "Delegate.h"

namespace VM::MACHINE {

    class REFA: public Delegate{

        virtual void run(Stackframe stackframe);
        virtual void run(Stackframe stackframe, TYPES::Reference a);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class REFF: public Delegate{

        virtual void run(Stackframe stackframe);
        virtual void run(Stackframe stackframe, TYPES::Reference a);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class MOV: public Delegate{
        virtual void run(Stackframe stackframe);
        virtual void run(Stackframe stackframe, TYPES::Reference a);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class SET: public Delegate{
        virtual void run(Stackframe stackframe);
        virtual void run(Stackframe stackframe, TYPES::Reference a);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class ASET: public Delegate{
        virtual void run(Stackframe stackframe);
        virtual void run(Stackframe stackframe, TYPES::Reference a);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class AGET: public Delegate{
        virtual void run(Stackframe stackframe);
        virtual void run(Stackframe stackframe, TYPES::Reference a);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class CPY: public Delegate{
        virtual void run(Stackframe stackframe);
        virtual void run(Stackframe stackframe, TYPES::Reference a);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
} // MACHINE

#endif //NUMVMV2_MEMORY_H
