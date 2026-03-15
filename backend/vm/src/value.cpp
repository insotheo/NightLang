#include "value.h"

#include <iostream>

namespace NightVM{

    void print2console(const ConstValue& cval){
        if(cval.type == ConstValue::Type::INT)
            std::cout << cval.i << "\n";

        else if(cval.type == ConstValue::Type::DOUBLE)
            std::cout << cval.d << "\n";
    }
    
}