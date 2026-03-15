#ifndef NIGHT_VM_OP_CODES_H
#define NIGHT_VM_OP_CODES_H

#include <cstdint>

namespace NightVM {
    enum class OpCode: uint8_t{
        OP_PUSH_CONST,
        OP_RET,
    };
}

#endif