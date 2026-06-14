#include <gtest/gtest.h>

#include "PiSubmarine/Security/Aead/Api/AssociatedData.h"
#include "PiSubmarine/Security/Aead/Api/Ciphertext.h"
#include "PiSubmarine/Security/Aead/Api/ErrorCode.h"
#include "PiSubmarine/Security/Aead/Api/Key.h"
#include "PiSubmarine/Security/Aead/Api/Nonce.h"
#include "PiSubmarine/Security/Aead/Api/Plaintext.h"

namespace PiSubmarine::Security::Aead::Api
{
    TEST(AeadApiTest, KeyStoresOpaqueBytes)
    {
        const Key key{.Value = {std::byte{0x10}, std::byte{0x20}}};

        ASSERT_EQ(key.Value.size(), 2U);
        EXPECT_EQ(key.Value[0], std::byte{0x10});
        EXPECT_EQ(key.Value[1], std::byte{0x20});
    }

    TEST(AeadApiTest, NonceStoresOpaqueBytes)
    {
        const Nonce nonce{.Value = {std::byte{0xAA}, std::byte{0xBB}, std::byte{0xCC}}};

        ASSERT_EQ(nonce.Value.size(), 3U);
        EXPECT_EQ(nonce.Value[0], std::byte{0xAA});
        EXPECT_EQ(nonce.Value[1], std::byte{0xBB});
        EXPECT_EQ(nonce.Value[2], std::byte{0xCC});
    }

    TEST(AeadApiTest, PlaintextStoresOpaqueBytes)
    {
        const Plaintext plaintext{.Value = {std::byte{0x01}, std::byte{0x02}}};

        ASSERT_EQ(plaintext.Value.size(), 2U);
        EXPECT_EQ(plaintext.Value[0], std::byte{0x01});
        EXPECT_EQ(plaintext.Value[1], std::byte{0x02});
    }

    TEST(AeadApiTest, CiphertextStoresOpaqueBytes)
    {
        const Ciphertext ciphertext{.Value = {std::byte{0x03}, std::byte{0x04}, std::byte{0x05}}};

        ASSERT_EQ(ciphertext.Value.size(), 3U);
        EXPECT_EQ(ciphertext.Value[0], std::byte{0x03});
        EXPECT_EQ(ciphertext.Value[1], std::byte{0x04});
        EXPECT_EQ(ciphertext.Value[2], std::byte{0x05});
    }

    TEST(AeadApiTest, AssociatedDataStoresOpaqueBytes)
    {
        const AssociatedData associatedData{.Value = {std::byte{0xFE}, std::byte{0xED}}};

        ASSERT_EQ(associatedData.Value.size(), 2U);
        EXPECT_EQ(associatedData.Value[0], std::byte{0xFE});
        EXPECT_EQ(associatedData.Value[1], std::byte{0xED});
    }

    TEST(AeadApiTest, ErrorCodeProducesExpectedMessage)
    {
        const auto errorCode = make_error_code(ErrorCode::AuthenticationFailed);

        EXPECT_EQ(errorCode.category().name(), std::string("PiSubmarine.Security.Aead.Api"));
        EXPECT_EQ(errorCode.message(), std::string("aead authentication failed"));
    }
}
