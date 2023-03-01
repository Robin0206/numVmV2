//
// Created by robin on 01.03.23.
//

#ifndef NUMVMV2_READINGMODULE_H
#define NUMVMV2_READINGMODULE_H

#include <string>
#include <vector>
#include "../Misc/ConstMakr.h"
#include <fstream>

namespace VM::READING{

    class ReadingModule {
        const std::string m_path;
        std::vector<BYTE> m_rawProgram;
    public:
        explicit ReadingModule(const std::string& path);
        void run();
        std::vector<BYTE>& getRawProgram();
    };
}



#endif //NUMVMV2_READINGMODULE_H
