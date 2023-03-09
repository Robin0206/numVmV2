//
// Created by Robin on 01.03.2023.
//

#ifndef NUMVMV2_REFERENCE_H
#define NUMVMV2_REFERENCE_H

#include <cstdint>
#include <cstdlib>
#include <memory>
#include <vector>

namespace VM::TYPES{
    class Reference {
    public:
        std::uint32_t m_id;
        std::uint64_t m_size;
        std::shared_ptr<void> m_content;
        std::vector<std::shared_ptr<void>> m_arrContent;

        std::uint8_t m_type;
        explicit Reference();
        explicit Reference(bool value, std::uint64_t size, std::uint32_t id);
        explicit Reference(std::uint8_t value, std::uint64_t size, std::uint32_t id);
        explicit Reference(std::uint32_t value, std::uint64_t size, std::uint32_t id);
        explicit Reference(std::uint64_t value, std::uint64_t size, std::uint32_t id);
        explicit Reference(std::int32_t value, std::uint64_t size, std::uint32_t id);
        explicit Reference(std::int64_t value, std::uint64_t size, std::uint32_t id);
        explicit Reference(long double value, std::uint64_t size, std::uint32_t id);
        ~Reference() = default;
        Reference(const Reference& toCopy);
    };
}

#endif //NUMVMV2_REFERENCE_H
