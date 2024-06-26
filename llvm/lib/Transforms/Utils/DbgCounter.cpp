#include "llvm/Transforms/Utils/DbgCounter.h"
#include "llvm/Passes/PassBuilder.h"

using namespace llvm;

cl::opt<std::string> OutputFilename("output", cl::value_desc("<output file>"), cl::desc("<output file>"), cl::init("-"));


PreservedAnalyses DbgCounter::run(Function &F, FunctionAnalysisManager &AM){
    
    static std::error_code EC;
    static llvm::raw_fd_ostream OutputFile(OutputFilename, EC);

    if(EC){
        errs() << "Could not open file: " << EC.message() << "\n";
        return PreservedAnalyses::all();
    }

    OutputFile << "Function: " << F.getName() << '\n';

    int valuesCnt = 0;
    int declareCnt = 0;
    int assignCnt = 0;

    //BB - Basic Block
    for(auto &BB: F){
        for(Instruction &Instr: BB){
            for(DbgVariableRecord &DVR : filterDbgVars(Instr.getDbgRecordRange())){
                if(DVR.isDbgValue()) valuesCnt++;
                else if(DVR.isDbgDeclare()) declareCnt++;
                else if(DVR.isDbgAssign()) assignCnt++;
            }
        }
    }

    OutputFile << "\tllvm.dbg.values: " << valuesCnt << '\n';
    OutputFile << "\tllvm.dbg.declare: " << declareCnt << '\n';
    OutputFile << "\tllvm.dbg.assign: " << assignCnt << '\n';

    return PreservedAnalyses::all();
}