#pragma once

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Security/Aead/Api/AssociatedData.h"
#include "PiSubmarine/Security/Aead/Api/Ciphertext.h"
#include "PiSubmarine/Security/Aead/Api/Key.h"
#include "PiSubmarine/Security/Aead/Api/Nonce.h"
#include "PiSubmarine/Security/Aead/Api/Plaintext.h"

namespace PiSubmarine::Security::Aead::Api
{
    class IAead
    {
    public:
        virtual ~IAead() = default;

        [[nodiscard]] virtual Error::Api::Result<Ciphertext> Seal(
            const Key& key,
            const Nonce& nonce,
            const Plaintext& plaintext,
            const AssociatedData& associatedData) const = 0;

        [[nodiscard]] virtual Error::Api::Result<Plaintext> Open(
            const Key& key,
            const Nonce& nonce,
            const Ciphertext& ciphertext,
            const AssociatedData& associatedData) const = 0;
    };
}
