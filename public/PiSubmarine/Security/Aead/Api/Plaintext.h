#pragma once

#include <cstddef>
#include <vector>

namespace PiSubmarine::Security::Aead::Api
{
    struct Plaintext
    {
        std::vector<std::byte> Value;

        [[nodiscard]] bool operator==(const Plaintext&) const = default;
    };
}
