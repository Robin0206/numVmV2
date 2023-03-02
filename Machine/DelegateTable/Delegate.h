//
// Created by robin on 02.03.23.
//

#ifndef NUMVMV2_DELEGATE_H
#define NUMVMV2_DELEGATE_H


#include "../Executor.h"

namespace VM::MACHINE::DELEGATES {
    struct Delegate {
        Executor *m_executor;

        void setExecutor(Executor *executor);

        virtual void run(Stackframe &stackframe) = 0;

        virtual void run(Stackframe &stackframe, TYPES::Reference &a) = 0;

        virtual void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) = 0;

        virtual void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) = 0;
    };


    struct ADD : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;

    };

    struct SUB : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct MUL : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct DIV : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };


    struct OR : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct AND : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct XOR : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct NOT : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct EQ : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };


    struct LSS : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct GRT : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct LSE : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct GRE : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };


    struct RET : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct CALL : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct PARG : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct ARG : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct FST : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct FEN : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };


    struct REFA : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;

    };

    struct REFF : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;

    };

    struct MOV : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct SET : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct ASET : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct AGET : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct CPY : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };


    struct PRINT : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct BRANCH : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct LABEL : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct MAIN : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct MEND : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };

    struct NOOP : public Delegate {
        void run(Stackframe &stackframe) override;

        void run(Stackframe &stackframe, TYPES::Reference &a) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b) override;

        void run(Stackframe &stackframe, TYPES::Reference &a, TYPES::Reference &b, TYPES::Reference &c) override;
    };
}
#endif //NUMVMV2_DELEGATE_H
