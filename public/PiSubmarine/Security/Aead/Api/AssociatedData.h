#pragma once

#include <cstddef>
#include <vector>

namespace PiSubmarine::Security::Aead::Api
{
    struct AssociatedData
    {
        std::vector<std::byte> Value;

        [[nodiscard]] bool operator==(const AssociatedData&) const = default;
    };
}
