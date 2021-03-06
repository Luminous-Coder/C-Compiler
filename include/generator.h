#ifndef C_COMPILER_GENERATOR_H
#define C_COMPILER_GENERATOR_H

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include "parser.h"

class Generator {
public:
    explicit Generator(Node* node);

    Generator(const Generator&) = delete;
    Generator& operator=(const Generator&) = delete;

    ~Generator();

    std::string_view getIR();

private:
    std::string ir;
    llvm::LLVMContext context;
    llvm::IRBuilder<>* builder;
};

#endif //C_COMPILER_GENERATOR_H
