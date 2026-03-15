#ifndef NIGHT_VM_VALUE_H
#define NIGHT_VM_VALUE_H

#include <variant>
#include <cstdint>

using ConstValue = std::variant<int64_t, double>;

#endif