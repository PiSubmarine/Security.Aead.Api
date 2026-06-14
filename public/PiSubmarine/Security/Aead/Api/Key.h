#pragma once

#include <cstddef>
#include <vector>

namespace PiSubmarine::Security::Aead::Api
{
    struct Key
    {
        std::vector<std::byte> Value;

        [[nodiscard]] bool operator==(const Key&) const = default;
    };
}
