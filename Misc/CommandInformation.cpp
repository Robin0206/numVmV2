//
// Created by robin on 01.03.23.
//

#include "CommandInformation.h"
#include "ConstMakr.h"

namespace VM::MISC {
        CommandInformation::CommandInformation() {
            //memory
            m_names[0]  = "NOOP";
            m_names[1]  = "REFA";//-
            m_names[2]  = "REFA";//-
            m_names[3]  = "MOV";
            m_names[4]  = "SET";//-
            m_names[5]  = "ASET";
            m_names[6]  = "AGET";
            m_names[7]  = "CPY";
            //arithmetic ___
            m_names[8]  = "ADD";//-
            m_names[9]  = "SUB";//-
            m_names[10] = "MUL";//-
            m_names[11] = "DIV";//-
            //binary__
            m_names[12] = "OR";//-
            m_names[13] = "AND";//-
            m_names[14] = "XOR";//-
            m_names[15] = "NOT";//-
            m_names[16] = "EQ";//-
            //logical__
            m_names[17] = "LSS";//-
            m_names[18] = "GRT";//-
            m_names[19] = "LSE";//-
            m_names[20] = "GRE";//-
            //system/functions
            m_names[21] = "PRINT";//-
            m_names[22] = "RET";//-
            m_names[23] = "CALL";//-
            m_names[24] = "PARG";
            m_names[25] = "BRANCH";
            m_names[26] = "LABEL";
            m_names[27] = "REFF";//-
            m_names[28] = "FST";//-
            m_names[29] = "FEN";//-
            m_names[30] = "ARG";
            m_names[31] = "MAIN";//-
            m_names[32] = "MEND";//-

            m_argLengths[0] = std::vector<std::uint8_t>{};//NOOP
            m_argLengths[1] = std::vector<std::uint8_t>{4,4};//REFA
            m_argLengths[2] = std::vector<std::uint8_t>{4,4,8};//REFA
            m_argLengths[3] = std::vector<std::uint8_t>{4,4};//MOV
            m_argLengths[4] = std::vector<std::uint8_t>{4,8};//SET
            m_argLengths[5] = std::vector<std::uint8_t>{4,4,8};//ASET
            m_argLengths[6] = std::vector<std::uint8_t>{4,4,8};//AGET
            m_argLengths[7] = std::vector<std::uint8_t>{4,4};//CPY
            m_argLengths[8] = std::vector<std::uint8_t>{4,4,4};//ADD
            m_argLengths[9] = std::vector<std::uint8_t>{4,4,4};//SUB
            m_argLengths[10] = std::vector<std::uint8_t>{4,4,4};//MUL
            m_argLengths[11] = std::vector<std::uint8_t>{4,4,4};//DIV
            m_argLengths[12] = std::vector<std::uint8_t>{4,4,4};//OR
            m_argLengths[13] = std::vector<std::uint8_t>{4,4,4};//AND
            m_argLengths[14] = std::vector<std::uint8_t>{4,4,4};//XOR
            m_argLengths[15] = std::vector<std::uint8_t>{4,4};//NOT
            m_argLengths[16] = std::vector<std::uint8_t>{4,4,4};//EQ
            m_argLengths[17] = std::vector<std::uint8_t>{4,4,4};//LSS
            m_argLengths[18] = std::vector<std::uint8_t>{4,4,4};//GRT
            m_argLengths[19] = std::vector<std::uint8_t>{4,4,4};//LSE
            m_argLengths[20] = std::vector<std::uint8_t>{4,4,4};//GRE
            m_argLengths[21] = std::vector<std::uint8_t>{4};//PRINT
            m_argLengths[22] = std::vector<std::uint8_t>{4};//RET
            m_argLengths[23] = std::vector<std::uint8_t>{4};//CALL
            m_argLengths[24] = std::vector<std::uint8_t>{4};//PARG
            m_argLengths[25] = std::vector<std::uint8_t>{4,4};//BRANCH
            m_argLengths[26] = std::vector<std::uint8_t>{4};//LABEL
            m_argLengths[27] = std::vector<std::uint8_t>{4};//REFF
            m_argLengths[28] = std::vector<std::uint8_t>{4};//FST
            m_argLengths[29] = std::vector<std::uint8_t>{4};//FEN
            m_argLengths[30] = std::vector<std::uint8_t>{4};//ARG
            m_argLengths[31] = std::vector<std::uint8_t>{};//MAIN
            m_argLengths[32] = std::vector<std::uint8_t>{};//MEND
        }
    } // MISC