#pragma once

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Security/Aead/Api/AssociatedData.h"
#include "PiSubmarine/Security/Aead/Api/Ciphertext.h"
#include "PiSubmarine/Security/Aead/Api/Key.h"
#include "PiSubmarine/Security/Aead/Api/Plaintext.h"
#include "PiSubmarine/Security/Api/Nonce.h"

namespace PiSubmarine::Security::Aead::Api
{
    class IProvider
    {
    public:
        virtual ~IProvider() = default;

        [[nodiscard]] virtual Error::Api::Result<Ciphertext> Seal(
            const Key& key,
            const ::PiSubmarine::Security::Api::Nonce& nonce,
            const Plaintext& plaintext,
            const AssociatedData& associatedData) const = 0;

        [[nodiscard]] virtual Error::Api::Result<Plaintext> Open(
            const Key& key,
            const ::PiSubmarine::Security::Api::Nonce& nonce,
            const Ciphertext& ciphertext,
            const AssociatedData& associatedData) const = 0;
    };
}
