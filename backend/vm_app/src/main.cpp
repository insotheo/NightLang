#include "op_codes.h"
#include <iostream>
#include <program.h>
#include <string>

int main(void){
    NightVM::Program prog{
        .functions =  {
            NightVM::Function{ //main
                .body = {
                    {NightVM::OpCode::OP_PUSH_CONST, 0},
                    {NightVM::OpCode::OP_RET}
                }
            }
        },
        .constant_pool = { 0 }
    };

    for(const auto& op : prog.functions[0].body){
        std::cout << (int)op.code << " " << (op.arg0.has_value() ? std::to_string(op.arg0.value()) : "") << "\n";

    }
    
    return 0;
}