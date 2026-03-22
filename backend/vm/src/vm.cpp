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

            &&op_add_i,
            &&op_sub_i,
            &&op_mul_i,
            &&op_div_i,
            &&op_mod_i,
            &&op_shl_i,
            &&op_shr_i,
            &&op_and_i,
            &&op_or_i,
            &&op_xor_i,
            &&op_neg_i,
            
            &&op_add_f,
            &&op_sub_f,
            &&op_mul_f,
            &&op_div_f,
        };

        #define DISPATCH() goto *dispatch_tabel[*ip]
        #define INC_IP() ip++
        #define READ_ARG() read_bytes(ip)
        #define FAST_POP() (--sp)

        //code generators
        #define BINARY_OPERATION(op_name, type, field, op)\
        op_name:\
        {\
            INC_IP();\
            type b = FAST_POP()->field;\
            type a = FAST_POP()->field;\
            (sp++)->field = a op b;\
            DISPATCH();\
        }
        #define UNARY_OPERATION(op_name, type, field, op)\
        op_name:\
        {\
            INC_IP();\
            type a = FAST_POP()->field;\
            (sp++)->field = op a;\
            DISPATCH();\
        }


        //code execution
        DISPATCH();

        op_push_const:
        {
            INC_IP();
            push(m_program.constant_pool[READ_ARG()]);
            DISPATCH();
        }

        BINARY_OPERATION(op_add_i, NightInt, i, +)
        BINARY_OPERATION(op_sub_i, NightInt, i, -)
        BINARY_OPERATION(op_mul_i, NightInt, i, *)
        BINARY_OPERATION(op_div_i, NightInt, i, /)
        BINARY_OPERATION(op_mod_i, NightInt, i, %)
        BINARY_OPERATION(op_shl_i, NightInt, i, <<)
        BINARY_OPERATION(op_shr_i, NightInt, i, >>)
        BINARY_OPERATION(op_and_i, NightInt, i, &)
        BINARY_OPERATION(op_or_i, NightInt, i, |)
        BINARY_OPERATION(op_xor_i, NightInt, i, ^)
        UNARY_OPERATION(op_neg_i, NightInt, i, ~)

        BINARY_OPERATION(op_add_f, NightFloat, f, +)
        BINARY_OPERATION(op_sub_f, NightFloat, f, -)
        BINARY_OPERATION(op_mul_f, NightFloat, f, *)
        BINARY_OPERATION(op_div_f, NightFloat, f, /)

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