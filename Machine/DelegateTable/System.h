//
// Created by Robin on 02.03.2023.
//

#ifndef NUMVMV2_SYSTEM_H
#define NUMVMV2_SYSTEM_H

#include "Delegate.h"

namespace VM::MACHINE {
    class PRINT: public Delegate{
        virtual void run(Stackframe stackframe);
        virtual void run(Stackframe stackframe, TYPES::Reference a);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class BRANCH: public Delegate{
        virtual void run(Stackframe stackframe);
        virtual void run(Stackframe stackframe, TYPES::Reference a);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class LABEL: public Delegate{
        virtual void run(Stackframe stackframe);
        virtual void run(Stackframe stackframe, TYPES::Reference a);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class MAIN: public Delegate{
        virtual void run(Stackframe stackframe);
        virtual void run(Stackframe stackframe, TYPES::Reference a);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
    class MEND: public Delegate{
        virtual void run(Stackframe stackframe);
        virtual void run(Stackframe stackframe, TYPES::Reference a);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b);
        virtual void run(Stackframe stackframe, TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
} // MACHINE

#endif //NUMVMV2_SYSTEM_H
