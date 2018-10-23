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
        ${PROJECT_SOURCE_DIR}/gen
)

add_executable(AbstractVMv1 src/AbstractVM.cpp
        src/AbstractVMFactory.cpp
        src/main.cpp
        /Users/rkoval/CLionProjects/Abstract_VM/gen/avmLexer.h
        /Users/rkoval/CLionProjects/Abstract_VM/gen/avmBaseVisitor.cpp
        /Users/rkoval/CLionProjects/Abstract_VM/gen/avmBaseListener.h
        /Users/rkoval/CLionProjects/Abstract_VM/gen/avmBaseListener.cpp
        /Users/rkoval/CLionProjects/Abstract_VM/gen/avmBaseVisitor.h
        /Users/rkoval/CLionProjects/Abstract_VM/gen/avmParser.cpp
        /Users/rkoval/CLionProjects/Abstract_VM/gen/avmListener.h
        /Users/rkoval/CLionProjects/Abstract_VM/gen/avmListener.cpp
        /Users/rkoval/CLionProjects/Abstract_VM/gen/avmLexer.cpp
        /Users/rkoval/CLionProjects/Abstract_VM/gen/avmVisitor.h
        /Users/rkoval/CLionProjects/Abstract_VM/gen/avmVisitor.cpp
        /Users/rkoval/CLionProjects/Abstract_VM/gen/avmParser.h
        /Users/rkoval/CLionProjects/Abstract_VM/includes/AbstractVMFactory.hpp
        /Users/rkoval/CLionProjects/Abstract_VM/includes/IOperand.hpp
        /Users/rkoval/CLionProjects/Abstract_VM/includes/TOperand.hpp
        /Users/rkoval/CLionProjects/Abstract_VM/includes/AbstractVM.hpp)

target_link_libraries(AbstractVMv1 "${PROJECT_SOURCE_DIR}/libantlr4-runtime.dylib")


