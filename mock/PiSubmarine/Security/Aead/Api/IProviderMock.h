#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Security/Aead/Api/IAead.h"

namespace PiSubmarine::Security::Aead::Api
{
    class IAeadMock : public IAead
    {
    public:
        MOCK_METHOD(
            (Error::Api::Result<Ciphertext>),
            Seal,
            (const Key& key, const Nonce& nonce, const Plaintext& plaintext, const AssociatedData& associatedData),
            (const, override));
        MOCK_METHOD(
            (Error::Api::Result<Plaintext>),
            Open,
            (const Key& key, const Nonce& nonce, const Ciphertext& ciphertext, const AssociatedData& associatedData),
            (const, override));
    };
}
