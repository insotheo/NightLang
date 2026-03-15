#ifndef NIGHT_VM_OP_CODES_H
#define NIGHT_VM_OP_CODES_H

#include "typedefs.h"

namespace NightVM {
    enum OpCode: Byte{
        OP_PUSH_CONST,
        OP_RET,
    };
}

#endif