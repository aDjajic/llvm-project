#ifndef LLVM_TRANSFORMS_DBGREMOVE
#define LLVM_TRANSFORMS_DBGREMOVE

#include "llvm/IR/PassManager.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/IntrinsicInst.h"

namespace llvm{
    class DbgRemove: public PassInfoMixin<DbgRemove> {
    public:
        PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);
    };
}

#endif