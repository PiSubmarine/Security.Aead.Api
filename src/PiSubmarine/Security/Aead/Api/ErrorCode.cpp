#include "PiSubmarine/Security/Aead/Api/ErrorCode.h"

namespace PiSubmarine::Security::Aead::Api
{
    namespace
    {
        class ErrorCategory final : public std::error_category
        {
        public:
            [[nodiscard]] const char* name() const noexcept override
            {
                return "PiSubmarine.Security.Aead.Api";
            }

            [[nodiscard]] std::string message(const int condition) const override
            {
                switch (static_cast<ErrorCode>(condition))
                {
                case ErrorCode::InvalidKey:
                    return "aead key must not be empty";
                case ErrorCode::InvalidNonce:
                    return "aead nonce must not be empty";
                case ErrorCode::InvalidCiphertext:
                    return "aead ciphertext must not be empty";
                case ErrorCode::EncryptionFailed:
                    return "aead encryption failed";
                case ErrorCode::AuthenticationFailed:
                    return "aead authentication failed";
                }

                return "unknown aead error";
            }
        };
    }

    std::error_code make_error_code(const ErrorCode errorCode) noexcept
    {
        static const ErrorCategory Category;
        return {static_cast<int>(errorCode), Category};
    }
}
