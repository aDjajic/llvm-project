#ifndef LLVM_TRANSFORMS_DBGCOUNTER_H
#define LLVM_TRANSFORMS_DBGCOUNTER_H

#include "llvm/IR/PassManager.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/IntrinsicInst.h"

namespace llvm {

    class DbgCounter: public PassInfoMixin<DbgCounter> {

    public:
        PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);
    };

}

#endif