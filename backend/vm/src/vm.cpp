#include "vm.h"
#include "program.h"
#include "typedefs.h"
#include <cstring>

namespace NightVM{
    void VM::run_function(size_t func_id){
        FunctionInfo& func = m_program.functions[func_id];

        InstructionPtr ip = m_program.bytecode.data(); // instruction ptr

        ip += func.offset;

        static void* dispatch_tabel[]{ //THE SAME ORDER AS OpCode!!!
            &&op_push_const,
            &&op_ret,
        };

        #define DISPATCH() goto *dispatch_tabel[*ip]
        #define INC_IP() ip++
        #define READ_ARG() read_bytes(ip)

        DISPATCH();

        op_push_const:
        {
            INC_IP();
            push(m_program.constant_pool[READ_ARG()]);
            DISPATCH();
        }
        
        op_ret:
        {
            print2console(pop()); //DBG
            return;
        }
    }

    InstructionArg VM::read_bytes(InstructionPtr& ip){
        InstructionArg val = 0;
        std::memcpy(&val, ip, 4);
        ip += 4;
        return val;
    }
}