cmake_minimum_required(VERSION 3.9)
project(AbstractVMv1)


set(CMAKE_CXX_STANDARD 14)

include_directories(
        ${PROJECT_SOURCE_DIR}/antlr4-runtime/
        ${PROJECT_SOURCE_DIR}/antlr4-runtime/misc
        ${PROJECT_SOURCE_DIR}/antlr4-runtime/atn
        ${PROJECT_SOURCE_DIR}/antlr4-runtime/dfa
        ${PROJECT_SOURCE_DIR}/antlr4-runtime/tree
        ${PROJECT_SOURCE_DIR}/antlr4-runtime/support
        ${PROJECT_SOURCE_DIR}/
        ${PROJECT_SOURCE_DIR}/libs/
        ${PROJECT_SOURCE_DIR}/gen
)

add_executable(AbstractVMv1 main.cpp /Users/rkoval/CLionProjects/AbstractVMv1/gen/avmLexer.cpp
        /Users/rkoval/CLionProjects/AbstractVMv1/gen/avmParser.cpp AbstractVM.cpp AbstractVM.hpp AbstractVMVisiter.cpp AbstractVMVisiter.hpp TNumber.hpp AbstractVMFactory.cpp AbstractVMFactory.hpp)

target_link_libraries(AbstractVMv1 "${PROJECT_SOURCE_DIR}/lib/libantlr4-runtime.dylib")


