#include "vm.h"
#include "program.h"
#include <vector>

namespace NightVM{
    void VM::run_function(size_t func_id){
        Function& func = m_program.functions[func_id];
        Instruction* ip = func.body.data(); // instruction ptr

        static void* dispatch_tabel[]{ //THE SAME ORDER AS OpCode!!!
            &&op_push_const,
            &&op_ret,
        };
        #define DISPATCH() goto *dispatch_tabel[(int)ip->code]

        DISPATCH();
        while(true){
            op_push_const:
                push(m_program.constant_pool[ip->arg0.value()]);
                ++ip;
                DISPATCH();

            op_ret:
                print2console(pop()); //DBG
                return;
        }
    }
}