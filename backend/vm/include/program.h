#ifndef NIGHT_VM_PROGRAM_H
#define NIGHT_VM_PROGRAM_H

#include "export.h"
#include "op_codes.h"
#include "value.h"
#include <cstdint>
#include <optional>
#include <vector>

namespace NightVM{
    
    struct NIGHT_VM_API Instruction{
        OpCode code;
        std::optional<uint32_t> arg0 = std::nullopt;
    };
    
    struct NIGHT_VM_API Function{
        std::vector<Instruction> body;
    };

    struct NIGHT_VM_API Program{
        std::vector<Function> functions; //auto(by code generator) id = index
        std::vector<ConstValue> constant_pool;
    };

}

#endif