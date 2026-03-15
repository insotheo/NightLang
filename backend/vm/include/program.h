#ifndef NIGHT_VM_PROGRAM_H
#define NIGHT_VM_PROGRAM_H

#include "export.h"
#include "typedefs.h"
#include "value.h"
#include <vector>

namespace NightVM{
    
    struct NIGHT_VM_API FunctionInfo{
        BytecodeIndex offset;
        BytecodeIndex length;
    };

    struct NIGHT_VM_API Program{
        std::vector<Byte> bytecode;
        std::vector<FunctionInfo> functions; //auto(by code generator) id = index
        std::vector<ConstValue> constant_pool;
    };

}

#endif