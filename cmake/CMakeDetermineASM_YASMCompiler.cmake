# Borrowed from x265
set(ASM_DIALECT "_YASM")
set(CMAKE_ASM${ASM_DIALECT}_COMPILER ${YASM_EXECUTABLE})
set(CMAKE_ASM${ASM_DIALECT}_COMPILER_INIT ${_CMAKE_TOOLCHAIN_PREFIX}yasm)
include(CMakeDetermineASMCompiler)
set(ASM_DIALECT)