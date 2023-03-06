//
// Created by Robin on 02.03.2023.
//
#include "Delegate.h"
#include "../../Misc/ConstMakr.h"

void VM::MACHINE::DELEGATES::MUL::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to MUL");
}

void VM::MACHINE::DELEGATES::MUL::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to MUL");
}

void VM::MACHINE::DELEGATES::MUL::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                      VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to MUL");
}

void
VM::MACHINE::DELEGATES::MUL::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                 VM::TYPES::Reference &c) {
//see if types match
    if(a.m_type == b.m_type && b.m_type == c.m_type) {
        //set the references
        TYPES::Reference *dst;
        TYPES::Reference *opA;
        TYPES::Reference *opB;
        std::uint32_t
                dstId = *(reinterpret_cast<std::uint32_t *>(a.m_content.get())),
                aId = *(reinterpret_cast<std::uint32_t *>(b.m_content.get())),
                bId = *(reinterpret_cast<std::uint32_t *>(c.m_content.get()));
        bool
                dstSet = false,
                opASet = false,
                opBSet = false,
                allSet = false;
        for (auto &ref: stackframe.m_references) {
            if (ref.m_id == dstId) {
                dst = &ref;
                dstSet = true;
            }
            if (ref.m_id == aId) {
                opA = &ref;
                opASet = true;
            }
            if (ref.m_id == bId) {
                opB = &ref;
                opBSet = true;
            }
            if (opASet && opBSet && dstSet) {
                allSet = true;
                break;
            }
        }
        bool boolValue;
        std::uint8_t byteValue;
        std::uint32_t uIntValue;
        std::uint64_t uLongValue;
        std::int32_t intValue;
        std::int64_t longValue;
        long double ldValue;

        if (allSet) {
            //add and write them
            switch (opA->m_type) {
                case 0x0://bool
                    boolValue = true;
                    break;
                case 0x1://byte
                    byteValue = *((reinterpret_cast<uint8_t*>(opA->m_content.get())))*(*(reinterpret_cast<uint8_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &byteValue, BYTE_LENGTH);
                    break;
                case 0x2://uint32
                    uIntValue = *((reinterpret_cast<uint32_t*>(opA->m_content.get())))*(*(reinterpret_cast<uint32_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &uIntValue, INT_LENGTH);
                    break;
                case 0x3://uint64
                    uLongValue = *((reinterpret_cast<uint64_t*>(opA->m_content.get())))*(*(reinterpret_cast<uint64_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &uLongValue, LONG_LENGTH);
                    break;
                case 0x4://int32
                    intValue = *((reinterpret_cast<int32_t*>(opA->m_content.get())))*(*(reinterpret_cast<int32_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &intValue, INT_LENGTH);
                    break;
                case 0x5://int64
                    longValue = *((reinterpret_cast<int64_t*>(opA->m_content.get())))*(*(reinterpret_cast<int64_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &longValue, LONG_LENGTH);
                    break;
                case 0x6://long double
                    ldValue = *((reinterpret_cast<long double*>(opA->m_content.get())))*(*(reinterpret_cast<long double*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &ldValue, DEC_LENGTH);
                    break;
                default:
                    throw std::invalid_argument("EXCEPTION: called MUL with invalid type.");
            }
        } else {
            throw std::invalid_argument(
                    "EXCEPTION: invalid types got passed (by the machine!) to MUL(types dont match)");
        }

    }else{
        throw std::invalid_argument(
                "EXCEPTION: invalid ids got passed (by the machine!) to MUL(at least one not found)");
    }
}

void VM::MACHINE::DELEGATES::SUB::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to SUB");
}

void VM::MACHINE::DELEGATES::SUB::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to SUB");
}

void VM::MACHINE::DELEGATES::SUB::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                      VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to SUB");
}

void
VM::MACHINE::DELEGATES::SUB::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                 VM::TYPES::Reference &c) {

//see if types match
    if(a.m_type == b.m_type && b.m_type == c.m_type) {
        //set the references
        TYPES::Reference *dst;
        TYPES::Reference *opA;
        TYPES::Reference *opB;
        std::uint32_t
                dstId = *(reinterpret_cast<std::uint32_t *>(a.m_content.get())),
                aId = *(reinterpret_cast<std::uint32_t *>(b.m_content.get())),
                bId = *(reinterpret_cast<std::uint32_t *>(c.m_content.get()));
        bool
                dstSet = false,
                opASet = false,
                opBSet = false,
                allSet = false;
        for (auto &ref: stackframe.m_references) {
            if (ref.m_id == dstId) {
                dst = &ref;
                dstSet = true;
            }
            if (ref.m_id == aId) {
                opA = &ref;
                opASet = true;
            }
            if (ref.m_id == bId) {
                opB = &ref;
                opBSet = true;
            }
            if (opASet && opBSet && dstSet) {
                allSet = true;
                break;
            }
        }
        bool boolValue;
        std::uint8_t byteValue = 1;
        std::uint32_t uIntValue = 1;;
        std::uint64_t uLongValue = 1;;
        std::int32_t intValue = 1;;
        std::int64_t longValue = 1;;
        long double ldValue = 1.0l;

        if (allSet) {
            //add and write them
            switch (opA->m_type) {
                case 0x0://bool
                    boolValue = true;
                    break;
                case 0x1://byte
                    byteValue = *(reinterpret_cast<uint8_t*>(opA->m_content.get()))-*(reinterpret_cast<uint8_t*>(opB->m_content.get()));
                    std::memcpy(dst->m_content.get(), &byteValue, BYTE_LENGTH);
                    break;
                case 0x2://uint32
                    uIntValue = *(reinterpret_cast<uint32_t*>(opA->m_content.get()))-*(reinterpret_cast<uint32_t*>(opB->m_content.get()));
                    std::memcpy(dst->m_content.get(), &uIntValue, INT_LENGTH);
                    break;
                case 0x3://uint64
                    uLongValue = *(reinterpret_cast<uint64_t*>(opA->m_content.get()))-*(reinterpret_cast<uint64_t*>(opB->m_content.get()));
                    std::memcpy(dst->m_content.get(), &uLongValue, LONG_LENGTH);
                    break;
                case 0x4://int32
                    intValue = *(reinterpret_cast<int32_t*>(opA->m_content.get()))-*(reinterpret_cast<int32_t*>(opB->m_content.get()));
                    std::memcpy(dst->m_content.get(), &intValue, INT_LENGTH);
                    break;
                case 0x5://int64
                    longValue = *(reinterpret_cast<int64_t*>(opA->m_content.get()))-*(reinterpret_cast<int64_t*>(opB->m_content.get()));
                    std::memcpy(dst->m_content.get(), &longValue, LONG_LENGTH);
                    break;
                case 0x6://long double
                    ldValue = *(reinterpret_cast<long double*>(opA->m_content.get()))-*(reinterpret_cast<long double*>(opB->m_content.get()));
                    std::memcpy(dst->m_content.get(), &ldValue, DEC_LENGTH);
                    break;
                default:
                    throw std::invalid_argument("EXCEPTION: called SUB with invalid type.");
            }
        } else {
            throw std::invalid_argument(
                    "EXCEPTION: invalid types got passed (by the machine!) to SUB(types dont match)");
        }

    }else{
        throw std::invalid_argument(
                "EXCEPTION: invalid ids got passed (by the machine!) to SUB(at least one not found)");
    }

}

void VM::MACHINE::DELEGATES::ADD::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to ADD");
}

void VM::MACHINE::DELEGATES::ADD::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to ADD");
}

void VM::MACHINE::DELEGATES::ADD::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                      VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to ADD");
}

