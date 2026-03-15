#ifndef NIGHT_VM_VALUE_H
#define NIGHT_VM_VALUE_H

#include "export.h"
#include <variant>
#include <cstdint>

using ConstValue = std::variant<int64_t, double>;

namespace NightVM{
    NIGHT_VM_API void print2console(const ConstValue& cval); //FOR DBG
}

#endif