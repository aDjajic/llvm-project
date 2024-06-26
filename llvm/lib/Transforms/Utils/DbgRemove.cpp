#include "llvm/Transforms/Utils/DbgRemove.h"

using namespace llvm;

PreservedAnalyses DbgRemove::run(Function &F, FunctionAnalysisManager &AM){
    
    SmallVector<DbgVariableRecord*> toBeRemoved;

    for(auto &BB:F){
        for(Instruction &Instr: BB){
            for(DbgVariableRecord &DVR : filterDbgVars(Instr.getDbgRecordRange())){
                toBeRemoved.push_back(&DVR);
            }
        }
    }

    bool modified = toBeRemoved.size()>0;

    for(auto DVR: toBeRemoved){
        DVR->eraseFromParent();
    }

    return modified ? PreservedAnalyses::none() : PreservedAnalyses::all();
}