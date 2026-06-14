#pragma once

#include <system_error>

namespace PiSubmarine::Security::Aead::Api
{
    enum class ErrorCode
    {
        InvalidKey = 1,
        InvalidNonce,
        InvalidCiphertext,
        EncryptionFailed,
        AuthenticationFailed
    };

    [[nodiscard]] std::error_code make_error_code(ErrorCode errorCode) noexcept;
}

namespace std
{
    template<>
    struct is_error_code_enum<PiSubmarine::Security::Aead::Api::ErrorCode> : true_type
    {
    };
}
