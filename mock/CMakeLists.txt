include("${_build_cmake_local}")

find_package(GTest CONFIG REQUIRED)

message("Adding interface library: ${PISUBMARINE_MODULE_NAME}.Mock")
add_library(${PISUBMARINE_MODULE_NAME}.Mock INTERFACE
        PiSubmarine/Security/Aead/Api/IAeadMock.h)
target_include_directories(${PISUBMARINE_MODULE_NAME}.Mock INTERFACE "./")
PiSubmarineInitTarget(${PISUBMARINE_MODULE_NAME}.Mock)

target_link_libraries(${PISUBMARINE_MODULE_NAME}.Mock INTERFACE ${PISUBMARINE_MODULE_NAME})
target_link_libraries(${PISUBMARINE_MODULE_NAME}.Mock INTERFACE GTest::gmock)
