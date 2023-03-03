//
// Created by Robin on 01.03.2023.
//


#include <cstring>
#include "Reference.h"



VM::TYPES::Reference::~Reference() {
    /*
    switch(this->m_type){
        case 0x0:
            this->m_content = reinterpret_cast<bool*>(this->m_content);
            break;
        case 0x1:
            this->m_content = reinterpret_cast<std::uint8_t*>(this->m_content);
            break;
        case 0x2:
            this->m_content = reinterpret_cast<std::uint32_t*>(this->m_content);
            break;
        case 0x3:
            this->m_content = reinterpret_cast<std::uint64_t*>(this->m_content);
            break;
        case 0x4:
            this->m_content = reinterpret_cast<std::int32_t*>(this->m_content);
            break;
        case 0x5:
            this->m_content = reinterpret_cast<std::int64_t*>(this->m_content);
            break;
        case 0x6:
            this->m_content = reinterpret_cast<long double*>(this->m_content);
            break;
    }
    */

}

VM::TYPES::Reference::Reference(const VM::TYPES::Reference &toCopy) {
    this->m_id = toCopy.m_id;
    this->m_size = toCopy.m_size;
    this->m_type = toCopy.m_type;
    this->m_content = toCopy.m_content;
}

VM::TYPES::Reference::Reference(bool value, std::uint64_t size, std::uint32_t id) {
    this->m_id = id;
    this->m_size = size;
    this->m_type = 0x0;
    this->m_content = std::make_shared<void*>(malloc(sizeof(bool) * size));
    std::memcpy(this->m_content.get(), &value, m_size);
}

VM::TYPES::Reference::Reference(std::uint8_t value, std::uint64_t size, std::uint32_t id) {
    this->m_id = id;
    this->m_size = size;
    this->m_type = 0x1;
    this->m_content = std::make_shared<void*>(malloc(sizeof(std::uint8_t) * size));
    std::memcpy(this->m_content.get(), &value, m_size);
}
VM::TYPES::Reference::Reference(std::uint32_t value, std::uint64_t size, std::uint32_t id) {
    this->m_id = id;
    this->m_size = size;
    this->m_type = 0x2;
    this->m_content = std::make_shared<void*>(malloc(sizeof(std::uint32_t) * size));
    std::memcpy(this->m_content.get(), &value, sizeof(std::uint32_t) * size);
}
VM::TYPES::Reference::Reference(std::uint64_t value, std::uint64_t size, std::uint32_t id) {
    this->m_id = id;
    this->m_size = size;
    this->m_type = 0x3;
    this->m_content = std::make_shared<void*>(malloc(sizeof(std::uint64_t) * size));
    std::memcpy(this->m_content.get(), &value, sizeof(std::uint64_t) * size);
}

VM::TYPES::Reference::Reference(std::int32_t value, std::uint64_t size, std::uint32_t id) {
    this->m_id = id;
    this->m_size = size;
    this->m_type = 0x4;
    this->m_content = std::make_shared<void*>(malloc(sizeof(std::int32_t) * size));
    std::memcpy(this->m_content.get(), &value, sizeof(std::int32_t) * size);
}
VM::TYPES::Reference::Reference(std::int64_t value, std::uint64_t size, std::uint32_t id) {
    this->m_id = id;
    this->m_size = size;
    this->m_type = 0x5;
    this->m_content = std::make_shared<void*>(malloc(sizeof(std::int64_t) * size));
    std::memcpy(this->m_content.get(), &value, sizeof(std::int64_t) * size);
}

VM::TYPES::Reference::Reference(long double value, std::uint64_t size, std::uint32_t id) {
    this->m_id = id;
    this->m_size = size;
    this->m_type = 0x6;
    this->m_content = std::make_shared<void*>(malloc(sizeof(long double) * size));
    std::memcpy(this->m_content.get(), &value, sizeof(long double) * size);
}

VM::TYPES::Reference::Reference() {
    this->m_type = 255;
    this->m_content = std::make_shared<void*>(malloc(sizeof(int)));
}





