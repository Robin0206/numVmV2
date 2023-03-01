//
// Created by Robin on 01.03.2023.
//

#ifndef NUMVMV2_REFERENCE_H
#define NUMVMV2_REFERENCE_H

#include <cstdint>

namespace VM::TYPES{
    class Reference {
        std::uint8_t m_type;
        std::uint32_t m_id;
        std::uint64_t m_size;
        void* m_content;

        explicit Reference(bool value, std::uint64_t size);
        explicit Reference(std::uint8_t value, std::uint64_t size);
        explicit Reference(std::uint32_t value, std::uint64_t size);
        explicit Reference(std::uint64_t value, std::uint64_t size);
        explicit Reference(std::int32_t value, std::uint64_t size);
        explicit Reference(std::int64_t value, std::uint64_t size);
        explicit Reference(long double value, std::uint64_t size);
        ~Reference();
    };
}

#endif //NUMVMV2_REFERENCE_H
