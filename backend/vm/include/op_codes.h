#ifndef NIGHT_VM_OP_CODES_H
#define NIGHT_VM_OP_CODES_H

#include "typedefs.h"

namespace NightVM {
    enum OpCode: Byte{
        OP_PUSH_CONST,
        OP_RET,

        OP_ADD_I,
        OP_SUB_I,
        OP_MUL_I,
        OP_DIV_I,
        OP_MOD_I,
        OP_SHL_I,
        OP_SHR_I,
        OP_AND_I,
        OP_OR_I,
        OP_XOR_I,
        OP_NEG_I, //~

        OP_ADD_F,
        OP_SUB_F,
        OP_MUL_F,
        OP_DIV_F,
    };
}

#endif