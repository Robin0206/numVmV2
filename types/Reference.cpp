//
// Created by Robin on 01.03.2023.
//


#include <cstring>
#include "Reference.h"


VM::TYPES::Reference::Reference(const VM::TYPES::Reference &toCopy) {
    this->m_id = toCopy.m_id;
    this->m_size = toCopy.m_size;
    this->m_type = toCopy.m_type;
    this->m_content = toCopy.m_content;
    this->m_arrContent = toCopy.m_arrContent;
}

VM::TYPES::Reference::Reference(bool value, std::uint64_t size, std::uint32_t id) {
    this->m_id = id;
    this->m_size = size;
    this->m_type = 0x0;
    if(size == 1) {
        this->m_content = std::make_shared<void *>(malloc(sizeof(bool)));
        std::memcpy(this->m_content.get(), &value, sizeof(bool));
    }else{
        this->m_arrContent.resize(size);
    }
}

VM::TYPES::Reference::Reference(std::uint8_t value, std::uint64_t size, std::uint32_t id) {
    this->m_id = id;
    this->m_size = size;
    this->m_type = 0x1;
    if(size == 1) {
        this->m_content = std::make_shared<void *>(malloc(sizeof(std::uint8_t)));
        std::memcpy(this->m_content.get(), &value, sizeof(std::uint8_t));
    }else{
        this->m_arrContent.resize(size);
    }
}
VM::TYPES::Reference::Reference(std::uint32_t value, std::uint64_t size, std::uint32_t id) {
    this->m_id = id;
    this->m_size = size;
    this->m_type = 0x2;
    if(size == 1) {
        this->m_content = std::make_shared<void *>(malloc(sizeof(std::uint32_t)));
        std::memcpy(this->m_content.get(), &value, sizeof(std::uint32_t));
    }else{
        this->m_arrContent.resize(size);
    }
}
VM::TYPES::Reference::Reference(std::uint64_t value, std::uint64_t size, std::uint32_t id) {
    this->m_id = id;
    this->m_size = size;
    this->m_type = 0x3;
    if(size == 1) {
        this->m_content = std::make_shared<void *>(malloc(sizeof(std::uint64_t)));
        std::memcpy(this->m_content.get(), &value, sizeof(std::uint64_t));
    }else{
        this->m_arrContent.resize(size);
    }
}

VM::TYPES::Reference::Reference(std::int32_t value, std::uint64_t size, std::uint32_t id) {
    this->m_id = id;
    this->m_size = size;
    this->m_type = 0x4;
    if(size == 1) {
        this->m_content = std::make_shared<void *>(malloc(sizeof(std::int32_t)));
        std::memcpy(this->m_content.get(), &value, sizeof(std::int32_t));
    }else{
        this->m_arrContent.resize(size);
    }
}
VM::TYPES::Reference::Reference(std::int64_t value, std::uint64_t size, std::uint32_t id) {
    this->m_id = id;
    this->m_size = size;
    this->m_type = 0x5;
    if(size == 1) {
        this->m_content = std::make_shared<void *>(malloc(sizeof(std::int64_t)));
        std::memcpy(this->m_content.get(), &value, sizeof(std::int64_t));
    }else{
        this->m_arrContent.resize(size);
    }
}

VM::TYPES::Reference::Reference(long double value, std::uint64_t size, std::uint32_t id) {
    this->m_id = id;
    this->m_size = size;
    this->m_type = 0x6;
    if(size == 1) {
        this->m_content = std::make_shared<void *>(malloc(sizeof(long double)));
        std::memcpy(this->m_content.get(), &value, sizeof(long double));
    }else{
        this->m_arrContent.resize(size);
    }
}

VM::TYPES::Reference::Reference() {
    this->m_type = 255;
    this->m_content = std::make_shared<void*>(malloc(sizeof(int)));
}





