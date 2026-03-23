#include <op_codes.h>
#include <program.h>
#include <vm.h>

using NightVM::OpCode;

int main(void){
    NightVM::Program prog{
        .bytecode{
            OpCode::OP_PUSH_CONST, 0x00, 0x00, 0x00, 0x00,
            OpCode::OP_PUSH_CONST, 0x01, 0x00, 0x00, 0x00,
            OpCode::OP_SHL_I,
            OpCode::OP_RET
        },
        .functions =  {
            NightVM::FunctionInfo{ //main
                .offset = 0,
                .length = 0,
            }
        },
        .constant_pool = { {.type=ConstValue::Type::INT, .i=5}, {.type=ConstValue::Type::INT, .i=2}, }
    };
    prog.functions[0].length = prog.bytecode.size();
    
    NightVM::VM vm(prog);
    vm.run(0);

    return 0;
}