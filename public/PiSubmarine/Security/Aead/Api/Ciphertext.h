#pragma once

#include <cstddef>
#include <vector>

namespace PiSubmarine::Security::Aead::Api
{
    struct Ciphertext
    {
        std::vector<std::byte> Value;

        [[nodiscard]] bool operator==(const Ciphertext&) const = default;
    };
}