void
VM::MACHINE::DELEGATES::ADD::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                 VM::TYPES::Reference &c) {
//see if types match
    if(a.m_type == b.m_type && b.m_type == c.m_type) {
        //set the references
        TYPES::Reference *dst;
        TYPES::Reference *opA;
        TYPES::Reference *opB;
        std::uint32_t
                dstId = *(reinterpret_cast<std::uint32_t *>(a.m_content.get())),
                aId = *(reinterpret_cast<std::uint32_t *>(b.m_content.get())),
                bId = *(reinterpret_cast<std::uint32_t *>(c.m_content.get()));
        bool
                dstSet = false,
                opASet = false,
                opBSet = false,
                allSet = false;
        for (auto &ref: stackframe.m_references) {
            if (ref.m_id == dstId) {
                dst = &ref;
                dstSet = true;
            }
            if (ref.m_id == aId) {
                opA = &ref;
                opASet = true;
            }
            if (ref.m_id == bId) {
                opB = &ref;
                opBSet = true;
            }
            if (opASet && opBSet && dstSet) {
                allSet = true;
                break;
            }
        }
        bool boolValue;
        std::uint8_t byteValue;
        std::uint32_t uIntValue;
        std::uint64_t uLongValue;
        std::int32_t intValue;
        std::int64_t longValue;
        long double ldValue;

        if (allSet) {
            //add and write them
            switch (opA->m_type) {
                case 0x0://bool
                    boolValue = true;
                    break;
                case 0x1://byte
                    byteValue = *(reinterpret_cast<uint8_t*>(opA->m_content.get()))+*(reinterpret_cast<uint8_t*>(opB->m_content.get()));
                    std::memcpy(dst->m_content.get(), &byteValue, BYTE_LENGTH);
                    break;
                case 0x2://uint32
                    uIntValue = *(reinterpret_cast<uint32_t*>(opA->m_content.get()))+*(reinterpret_cast<uint32_t*>(opB->m_content.get()));
                    std::memcpy(dst->m_content.get(), &uIntValue, INT_LENGTH);
                    break;
                case 0x3://uint64
                    uLongValue = *(reinterpret_cast<uint64_t*>(opA->m_content.get()))+*(reinterpret_cast<uint64_t*>(opB->m_content.get()));
                    std::memcpy(dst->m_content.get(), &uLongValue, LONG_LENGTH);
                    break;
                case 0x4://int32
                    intValue = *(reinterpret_cast<int32_t*>(opA->m_content.get()))+*(reinterpret_cast<int32_t*>(opB->m_content.get()));
                    std::memcpy(dst->m_content.get(), &intValue, INT_LENGTH);
                    break;
                case 0x5://int64
                    longValue = *(reinterpret_cast<int64_t*>(opA->m_content.get()))+*(reinterpret_cast<int64_t*>(opB->m_content.get()));
                    std::memcpy(dst->m_content.get(), &longValue, LONG_LENGTH);
                    break;
                case 0x6://long double
                    ldValue = *(reinterpret_cast<long double*>(opA->m_content.get()))+*(reinterpret_cast<long double*>(opB->m_content.get()));
                    std::memcpy(dst->m_content.get(), &ldValue, DEC_LENGTH);
                    break;
                default:
                    throw std::invalid_argument("EXCEPTION: called ADD with invalid type.");
            }
        } else {
            throw std::invalid_argument(
                    "EXCEPTION: invalid types got passed (by the machine!) to ADD(types dont match)");
        }

    }else{
        throw std::invalid_argument(
                "EXCEPTION: invalid ids got passed (by the machine!) to ADD(at least one not found)");
    }

}

void VM::MACHINE::DELEGATES::Delegate::setExecutor(VM::MACHINE::Executor *executor) {

}



void VM::MACHINE::DELEGATES::DIV::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to DIV");
}

void VM::MACHINE::DELEGATES::DIV::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to DIV");
}

void VM::MACHINE::DELEGATES::DIV::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                      VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to DIV");
}

