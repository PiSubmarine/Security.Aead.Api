#include <gtest/gtest.h>

#include "PiSubmarine/Security/Aead/Api/IAeadMock.h"

namespace PiSubmarine::Security::Aead::Api
{
    TEST(AeadApiMockTest, AeadMockCanReturnCiphertext)
    {
        IAeadMock aead;
        const Key key{.Value = {std::byte{0x01}}};
        const Nonce nonce{.Value = {std::byte{0x02}}};
        const Plaintext plaintext{.Value = {std::byte{0x03}}};
        const AssociatedData associatedData{.Value = {std::byte{0x04}}};
        const Ciphertext expected{.Value = {std::byte{0x05}, std::byte{0x06}}};

        EXPECT_CALL(aead, Seal(key, nonce, plaintext, associatedData))
            .WillOnce(testing::Return(Error::Api::Result<Ciphertext>(expected)));

        const auto result = aead.Seal(key, nonce, plaintext, associatedData);

        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(*result, expected);
    }
}
