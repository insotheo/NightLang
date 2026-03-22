#ifndef NIGHT_VM_VALUE_H
#define NIGHT_VM_VALUE_H

#include "export.h"
#include "typedefs.h"
#include <cstdint>

struct ConstValue{
    enum class Type: uint8_t {INT, FLOAT} type;
    union {
        NightInt i;
        NightFloat f;
    };
};

namespace NightVM{
    NIGHT_VM_API void print2console(const ConstValue& cval); //FOR DBG
}

#endif