#include "value.h"

#include <iostream>

namespace NightVM{

    void print2console(const ConstValue& cval){
        if(cval.type == ConstValue::Type::INT)
            std::cout << cval.i << "\n";

        else if(cval.type == ConstValue::Type::FLOAT)
            std::cout << cval.f << "\n";
    }
    
}