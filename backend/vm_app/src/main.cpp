#include <op_codes.h>
#include <program.h>
#include <vm.h>
#include <stdio.h>

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
    printf("Size of the program: %llu bytes\n", sizeof(prog));
    
    NightVM::VM vm(prog);
    vm.run(0);

    return 0;
}