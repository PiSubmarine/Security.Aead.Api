#pragma once

#include <cstddef>
#include <vector>

namespace PiSubmarine::Security::Aead::Api
{
    struct Nonce
    {
        std::vector<std::byte> Value;

        [[nodiscard]] bool operator==(const Nonce&) const = default;
    };
}
