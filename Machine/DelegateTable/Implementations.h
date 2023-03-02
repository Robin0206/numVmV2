//
// Created by robin on 02.03.23.
//

#ifndef NUMVMV2_IMPLEMENTATIONS_H
#define NUMVMV2_IMPLEMENTATIONS_H

#include "Delegate.h"

namespace VM::MACHINE {
    class Implementations : public Delegate {
        virtual void run();
        virtual void run(TYPES::Reference a);
        virtual void run(TYPES::Reference a, TYPES::Reference b);
        virtual void run(TYPES::Reference a, TYPES::Reference b, TYPES::Reference c);
    };
} // MACHINE

#endif //NUMVMV2_IMPLEMENTATIONS_H