void
VM::MACHINE::DELEGATES::DIV::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                 VM::TYPES::Reference &c) {
//see if types match
    if(a.m_type == b.m_type && b.m_type == c.m_type) {
        //set the references
        TYPES::Reference *dst;
        TYPES::Reference *opA;
        TYPES::Reference *opB;
        std::uint32_t
                dstId = *(reinterpret_cast<std::uint32_t *>(a.m_content.get())),
                aId = *(reinterpret_cast<std::uint32_t *>(b.m_content.get())),
                bId = *(reinterpret_cast<std::uint32_t *>(c.m_content.get()));
        bool
                dstSet = false,
                opASet = false,
                opBSet = false,
                allSet = false;
        for (auto &ref: stackframe.m_references) {
            if (ref.m_id == dstId) {
                dst = &ref;
                dstSet = true;
            }
            if (ref.m_id == aId) {
                opA = &ref;
                opASet = true;
            }
            if (ref.m_id == bId) {
                opB = &ref;
                opBSet = true;
            }
            if (opASet && opBSet && dstSet) {
                allSet = true;
                break;
            }
        }
        bool boolValue;
        std::uint8_t byteValue;
        std::uint32_t uIntValue;
        std::uint64_t uLongValue;
        std::int32_t intValue;
        std::int64_t longValue;
        long double ldValue;

        if (allSet) {
            //add and write them
            switch (opA->m_type) {
                case 0x0://bool
                    boolValue = true;
                    break;
                case 0x1://byte
                    byteValue = *((reinterpret_cast<uint8_t*>(opA->m_content.get())))/(*(reinterpret_cast<uint8_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &byteValue, BYTE_LENGTH);
                    break;
                case 0x2://uint32
                    uIntValue = *((reinterpret_cast<uint32_t*>(opA->m_content.get())))/(*(reinterpret_cast<uint32_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &uIntValue, INT_LENGTH);
                    break;
                case 0x3://uint64
                    uLongValue = *((reinterpret_cast<uint64_t*>(opA->m_content.get())))/(*(reinterpret_cast<uint64_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &uLongValue, LONG_LENGTH);
                    break;
                case 0x4://int32
                    intValue = *((reinterpret_cast<int32_t*>(opA->m_content.get())))/(*(reinterpret_cast<int32_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &intValue, INT_LENGTH);
                    break;
                case 0x5://int64
                    longValue = *((reinterpret_cast<int64_t*>(opA->m_content.get())))/(*(reinterpret_cast<int64_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &longValue, LONG_LENGTH);
                    break;
                case 0x6://long double
                    ldValue = *((reinterpret_cast<long double*>(opA->m_content.get())))/(*(reinterpret_cast<long double*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &ldValue, DEC_LENGTH);
                    break;
                default:
                    throw std::invalid_argument("EXCEPTION: called DIV with invalid type.");
            }
        } else {
            throw std::invalid_argument(
                    "EXCEPTION: invalid types got passed (by the machine!) to DIV(types dont match)");
        }

    }else{
        throw std::invalid_argument(
                "EXCEPTION: invalid ids got passed (by the machine!) to DIV(at least one not found)");
    }

}

void VM::MACHINE::DELEGATES::OR::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to OR");
}

void VM::MACHINE::DELEGATES::OR::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to OR");
}

void VM::MACHINE::DELEGATES::OR::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                     VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to OR");
}

void
VM::MACHINE::DELEGATES::OR::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                VM::TYPES::Reference &c) {
//see if types match
    if(a.m_type == b.m_type && b.m_type == c.m_type) {
        //set the references
        TYPES::Reference *dst;
        TYPES::Reference *opA;
        TYPES::Reference *opB;
        std::uint32_t
                dstId = *(reinterpret_cast<std::uint32_t *>(a.m_content.get())),
                aId = *(reinterpret_cast<std::uint32_t *>(b.m_content.get())),
                bId = *(reinterpret_cast<std::uint32_t *>(c.m_content.get()));
        bool
                dstSet = false,
                opASet = false,
                opBSet = false,
                allSet = false;
        for (auto &ref: stackframe.m_references) {
            if (ref.m_id == dstId) {
                dst = &ref;
                dstSet = true;
            }
            if (ref.m_id == aId) {
                opA = &ref;
                opASet = true;
            }
            if (ref.m_id == bId) {
                opB = &ref;
                opBSet = true;
            }
            if (opASet && opBSet && dstSet) {
                allSet = true;
                break;
            }
        }
        bool boolValue;
        std::uint8_t byteValue;
        std::uint32_t uIntValue;
        std::uint64_t uLongValue;
        std::int32_t intValue;
        std::int64_t longValue;
        long double ldValue;

        if (allSet) {
            //add and write them
            switch (opA->m_type) {
                case 0x0://bool
                    boolValue = true;
                    break;
                case 0x1://byte
                    byteValue = *((reinterpret_cast<uint8_t*>(opA->m_content.get())))|(*(reinterpret_cast<uint8_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &byteValue, BYTE_LENGTH);
                    break;
                case 0x2://uint32
                    uIntValue = *((reinterpret_cast<uint32_t*>(opA->m_content.get())))|(*(reinterpret_cast<uint32_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &uIntValue, INT_LENGTH);
                    break;
                case 0x3://uint64
                    uLongValue = *((reinterpret_cast<uint64_t*>(opA->m_content.get())))|(*(reinterpret_cast<uint64_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &uLongValue, LONG_LENGTH);
                    break;
                case 0x4://int32
                    intValue = *((reinterpret_cast<int32_t*>(opA->m_content.get())))|(*(reinterpret_cast<int32_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &intValue, INT_LENGTH);
                    break;
                case 0x5://int64
                    longValue = *((reinterpret_cast<int64_t*>(opA->m_content.get())))|(*(reinterpret_cast<int64_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &longValue, LONG_LENGTH);
                    break;
                case 0x6://long double
                    throw std::invalid_argument("EXCEPTION: called OR with invalid type(DEC).");
                    break;
                default:
                    throw std::invalid_argument("EXCEPTION: called OR with invalid type.");
            }
        } else {
            throw std::invalid_argument(
                    "EXCEPTION: invalid types got passed (by the machine!) to OR(types dont match)");
        }

    }else{
        throw std::invalid_argument(
                "EXCEPTION: invalid ids got passed (by the machine!) to OR(at least one not found)");
    }

}

void VM::MACHINE::DELEGATES::AND::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to AND");
}

void VM::MACHINE::DELEGATES::AND::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to AND");
}

void VM::MACHINE::DELEGATES::AND::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                      VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to AND");
}

void
VM::MACHINE::DELEGATES::AND::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                 VM::TYPES::Reference &c) {
//see if types match
    if(a.m_type == b.m_type && b.m_type == c.m_type) {
        //set the references
        TYPES::Reference *dst;
        TYPES::Reference *opA;
        TYPES::Reference *opB;
        std::uint32_t
                dstId = *(reinterpret_cast<std::uint32_t *>(a.m_content.get())),
                aId = *(reinterpret_cast<std::uint32_t *>(b.m_content.get())),
                bId = *(reinterpret_cast<std::uint32_t *>(c.m_content.get()));
        bool
                dstSet = false,
                opASet = false,
                opBSet = false,
                allSet = false;
        for (auto &ref: stackframe.m_references) {
            if (ref.m_id == dstId) {
                dst = &ref;
                dstSet = true;
            }
            if (ref.m_id == aId) {
                opA = &ref;
                opASet = true;
            }
            if (ref.m_id == bId) {
                opB = &ref;
                opBSet = true;
            }
            if (opASet && opBSet && dstSet) {
                allSet = true;
                break;
            }
        }
        bool boolValue;
        std::uint8_t byteValue;
        std::uint32_t uIntValue;
        std::uint64_t uLongValue;
        std::int32_t intValue;
        std::int64_t longValue;
        long double ldValue;

        if (allSet) {
            //add and write them
            switch (opA->m_type) {
                case 0x0://bool
                    boolValue = true;
                    break;
                case 0x1://byte
                    byteValue = *((reinterpret_cast<uint8_t*>(opA->m_content.get())))&(*(reinterpret_cast<uint8_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &byteValue, BYTE_LENGTH);
                    break;
                case 0x2://uint32
                    uIntValue = *((reinterpret_cast<uint32_t*>(opA->m_content.get())))&(*(reinterpret_cast<uint32_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &uIntValue, INT_LENGTH);
                    break;
                case 0x3://uint64
                    uLongValue = *((reinterpret_cast<uint64_t*>(opA->m_content.get())))&(*(reinterpret_cast<uint64_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &uLongValue, LONG_LENGTH);
                    break;
                case 0x4://int32
                    intValue = *((reinterpret_cast<int32_t*>(opA->m_content.get())))&(*(reinterpret_cast<int32_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &intValue, INT_LENGTH);
                    break;
                case 0x5://int64
                    longValue = *((reinterpret_cast<int64_t*>(opA->m_content.get())))&(*(reinterpret_cast<int64_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &longValue, LONG_LENGTH);
                    break;
                case 0x6://long double
                    throw std::invalid_argument("EXCEPTION: called AND with invalid type (DEC).");
                    break;
                default:
                    throw std::invalid_argument("EXCEPTION: called AND with invalid type.");
            }
        } else {
            throw std::invalid_argument(
                    "EXCEPTION: invalid types got passed (by the machine!) to AND(types dont match)");
        }

    }else{
        throw std::invalid_argument(
                "EXCEPTION: invalid ids got passed (by the machine!) to AND(at least one not found)");
    }

}

void VM::MACHINE::DELEGATES::XOR::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to XOR");
}

void VM::MACHINE::DELEGATES::XOR::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to XOR");
}

void VM::MACHINE::DELEGATES::XOR::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                      VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to XOR");
}

void
VM::MACHINE::DELEGATES::XOR::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                 VM::TYPES::Reference &c) {
//see if types match
    if(a.m_type == b.m_type && b.m_type == c.m_type) {
        //set the references
        TYPES::Reference *dst;
        TYPES::Reference *opA;
        TYPES::Reference *opB;
        std::uint32_t
                dstId = *(reinterpret_cast<std::uint32_t *>(a.m_content.get())),
                aId = *(reinterpret_cast<std::uint32_t *>(b.m_content.get())),
                bId = *(reinterpret_cast<std::uint32_t *>(c.m_content.get()));
        bool
                dstSet = false,
                opASet = false,
                opBSet = false,
                allSet = false;
        for (auto &ref: stackframe.m_references) {
            if (ref.m_id == dstId) {
                dst = &ref;
                dstSet = true;
            }
            if (ref.m_id == aId) {
                opA = &ref;
                opASet = true;
            }
            if (ref.m_id == bId) {
                opB = &ref;
                opBSet = true;
            }
            if (opASet && opBSet && dstSet) {
                allSet = true;
                break;
            }
        }
        bool boolValue;
        std::uint8_t byteValue;
        std::uint32_t uIntValue;
        std::uint64_t uLongValue;
        std::int32_t intValue;
        std::int64_t longValue;
        long double ldValue;

        if (allSet) {
            //add and write them
            switch (opA->m_type) {
                case 0x0://bool
                    boolValue = true;
                    break;
                case 0x1://byte
                    byteValue = *((reinterpret_cast<uint8_t*>(opA->m_content.get())))^(*(reinterpret_cast<uint8_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &byteValue, BYTE_LENGTH);
                    break;
                case 0x2://uint32
                    uIntValue = *((reinterpret_cast<uint32_t*>(opA->m_content.get())))^(*(reinterpret_cast<uint32_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &uIntValue, INT_LENGTH);
                    break;
                case 0x3://uint64
                    uLongValue = *((reinterpret_cast<uint64_t*>(opA->m_content.get())))^(*(reinterpret_cast<uint64_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &uLongValue, LONG_LENGTH);
                    break;
                case 0x4://int32
                    intValue = *((reinterpret_cast<int32_t*>(opA->m_content.get())))^(*(reinterpret_cast<int32_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &intValue, INT_LENGTH);
                    break;
                case 0x5://int64
                    longValue = *((reinterpret_cast<int64_t*>(opA->m_content.get())))^(*(reinterpret_cast<int64_t*>(opB->m_content.get())));
                    std::memcpy(dst->m_content.get(), &longValue, LONG_LENGTH);
                    break;
                case 0x6://long double
                    throw std::invalid_argument("EXCEPTION: called XOR with invalid type.(DEC)");
                    break;
                default:
                    throw std::invalid_argument("EXCEPTION: called XOR with invalid type.");
            }
        } else {
            throw std::invalid_argument(
                    "EXCEPTION: invalid types got passed (by the machine!) to XOR(types dont match)");
        }

    }else{
        throw std::invalid_argument(
                "EXCEPTION: invalid ids got passed (by the machine!) to XOR(at least one not found)");
    }
}

void VM::MACHINE::DELEGATES::NOT::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to NOT");
}

void VM::MACHINE::DELEGATES::NOT::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to NOT");
}

void VM::MACHINE::DELEGATES::NOT::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                      VM::TYPES::Reference &b) {
    if(a.m_type == b.m_type && b.m_type) {
        //set the references
        TYPES::Reference *dst;
        TYPES::Reference *opA;
        std::uint32_t
                dstId = *(reinterpret_cast<std::uint32_t *>(a.m_content.get())),
                aId = *(reinterpret_cast<std::uint32_t *>(b.m_content.get()));
        bool
                dstSet = false,
                opASet = false,
                allSet = false;
        for (auto &ref: stackframe.m_references) {
            if (ref.m_id == dstId) {
                dst = &ref;
                dstSet = true;
            }
            if (ref.m_id == aId) {
                opA = &ref;
                opASet = true;
            }
            if (opASet && dstSet) {
                allSet = true;
                break;
            }
        }
        bool boolValue;
        std::uint8_t byteValue;
        std::uint32_t uIntValue;
        std::uint64_t uLongValue;
        std::int32_t intValue;
        std::int64_t longValue;
        long double ldValue;

        if (allSet) {
            //add and write them
            switch (opA->m_type) {
                case 0x0://bool
                    boolValue = true;
                    break;
                case 0x1://byte
                    byteValue = ~(*((reinterpret_cast<uint8_t*>(opA->m_content.get()))));
                    std::memcpy(dst->m_content.get(), &byteValue, BYTE_LENGTH);
                    break;
                case 0x2://uint32
                    uIntValue = ~(*((reinterpret_cast<uint32_t*>(opA->m_content.get()))));
                    std::memcpy(dst->m_content.get(), &uIntValue, INT_LENGTH);
                    break;
                case 0x3://uint64
                    uLongValue = ~(*((reinterpret_cast<uint64_t*>(opA->m_content.get()))));
                    std::memcpy(dst->m_content.get(), &uLongValue, LONG_LENGTH);
                    break;
                case 0x4://int32
                    intValue = ~(*((reinterpret_cast<int32_t*>(opA->m_content.get()))));
                    std::memcpy(dst->m_content.get(), &intValue, INT_LENGTH);
                    break;
                case 0x5://int64
                    longValue = ~(*((reinterpret_cast<int64_t*>(opA->m_content.get()))));
                    std::memcpy(dst->m_content.get(), &longValue, LONG_LENGTH);
                    break;
                case 0x6://long double
                    throw std::invalid_argument("EXCEPTION: called NOT with invalid type.(DEC)");
                    break;
                default:
                    throw std::invalid_argument("EXCEPTION: called NOT with invalid type.");
            }
        } else {
            throw std::invalid_argument(
                    "EXCEPTION: invalid types got passed (by the machine!) to NOT(types dont match)");
        }

    }else{
        throw std::invalid_argument(
                "EXCEPTION: invalid ids got passed (by the machine!) to XOR(at least one not found)");
    }
}

void
VM::MACHINE::DELEGATES::NOT::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                 VM::TYPES::Reference &c) {
    throw std::invalid_argument("EXCEPTION: 3 Arguments got passed (by the machine!) to NOT");
}

void VM::MACHINE::DELEGATES::EQ::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to EQ");
}

void VM::MACHINE::DELEGATES::EQ::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to EQ");
}

void VM::MACHINE::DELEGATES::EQ::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                     VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to EQ");
}

void
VM::MACHINE::DELEGATES::EQ::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                VM::TYPES::Reference &c) {

    TYPES::Reference *dst;
    TYPES::Reference *opA;
    TYPES::Reference *opB;
    std::uint32_t
            dstId = *(reinterpret_cast<std::uint32_t *>(a.m_content.get())),
            aId = *(reinterpret_cast<std::uint32_t *>(b.m_content.get())),
            bId = *(reinterpret_cast<std::uint32_t *>(c.m_content.get()));
    bool
            dstSet = false,
            opASet = false,
            opBSet = false,
            allSet = false;
    for (auto &ref: stackframe.m_references) {
        if (ref.m_id == dstId) {
            dst = &ref;
            dstSet = true;
        }
        if (ref.m_id == aId) {
            opA = &ref;
            opASet = true;
        }
        if (ref.m_id == bId) {
            opB = &ref;
            opBSet = true;
        }
        if (opASet && opBSet && dstSet) {
            allSet = true;
            break;
        }
    }
    //See if types match
    if(dst->m_type != 0x0){
        throw std::invalid_argument("EXCEPTION: first Argument passed (by the machine) to EQ must be a bool");
    }
    if(opB->m_type != opA->m_type){
        throw std::invalid_argument("EXCEPTION: invalid types got passed (by the machine!) to EQ(types of second and third argument dont match)");
    }
    bool result;
    switch (opA->m_type) {
        case 0x0://bool
            result = (*((bool*)opA->m_content.get()))==(*((bool*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x1://byte
            result = (*((std::uint8_t*)opA->m_content.get()))==(*((std::uint8_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x2://uint32
            result = (*((std::uint32_t*)opA->m_content.get()))==(*((std::uint32_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x3://uint64
            result = (*((std::uint64_t*)opA->m_content.get()))==(*((std::uint64_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x4://int32
            result = (*((std::int32_t*)opA->m_content.get()))==(*((std::int32_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x5://int64
            result = (*((std::int64_t*)opA->m_content.get()))==(*((std::int64_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x6://long double
            result = (*((long double*)opA->m_content.get()))==(*((long double*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        default:
            throw std::invalid_argument("EXCEPTION: called EQ with invalid type?????.");
    }
}

void VM::MACHINE::DELEGATES::LSS::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to LSS");
}

void VM::MACHINE::DELEGATES::LSS::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to LSS");
}

void VM::MACHINE::DELEGATES::LSS::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                      VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to LSS");
}

void
VM::MACHINE::DELEGATES::LSS::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                 VM::TYPES::Reference &c) {
    //See if types match

    TYPES::Reference *dst;
    TYPES::Reference *opA;
    TYPES::Reference *opB;
    std::uint32_t
            dstId = *(reinterpret_cast<std::uint32_t *>(a.m_content.get())),
            aId = *(reinterpret_cast<std::uint32_t *>(b.m_content.get())),
            bId = *(reinterpret_cast<std::uint32_t *>(c.m_content.get()));
    bool
            dstSet = false,
            opASet = false,
            opBSet = false,
            allSet = false;
    for (auto &ref: stackframe.m_references) {
        if (ref.m_id == dstId) {
            dst = &ref;
            dstSet = true;
        }
        if (ref.m_id == aId) {
            opA = &ref;
            opASet = true;
        }
        if (ref.m_id == bId) {
            opB = &ref;
            opBSet = true;
        }
        if (opASet && opBSet && dstSet) {
            allSet = true;
            break;
        }
    }
    if(dst->m_type != 0x0){
        throw std::invalid_argument("EXCEPTION: first Argument passed (by the machine) to LSS must be a bool");
    }
    if(opB->m_type != opA->m_type){
        throw std::invalid_argument("EXCEPTION: invalid types got passed (by the machine!) to LSS(types of second and third argument dont match)");
    }
    bool result;
    switch (opA->m_type) {
        case 0x0://bool
            result = (*((bool*)opA->m_content.get()))<(*((bool*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x1://byte
            result = (*((std::uint8_t*)opA->m_content.get()))<(*((std::uint8_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x2://uint32
            result = (*((std::uint32_t*)opA->m_content.get()))<(*((std::uint32_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x3://uint64
            result = (*((std::uint64_t*)opA->m_content.get()))<(*((std::uint64_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x4://int32
            result = (*((std::int32_t*)opA->m_content.get()))<(*((std::int32_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x5://int64
            result = (*((std::int64_t*)opA->m_content.get()))<(*((std::int64_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x6://long double
            result = (*((long double*)opA->m_content.get()))<(*((long double*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        default:
            throw std::invalid_argument("EXCEPTION: called LSS with invalid type?????.");
    }
}

void VM::MACHINE::DELEGATES::GRT::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to GRT");
}

void VM::MACHINE::DELEGATES::GRT::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to GRT");
}

void VM::MACHINE::DELEGATES::GRT::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                      VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to GRT");
}

void
VM::MACHINE::DELEGATES::GRT::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                 VM::TYPES::Reference &c) {

    TYPES::Reference *dst;
    TYPES::Reference *opA;
    TYPES::Reference *opB;
    std::uint32_t
            dstId = *(reinterpret_cast<std::uint32_t *>(a.m_content.get())),
            aId = *(reinterpret_cast<std::uint32_t *>(b.m_content.get())),
            bId = *(reinterpret_cast<std::uint32_t *>(c.m_content.get()));
    bool
            dstSet = false,
            opASet = false,
            opBSet = false,
            allSet = false;
    for (auto &ref: stackframe.m_references) {
        if (ref.m_id == dstId) {
            dst = &ref;
            dstSet = true;
        }
        if (ref.m_id == aId) {
            opA = &ref;
            opASet = true;
        }
        if (ref.m_id == bId) {
            opB = &ref;
            opBSet = true;
        }
        if (opASet && opBSet && dstSet) {
            allSet = true;
            break;
        }
    }
    //See if types match
    if(dst->m_type != 0x0){
        throw std::invalid_argument("EXCEPTION: first Argument passed (by the machine) to GRT must be a bool");
    }
    if(opB->m_type != opA->m_type){
        throw std::invalid_argument("EXCEPTION: invalid types got passed (by the machine!) to GRT(types of second and third argument dont match)");
    }
    bool result;
    switch (opA->m_type) {
        case 0x0://bool
            result = (*((bool*)opA->m_content.get()))>(*((bool*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x1://byte
            result = (*((std::uint8_t*)opA->m_content.get()))>(*((std::uint8_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x2://uint32
            result = (*((std::uint32_t*)opA->m_content.get()))>(*((std::uint32_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x3://uint64
            result = (*((std::uint64_t*)opA->m_content.get()))>(*((std::uint64_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x4://int32
            result = (*((std::int32_t*)opA->m_content.get()))>(*((std::int32_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x5://int64
            result = (*((std::int64_t*)opA->m_content.get()))>(*((std::int64_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x6://long double
            result = (*((long double*)opA->m_content.get()))>(*((long double*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        default:
            throw std::invalid_argument("EXCEPTION: called GRT with invalid type?????.");
    }
}

void VM::MACHINE::DELEGATES::LSE::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to LSE");
}

void VM::MACHINE::DELEGATES::LSE::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to LSE");
}

void VM::MACHINE::DELEGATES::LSE::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                      VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to LSE");
}

void
VM::MACHINE::DELEGATES::LSE::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                 VM::TYPES::Reference &c) {

    TYPES::Reference *dst;
    TYPES::Reference *opA;
    TYPES::Reference *opB;
    std::uint32_t
            dstId = *(reinterpret_cast<bool *>(a.m_content.get())),
            aId = *(reinterpret_cast<std::uint32_t *>(b.m_content.get())),
            bId = *(reinterpret_cast<std::uint32_t *>(c.m_content.get()));
    bool
            dstSet = false,
            opASet = false,
            opBSet = false,
            allSet = false;
    for (auto &ref: stackframe.m_references) {
        if (ref.m_id == dstId) {
            dst = &ref;
            dstSet = true;
        }
        if (ref.m_id == aId) {
            opA = &ref;
            opASet = true;
        }
        if (ref.m_id == bId) {
            opB = &ref;
            opBSet = true;
        }
        if (opASet && opBSet && dstSet) {
            allSet = true;
            break;
        }
    }
    //See if types match
    if(dst->m_type != 0x0){
        throw std::invalid_argument("EXCEPTION: first Argument passed (by the machine) to LSE must be a bool");
    }
    if(opB->m_type != opA->m_type){
        throw std::invalid_argument("EXCEPTION: invalid types got passed (by the machine!) to LSE(types of second and third argument dont match)");
    }
    bool result;
    switch (opA->m_type) {
        case 0x0://bool
            result =  (*((bool*)opA->m_content.get()))<=(*((bool*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x1://byte
            result = (*((std::uint8_t*)opA->m_content.get()))<=(*((std::uint8_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x2://uint32
            result = (*((std::uint32_t*)opA->m_content.get()))<=(*((std::uint32_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x3://uint64
            result = (*((std::uint64_t*)opA->m_content.get()))<=(*((std::uint64_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x4://int32
            result = (*((std::int32_t*)opA->m_content.get()))<=(*((std::int32_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x5://int64
            result = (*((std::int64_t*)opA->m_content.get()))<=(*((std::int64_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x6://long double
            result = (*((long double*)opA->m_content.get()))<=(*((long double*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        default:
            throw std::invalid_argument("EXCEPTION: called LSE with invalid type?????.");
    }
}

void VM::MACHINE::DELEGATES::GRE::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to GRE");
}

void VM::MACHINE::DELEGATES::GRE::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to GRE");
}

void VM::MACHINE::DELEGATES::GRE::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                      VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to GRE");
}

void
VM::MACHINE::DELEGATES::GRE::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                 VM::TYPES::Reference &c) {

    TYPES::Reference *dst;
    TYPES::Reference *opA;
    TYPES::Reference *opB;
    std::uint32_t
            dstId = *(reinterpret_cast<bool *>(a.m_content.get())),
            aId = *(reinterpret_cast<std::uint32_t *>(b.m_content.get())),
            bId = *(reinterpret_cast<std::uint32_t *>(c.m_content.get()));
    bool
            dstSet = false,
            opASet = false,
            opBSet = false,
            allSet = false;
    for (auto &ref: stackframe.m_references) {
        if (ref.m_id == dstId) {
            dst = &ref;
            dstSet = true;
        }
        if (ref.m_id == aId) {
            opA = &ref;
            opASet = true;
        }
        if (ref.m_id == bId) {
            opB = &ref;
            opBSet = true;
        }
        if (opASet && opBSet && dstSet) {
            allSet = true;
            break;
        }
    }
    //See if types match
    if(dst->m_type != 0x0){
        throw std::invalid_argument("EXCEPTION: first Argument passed (by the machine) to GRE must be a bool");
    }
    if(opB->m_type != opA->m_type){
        throw std::invalid_argument("EXCEPTION: invalid types got passed (by the machine!) to GRE(types of second and third argument dont match)");
    }
    bool result;
    switch (opA->m_type) {
        case 0x0://bool
            result = (*((bool*)opA->m_content.get()))>=(*((bool*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x1://byte
            result = (*((std::uint8_t*)opA->m_content.get()))>=(*((std::uint8_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x2://uint32
            result = (*((std::uint32_t*)opA->m_content.get()))>=(*((std::uint32_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x3://uint64
            result = (*((std::uint64_t*)opA->m_content.get()))>=(*((std::uint64_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x4://int32
            result = (*((std::int32_t*)opA->m_content.get()))>=(*((std::int32_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x5://int64
            result = (*((std::int64_t*)opA->m_content.get()))>=(*((std::int64_t*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        case 0x6://long double
            result = (*((long double*)opA->m_content.get()))>=(*((long double*)opB->m_content.get()));
            std::memcpy(dst->m_content.get(), &result, BOOL_LENGTH);
            break;
        default:
            throw std::invalid_argument("EXCEPTION: called GRE with invalid type?????.");
    }
}

void VM::MACHINE::DELEGATES::RET::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to RET");
}

void VM::MACHINE::DELEGATES::RET::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    std::uint32_t id = *(reinterpret_cast<std::uint32_t*>(a.m_content.get()));
    bool returnedElement = false;
    for(std::size_t i = 0; i < stackframe.m_references.size(); i++){
        if(stackframe.m_references[i].m_id == id){
            stackframe.m_executor->m_returnRegister = TYPES::Reference(stackframe.m_references[i]);
            returnedElement = true;
            break;
        }
    }
    if(!returnedElement){
        throw std::invalid_argument("EXCEPTION: invalid id got passed (by the machine!) to REFF");
    }
}

void VM::MACHINE::DELEGATES::RET::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                      VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to RET");
}

void
VM::MACHINE::DELEGATES::RET::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                 VM::TYPES::Reference &c) {
    throw std::invalid_argument("EXCEPTION: 3 Arguments got passed (by the machine!) to RET");
}

void VM::MACHINE::DELEGATES::CALL::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to CALL");
}

void VM::MACHINE::DELEGATES::CALL::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    std::uint32_t id = *(reinterpret_cast<std::uint32_t*>(a.m_content.get()));
    std::uint32_t index = 1;
    bool foundIndex = false;
    for(std::size_t i = 0; i < stackframe.m_executor->m_functions.size(); i++){
        if(stackframe.m_executor->m_functions[i].m_id == id){
            index = i;
            foundIndex = true;
        }
    }
    if(foundIndex){
        Stackframe frameToPass = Stackframe();
        frameToPass.init(stackframe.m_function.m_machine->m_functions[index],stackframe.m_function.m_machine);
        for(auto& arg : stackframe.m_function.m_machine->m_argRegisters){
            frameToPass.m_arguments.push_back(arg);
        }
        stackframe.m_executor->m_stack.push_back(frameToPass);
        if(!stackframe.m_function.m_machine->m_argRegisters.empty()){
            stackframe.m_function.m_machine->m_argRegisters.clear();
        }
    }else{
        throw std::invalid_argument("EXCEPTION: invalid id got passed (by the machine!) to CALL");
    }
}

void VM::MACHINE::DELEGATES::CALL::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                       VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to CALL");
}

void
VM::MACHINE::DELEGATES::CALL::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                  VM::TYPES::Reference &c) {
    throw std::invalid_argument("EXCEPTION: 3 Arguments got passed (by the machine!) to CALL");
}

void VM::MACHINE::DELEGATES::PARG::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to PARG");
}

void VM::MACHINE::DELEGATES::PARG::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    //search for the reference
    TYPES::Reference* refToPush;
    std::uint32_t refId = *(reinterpret_cast<std::uint32_t*>(a.m_content.get()));
    bool foundRef = false;
    for(auto& ref : stackframe.m_references){
        if(ref.m_id == refId){
            refToPush = &ref;
            foundRef = true;
        }
    }
    //push it to the argRegister
    if(foundRef){
        stackframe.m_executor->m_argRegisters.push_back(*(refToPush));
    }else{
        throw std::invalid_argument("EXCEPTION: invalid id got passed (by the machine!) to PARG");
    }
}

void VM::MACHINE::DELEGATES::PARG::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                       VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to PARG");
}

void
VM::MACHINE::DELEGATES::PARG::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                  VM::TYPES::Reference &c) {
    throw std::invalid_argument("EXCEPTION: 3 Arguments got passed (by the machine!) to PARG");
}

void VM::MACHINE::DELEGATES::ARG::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to ARG");
}

void VM::MACHINE::DELEGATES::ARG::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to ARG");
}

void VM::MACHINE::DELEGATES::ARG::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                      VM::TYPES::Reference &b) {
    TYPES::Reference* dst;
    std::uint32_t dstId = *(reinterpret_cast<std::uint32_t*>(a.m_content.get()));
    std::uint32_t srcIndex = *(reinterpret_cast<std::uint32_t*>(b.m_content.get()));
    bool foundDst = false;
    for(auto& ref : stackframe.m_references){
        if(ref.m_id == dstId){
            dst = &ref;
            foundDst = true;
            break;
        }
    }
    if(foundDst){
        if(stackframe.m_arguments[srcIndex].m_type == dst->m_type) {
            std::uint8_t type = dst->m_type;
            *(dst) = TYPES::Reference(stackframe.m_arguments[srcIndex]);
            (*(dst)).m_id = dstId;
            (*(dst)).m_type = type;
        }else{
            throw std::invalid_argument("EXCEPTION: Source and destination have different types (ARG)");
        }
    }else{
        throw std::invalid_argument("EXCEPTION: invalid Argument got passed (by the machine!) to ARG(argument not found)");
    }
}

void
VM::MACHINE::DELEGATES::ARG::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                 VM::TYPES::Reference &c) {
    throw std::invalid_argument("EXCEPTION: 3 Arguments got passed (by the machine!) to ARG");
}

void VM::MACHINE::DELEGATES::FST::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to FST");
}

void VM::MACHINE::DELEGATES::FST::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {

}

void VM::MACHINE::DELEGATES::FST::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                      VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to FST");
}

void
VM::MACHINE::DELEGATES::FST::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                 VM::TYPES::Reference &c) {
    throw std::invalid_argument("EXCEPTION: 3 Arguments got passed (by the machine!) to FST");
}

void VM::MACHINE::DELEGATES::FEN::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to FEN");
}

void VM::MACHINE::DELEGATES::FEN::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {

}

void VM::MACHINE::DELEGATES::FEN::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                      VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to FEN");
}

void
VM::MACHINE::DELEGATES::FEN::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                 VM::TYPES::Reference &c) {
    throw std::invalid_argument("EXCEPTION: 3 Arguments got passed (by the machine!) to FEN");
}

void VM::MACHINE::DELEGATES::REFA::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to REFA");
}

void VM::MACHINE::DELEGATES::REFA::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to REFA");
}

void VM::MACHINE::DELEGATES::REFA::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                       VM::TYPES::Reference &b) {
    std::uint32_t id = *(reinterpret_cast<std::uint32_t*>(a.m_content.get()));
    std::uint32_t type = *(reinterpret_cast<std::uint32_t*>(b.m_content.get()));

    bool boolVal = true;
    std::uint8_t byteVal = 1;
    std::uint32_t uintVal = 1;
    std::uint64_t uLongVal = 1;
    std::int32_t intVal = 1;
    std::int64_t longVal = 1;
    long double ldVal = 1.0;
    switch(type){
        case 0x0:
            stackframe.m_references.push_back(TYPES::Reference(boolVal, 1,id));
            break;
        case 0x1:
            stackframe.m_references.push_back(TYPES::Reference(byteVal, 1,id));
            break;
        case 0x2:
            stackframe.m_references.push_back(TYPES::Reference(uintVal, 1,id));
            break;
        case 0x3:
            stackframe.m_references.push_back(TYPES::Reference(uLongVal, 1,id));
            break;
        case 0x4:
            stackframe.m_references.push_back(TYPES::Reference(intVal, 1,id));
            break;
        case 0x5:
            stackframe.m_references.push_back(TYPES::Reference(longVal, 1,id));
            break;
        case 0x6:
            stackframe.m_references.push_back(TYPES::Reference(ldVal, 1,id));
            break;
        default:
            throw std::invalid_argument("EXCEPTION: called REFA with invalid type.");
    }
}

void
VM::MACHINE::DELEGATES::REFA::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                  VM::TYPES::Reference &c) {
    std::uint32_t id = *(reinterpret_cast<std::uint32_t*>(a.m_content.get()));
    std::uint8_t type = *(reinterpret_cast<std::uint8_t*>(b.m_content.get()));
    std::uint64_t size = *(reinterpret_cast<std::uint64_t*>(c.m_content.get()));

    bool boolVal = true;
    std::uint8_t byteVal = 1;
    std::uint32_t uintVal = 1;
    std::uint64_t uLongVal = 1;
    std::uint32_t intVal = 1;
    std::uint64_t longVal = 1;
    long double ldVal = 1.0;
    switch(type){
        case 0x0:
            stackframe.m_references.push_back(TYPES::Reference(boolVal, size,id));

            break;
        case 0x1:
            stackframe.m_references.push_back(TYPES::Reference(byteVal, size,id));
            break;
        case 0x2:
            stackframe.m_references.push_back(TYPES::Reference(uintVal, size,id));
            break;
        case 0x3:
            stackframe.m_references.push_back(TYPES::Reference(uLongVal, size,id));
            break;
        case 0x4:
            stackframe.m_references.push_back(TYPES::Reference(intVal, size,id));
            break;
        case 0x5:
            stackframe.m_references.push_back(TYPES::Reference(longVal, size,id));
            break;
        case 0x6:
            stackframe.m_references.push_back(TYPES::Reference(ldVal, size,id));
            break;
        default:
            throw std::invalid_argument("EXCEPTION: called REFA with invalid type.");
    }
}

void VM::MACHINE::DELEGATES::REFF::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to REFF");
}

void VM::MACHINE::DELEGATES::REFF::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    std::uint32_t idToRemove = *(reinterpret_cast<std::uint32_t*>(a.m_content.get()));
    bool removedElement = false;
    for(std::size_t i = 0; i < stackframe.m_references.size(); i++){
        if(stackframe.m_references[i].m_id == idToRemove){
            stackframe.m_references.erase(stackframe.m_references.begin() + i);
            removedElement = true;
            break;
        }
    }
    if(!removedElement){
        throw std::invalid_argument("EXCEPTION: invalid id got passed (by the machine!) to REFF");
    }
}

void VM::MACHINE::DELEGATES::REFF::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                       VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to REFF");
}

void
VM::MACHINE::DELEGATES::REFF::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                  VM::TYPES::Reference &c) {
    throw std::invalid_argument("EXCEPTION: 3 Arguments got passed (by the machine!) to REFF");
}

void VM::MACHINE::DELEGATES::MOV::run(VM::MACHINE::Stackframe &stackframe) {

}

void VM::MACHINE::DELEGATES::MOV::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {

}

void VM::MACHINE::DELEGATES::MOV::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                      VM::TYPES::Reference &b) {

}

void
VM::MACHINE::DELEGATES::MOV::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                 VM::TYPES::Reference &c) {

}

void VM::MACHINE::DELEGATES::SET::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to SET");
}

void VM::MACHINE::DELEGATES::SET::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to SET");
}

void VM::MACHINE::DELEGATES::SET::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                      VM::TYPES::Reference &b) {
    TYPES::Reference* refToSet;
    std::uint32_t idToSet = *(reinterpret_cast<std::uint32_t*>(a.m_content.get()));
    bool foundId = false;
    for(auto & m_reference : stackframe.m_references){
        if(m_reference.m_id == idToSet){
            refToSet = &m_reference;
            foundId = true;
            break;
        }
    }
    if(foundId){
        bool boolVal = true;
        std::uint8_t byteVal = 1;
        std::uint32_t uintVal = 1;
        std::uint64_t uLongVal = 1;
        std::uint32_t intVal = 1;
        std::uint64_t longVal = 1;
        long double ldVal = 1.0;
        switch(refToSet->m_type) {
            case 0x0:
                if(*(reinterpret_cast<std::uint64_t *>(b.m_content.get())) != 1l){
                    boolVal = false;
                }
                std::memcpy(refToSet->m_content.get(), &boolVal, BOOL_LENGTH);
                break;
            case 0x1:
                byteVal = *(reinterpret_cast<std::uint8_t *>(b.m_content.get()));
                std::memcpy(refToSet->m_content.get(), &byteVal, BYTE_LENGTH);
                break;
            case 0x2:
                uintVal = *(reinterpret_cast<std::uint32_t *>(b.m_content.get()));
                std::memcpy(refToSet->m_content.get(), &uintVal, INT_LENGTH);
                break;
            case 0x3:
                uLongVal = *(reinterpret_cast<std::uint64_t *>(b.m_content.get()));
                std::memcpy(refToSet->m_content.get(), &uLongVal, LONG_LENGTH);
                break;
            case 0x4:
                intVal = *(reinterpret_cast<std::int32_t *>(b.m_content.get()));
                std::memcpy(refToSet->m_content.get(), &intVal, INT_LENGTH);
                break;
            case 0x5:
                longVal = *(reinterpret_cast<std::int64_t *>(b.m_content.get()));
                std::memcpy(refToSet->m_content.get(), &longVal, LONG_LENGTH);
                break;
            case 0x6:
                ldVal = *(reinterpret_cast<long double *>(b.m_content.get()));
                std::memcpy(refToSet->m_content.get(), &ldVal, DEC_LENGTH);
                break;
            default:
                throw std::invalid_argument("EXCEPTION: invalid Reference got passed (by the machine!) to SET.");
        }
    }else{
        throw std::invalid_argument("EXCEPTION: Invalid Reference got passed (by the machine!) to SET");
    }
}

void
VM::MACHINE::DELEGATES::SET::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                 VM::TYPES::Reference &c) {
    throw std::invalid_argument("EXCEPTION: 3 Arguments got passed (by the machine!) to SET");
}

void VM::MACHINE::DELEGATES::ASET::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to ASET");
}

void VM::MACHINE::DELEGATES::ASET::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to ASET");
}

void VM::MACHINE::DELEGATES::ASET::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                       VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to ASET");
}

void
VM::MACHINE::DELEGATES::ASET::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                  VM::TYPES::Reference &c) {
    TYPES::Reference* refToSet;
    std::uint64_t indexToSet = *(reinterpret_cast<std::uint64_t*>(c.m_content.get()));
    std::uint32_t idToSet = *(reinterpret_cast<std::uint32_t*>(a.m_content.get()));
    bool foundId = false;
    for(auto & m_reference : stackframe.m_references){
        if(m_reference.m_id == idToSet){
            refToSet = &m_reference;
            foundId = true;
            break;
        }
    }
    if(foundId){
        if(indexToSet <= refToSet->m_size){
            throw std::invalid_argument("EXCEPTION: Array index out of bounds (ASET).");
        }
        bool boolVal = true;
        std::uint8_t byteVal = 1;
        std::uint32_t uintVal = 1;
        std::uint64_t uLongVal = 1;
        std::uint32_t intVal = 1;
        std::uint64_t longVal = 1;
        long double ldVal = 1.0;
        switch(refToSet->m_type) {
            case 0x0:
                if(*(reinterpret_cast<std::uint64_t *>(b.m_content.get())) != 1l){
                    boolVal = false;
                }
                std::memcpy(((bool*)(refToSet->m_content.get()))+indexToSet, &boolVal, BOOL_LENGTH);
                break;
            case 0x1:
                byteVal = *(reinterpret_cast<std::uint8_t *>(b.m_content.get()));
                std::memcpy(((std::uint8_t*)(refToSet->m_content.get()))+indexToSet, &byteVal, BYTE_LENGTH);
                break;
            case 0x2:
                uintVal = *(reinterpret_cast<std::uint32_t *>(b.m_content.get()));
                std::memcpy(((std::uint32_t*)(refToSet->m_content.get()))+indexToSet, &uintVal, INT_LENGTH);
                break;
            case 0x3:
                uLongVal = *(reinterpret_cast<std::uint64_t *>(b.m_content.get()));
                std::memcpy(((std::uint64_t*)(refToSet->m_content.get()))+indexToSet, &uLongVal, LONG_LENGTH);
                break;
            case 0x4:
                intVal = *(reinterpret_cast<std::int32_t *>(b.m_content.get()));
                std::memcpy(((std::int32_t*)(refToSet->m_content.get()))+indexToSet, &intVal, INT_LENGTH);
                break;
            case 0x5:
                longVal = *(reinterpret_cast<std::int64_t *>(b.m_content.get()));
                std::memcpy(((std::int64_t*)(refToSet->m_content.get()))+indexToSet, &longVal, LONG_LENGTH);
                break;
            case 0x6:
                ldVal = *(reinterpret_cast<long double *>(b.m_content.get()));
                std::memcpy(((long double*)(refToSet->m_content.get()))+indexToSet, &ldVal, DEC_LENGTH);
                break;
            default:
                throw std::invalid_argument("EXCEPTION: invalid Reference got passed (by the machine!) to ASET.");
        }
    }else{
        throw std::invalid_argument("EXCEPTION: Invalid Reference got passed (by the machine!) to ASET");
    }
}

void VM::MACHINE::DELEGATES::AGET::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to AGET");
}

void VM::MACHINE::DELEGATES::AGET::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to AGET");
}

void VM::MACHINE::DELEGATES::AGET::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                       VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to AGET");
}

void
VM::MACHINE::DELEGATES::AGET::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                  VM::TYPES::Reference &c) {
    TYPES::Reference* dst;
    TYPES::Reference* src;
    std::uint32_t
            dstId = *(reinterpret_cast<std::uint32_t*>(a.m_content.get())),
            srcId = *(reinterpret_cast<std::uint32_t*>(b.m_content.get()));

    std::uint64_t srcIndex = *(reinterpret_cast<std::uint64_t*>(c.m_content.get()));
    bool
            foundDst = false,
            foundSrc = false;
    for(auto& ref : stackframe.m_references){
        if(!foundDst && ref.m_id == dstId){
            dst = &ref;
            foundDst = true;
        }
        if(!foundSrc && ref.m_id == srcId){
            src = &ref;
            foundSrc = true;
        }
        if(foundSrc && foundDst){
            break;
        }
    }
    int typeSizes[7];
    typeSizes[0] = BOOL_LENGTH;
    typeSizes[1] = BYTE_LENGTH;
    typeSizes[2] = INT_LENGTH;
    typeSizes[3] = LONG_LENGTH;
    typeSizes[4] = INT_LENGTH;
    typeSizes[5] = LONG_LENGTH;
    typeSizes[6] = DEC_LENGTH;
    std::memcpy(dst->m_content.get(), src->m_content.get(), typeSizes[dst->m_type]);
    switch(dst->m_type){
        case 0:
            std::memcpy(dst->m_content.get(), ((bool*)(src->m_content.get()))+srcIndex, typeSizes[dst->m_type]);
            break;
        case 1:
            std::memcpy(dst->m_content.get(), ((std::uint8_t*)(src->m_content.get()))+srcIndex, typeSizes[dst->m_type]);
            break;
        case 2:
            std::memcpy(dst->m_content.get(), ((std::uint32_t*)(src->m_content.get()))+srcIndex, typeSizes[dst->m_type]);
            break;
        case 3:
            std::memcpy(dst->m_content.get(), ((std::uint64_t*)(src->m_content.get()))+srcIndex, typeSizes[dst->m_type]);
            break;
        case 4:
            std::memcpy(dst->m_content.get(), ((std::int32_t*)(src->m_content.get()))+srcIndex, typeSizes[dst->m_type]);
            break;
        case 5:
            std::memcpy(dst->m_content.get(), ((std::int64_t*)(src->m_content.get()))+srcIndex, typeSizes[dst->m_type]);
            break;
        case 6:
            std::memcpy(dst->m_content.get(), ((long double*)(src->m_content.get()))+srcIndex, typeSizes[dst->m_type]);
            break;
    }

}

void VM::MACHINE::DELEGATES::CPY::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to CPY");
}

void VM::MACHINE::DELEGATES::CPY::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to CPY");
}

void VM::MACHINE::DELEGATES::CPY::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                      VM::TYPES::Reference &b) {
    TYPES::Reference* dst;
    TYPES::Reference* src;
    std::uint32_t
        dstId = *(reinterpret_cast<std::uint32_t*>(a.m_content.get())),
        srcId = *(reinterpret_cast<std::uint32_t*>(b.m_content.get()));
    bool
        foundDst = false,
        foundSrc = false;
    for(auto& ref : stackframe.m_references){
        if(!foundDst && ref.m_id == dstId){
            dst = &ref;
            foundDst = true;
        }
        if(!foundSrc && ref.m_id == srcId){
            src = &ref;
            foundSrc = true;
        }
        if(foundSrc && foundDst){
            break;
        }
    }
    int typeSizes[7];
    typeSizes[0] = BOOL_LENGTH;
    typeSizes[1] = BYTE_LENGTH;
    typeSizes[2] = INT_LENGTH;
    typeSizes[3] = LONG_LENGTH;
    typeSizes[4] = INT_LENGTH;
    typeSizes[5] = LONG_LENGTH;
    typeSizes[6] = DEC_LENGTH;
    std::memcpy(dst->m_content.get(), src->m_content.get(), typeSizes[dst->m_type]);
}

void
VM::MACHINE::DELEGATES::CPY::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                 VM::TYPES::Reference &c) {
    throw std::invalid_argument("EXCEPTION: 3 Arguments got passed (by the machine!) to CPY");
}

void VM::MACHINE::DELEGATES::PRINT::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to PRINT");
}

void VM::MACHINE::DELEGATES::PRINT::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    TYPES::Reference* refToPrint;
    std::uint32_t idToPrint = *(reinterpret_cast<std::uint32_t*>(a.m_content.get()));
    bool foundId = false;
    for(auto & m_reference : stackframe.m_references){
        if(m_reference.m_id == idToPrint){
            refToPrint = &m_reference;
            foundId = true;
            break;
        }
    }
    if(!foundId){
        throw std::invalid_argument("EXCEPTION: invalid id got passed (by the machine!) to PRINT");
    }
    switch(refToPrint->m_type){
        case 0x0:
            if(*(reinterpret_cast<bool*>(refToPrint->m_content.get()))){
                std::cout << "true";
            }else{
                std::cout << "false";
            }
            break;
        case 0x1:
            std::cout << *(reinterpret_cast<unsigned char*>(refToPrint->m_content.get()));
            break;
        case 0x2:
            std::cout << *(reinterpret_cast<std::uint32_t *>(refToPrint->m_content.get()));
            break;
        case 0x3:
            std::cout << *(reinterpret_cast<std::uint64_t *>(refToPrint->m_content.get()));
            break;
        case 0x4:
            std::cout << *(reinterpret_cast<std::int32_t *>(refToPrint->m_content.get()));
            break;
        case 0x5:
            std::cout << *(reinterpret_cast<std::int64_t *>(refToPrint->m_content.get()));
            break;
        case 0x6:
            std::cout << *(reinterpret_cast<long double *>(refToPrint->m_content.get()));
            break;
        default:
            throw std::invalid_argument("EXCEPTION: invalid Reference got passed (by the machine!) to PRINT.");
    }
}

void VM::MACHINE::DELEGATES::PRINT::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                        VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to PRINT");
}

void VM::MACHINE::DELEGATES::PRINT::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                        VM::TYPES::Reference &b, VM::TYPES::Reference &c) {
    throw std::invalid_argument("EXCEPTION: 3 Arguments got passed (by the machine!) to PRINT");
}

void VM::MACHINE::DELEGATES::BRANCH::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to BRANCH");
}

void VM::MACHINE::DELEGATES::BRANCH::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to BRANCH");
}

void VM::MACHINE::DELEGATES::BRANCH::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                         VM::TYPES::Reference &b) {

    std::uint32_t labelId = *(reinterpret_cast<std::uint32_t*>(a.m_content.get()));
    std::uint32_t newPc = - 1;
    TYPES::Reference* boolRef;
    bool foundBoolRef = false;

    for(auto& ref : stackframe.m_references){
        if(*(reinterpret_cast<std::uint32_t*>(b.m_content.get())) == ref.m_id){
            boolRef = &ref;
            foundBoolRef = true;
            break;
        }
    }
    for(auto& pair : stackframe.m_labels){
        if(pair.first == labelId){
            newPc = pair.second;
            break;
        }
    }
    if(*(reinterpret_cast<bool*>(boolRef->m_content.get()))){
        stackframe.m_programCounter = newPc;
    }
    //std::cout << (std::uint32_t)stackframe.m_function.m_commands[stackframe.m_programCounter].m_opCode << "\n";
}

void VM::MACHINE::DELEGATES::BRANCH::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                         VM::TYPES::Reference &b, VM::TYPES::Reference &c) {
    throw std::invalid_argument("EXCEPTION: 3 Arguments got passed (by the machine!) to BRANCH");
}

void VM::MACHINE::DELEGATES::LABEL::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to LABEL");
}

void VM::MACHINE::DELEGATES::LABEL::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    std::pair<std::uint32_t, std::uint32_t> result;
    result.first = *(reinterpret_cast<std::uint32_t*>(a.m_content.get()));
    result.second = stackframe.m_programCounter;
    stackframe.m_labels.push_back(result);
}

void VM::MACHINE::DELEGATES::LABEL::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                        VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to LABEL");
}

void VM::MACHINE::DELEGATES::LABEL::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                        VM::TYPES::Reference &b, VM::TYPES::Reference &c) {
    throw std::invalid_argument("EXCEPTION: 3 Arguments got passed (by the machine!) to LABEL");
}

void VM::MACHINE::DELEGATES::MAIN::run(VM::MACHINE::Stackframe &stackframe) {

}

void VM::MACHINE::DELEGATES::MAIN::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to MAIN");
}

void VM::MACHINE::DELEGATES::MAIN::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                       VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to MAIN");
}

void
VM::MACHINE::DELEGATES::MAIN::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                  VM::TYPES::Reference &c) {
    throw std::invalid_argument("EXCEPTION: 3 Arguments got passed (by the machine!) to MAIN");
}

void VM::MACHINE::DELEGATES::MEND::run(VM::MACHINE::Stackframe &stackframe) {

}

void VM::MACHINE::DELEGATES::MEND::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to MEND");
}

void VM::MACHINE::DELEGATES::MEND::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                       VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to MEND");
}

void
VM::MACHINE::DELEGATES::MEND::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                  VM::TYPES::Reference &c) {
    throw std::invalid_argument("EXCEPTION: 3 Arguments got passed (by the machine!) to MEND");
}

void VM::MACHINE::DELEGATES::NOOP::run(VM::MACHINE::Stackframe &stackframe) {

}

void VM::MACHINE::DELEGATES::NOOP::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    throw std::invalid_argument("EXCEPTION: 1 Argument got passed (by the machine!) to NOOP");
}

void VM::MACHINE::DELEGATES::NOOP::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                       VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to NOOP");
}

void
VM::MACHINE::DELEGATES::NOOP::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                  VM::TYPES::Reference &c) {
    throw std::invalid_argument("EXCEPTION: 3 Arguments got passed (by the machine!) to NOOP");
}

void VM::MACHINE::DELEGATES::RETG::run(VM::MACHINE::Stackframe &stackframe) {
    throw std::invalid_argument("EXCEPTION: 0 Arguments got passed (by the machine!) to RETG");
}

void VM::MACHINE::DELEGATES::RETG::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a) {
    TYPES::Reference* dst;
    bool foundRef = false;
    std::uint32_t dstId = *(reinterpret_cast<std::uint32_t*>(a.m_content.get()));
    for(auto& ref : stackframe.m_references){
        if(ref.m_id == dstId){
            dst = &ref;
            foundRef = true;
            break;
        }
    }
    if(foundRef){
        bool boolValue = false;
        std::uint8_t byteValue = 0;
        std::uint32_t uintValue = 0;
        std::uint64_t ulongValue = 0;
        std::int32_t intValue = 0;
        std::int64_t longValue = 0;
        long double ldValue = 0;

        if(dst->m_type == stackframe.m_executor->m_returnRegister.m_type){
            switch(dst->m_type){
                case 0:
                    if(*(reinterpret_cast<bool*>(stackframe.m_executor->m_returnRegister.m_content.get()))){
                        boolValue = true;
                    }
                    std::memcpy (dst->m_content.get(), &boolValue, BOOL_LENGTH);
                    break;
                case 1:
                    byteValue = *(reinterpret_cast<std::uint8_t*>(stackframe.m_executor->m_returnRegister.m_content.get()));
                    std::memcpy (dst->m_content.get(), &byteValue, BYTE_LENGTH);
                    break;
                case 2:
                    uintValue = *(reinterpret_cast<std::uint32_t*>(stackframe.m_executor->m_returnRegister.m_content.get()));
                    std::memcpy (dst->m_content.get(), &uintValue, INT_LENGTH);
                    break;
                case 3:
                    ulongValue = *(reinterpret_cast<std::uint64_t*>(stackframe.m_executor->m_returnRegister.m_content.get()));
                    std::memcpy (dst->m_content.get(), &ulongValue, LONG_LENGTH);
                    break;
                case 4:
                    intValue = *(reinterpret_cast<std::int32_t*>(stackframe.m_executor->m_returnRegister.m_content.get()));
                    std::memcpy (dst->m_content.get(), &uintValue, INT_LENGTH);
                    break;
                case 5:
                    longValue = *(reinterpret_cast<std::int64_t*>(stackframe.m_executor->m_returnRegister.m_content.get()));
                    std::memcpy (dst->m_content.get(), &longValue, LONG_LENGTH);
                    break;
                case 6:
                    ldValue = *(reinterpret_cast<long double*>(stackframe.m_executor->m_returnRegister.m_content.get()));
                    std::memcpy (dst->m_content.get(), &ldValue, DEC_LENGTH);
                    break;
            }
        }else{
            throw std::invalid_argument("EXCEPTION: type in return register doesnt match first argument to (RETG)");
        }
    }else{
        throw std::invalid_argument("EXCEPTION: invalid first argument got passed (by the machine!) to RETG");
    }
}

void VM::MACHINE::DELEGATES::RETG::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a,
                                       VM::TYPES::Reference &b) {
    throw std::invalid_argument("EXCEPTION: 2 Arguments got passed (by the machine!) to RETG");
}

void
VM::MACHINE::DELEGATES::RETG::run(VM::MACHINE::Stackframe &stackframe, VM::TYPES::Reference &a, VM::TYPES::Reference &b,
                                  VM::TYPES::Reference &c) {
    throw std::invalid_argument("EXCEPTION: 3 Arguments got passed (by the machine!) to RETG");
}
