//
// Created by Robin on 01.03.2023.
//

#include "Reference.h"



VM::TYPES::Reference::~Reference() {
    delete [] m_content;
}

VM::TYPES::Reference::Reference(bool value, std::uint64_t size) {
    this->m_size = size;
    this->m_type = 0x0;
    this->m_content = new bool[size];
}

VM::TYPES::Reference::Reference(std::uint8_t value, std::uint64_t size) {
    this->m_size = size;
    this->m_type = 0x1;
    this->m_content = new std::uint8_t[size];
}
VM::TYPES::Reference::Reference(std::uint32_t value, std::uint64_t size) {
    this->m_size = size;
    this->m_type = 0x2;
    this->m_content = new std::uint32_t[size];
}
VM::TYPES::Reference::Reference(std::uint64_t value, std::uint64_t size) {
    this->m_size = size;
    this->m_type = 0x3;
    this->m_content = new std::uint64_t[size];
}

VM::TYPES::Reference::Reference(std::int32_t value, std::uint64_t size) {
    this->m_size = size;
    this->m_type = 0x4;
    this->m_content = new std::int32_t[size];
}
VM::TYPES::Reference::Reference(std::int64_t value, std::uint64_t size) {
    this->m_size = size;
    this->m_type = 0x5;
    this->m_content = new std::int64_t[size];
}

VM::TYPES::Reference::Reference(long double value, std::uint64_t size) {
    this->m_size = size;
    this->m_type = 0x6;
    this->m_content = new long double[size];
}



