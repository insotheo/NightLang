#include "value.h"

#include <iostream>

namespace NightVM{
    void print2console(const ConstValue& cval){
        if(std::holds_alternative<int64_t>(cval))
            std::cout << std::get<int64_t>(cval) << "\n";
        
        else if(std::holds_alternative<double>(cval))
            std::cout << std::get<double>(cval) << "\n";
    }
}