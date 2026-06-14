include("${_build_cmake_local}")

message("Adding library: ${PISUBMARINE_MODULE_NAME}")
add_library(${PISUBMARINE_MODULE_NAME}
        PiSubmarine/Security/Aead/Api/ErrorCode.cpp
        "../public/PiSubmarine/Security/Aead/Api/AssociatedData.h"
        "../public/PiSubmarine/Security/Aead/Api/Ciphertext.h"
        "../public/PiSubmarine/Security/Aead/Api/ErrorCode.h"
        "../public/PiSubmarine/Security/Aead/Api/IAead.h"
        "../public/PiSubmarine/Security/Aead/Api/Key.h"
        "../public/PiSubmarine/Security/Aead/Api/Nonce.h"
        "../public/PiSubmarine/Security/Aead/Api/Plaintext.h")
target_include_directories(${PISUBMARINE_MODULE_NAME} PUBLIC "../public")
PiSubmarineInitTarget(${PISUBMARINE_MODULE_NAME})

PiSubmarineAddDependency("https://github.com/PiSubmarine/Error.Api.git" "")
target_link_libraries(${PISUBMARINE_MODULE_NAME} PUBLIC PiSubmarine.Error.Api)
