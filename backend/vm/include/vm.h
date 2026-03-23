#ifndef NIGHT_VM_VM_H
#define NIGHT_VM_VM_H

#include "export.h"
#include "program.h"
#include "typedefs.h"
#include "value.h"

#define VM_STACK_SIZE 128

namespace NightVM{

    class NIGHT_VM_API VM{
    public:
        explicit VM(Program& program)
            : m_program(program), sp(stack)
        {}

        inline void run(size_t func_id) { run_function(func_id); }

    private:
        Program& m_program;

        //stack
        ConstValue stack[VM_STACK_SIZE];
        ConstValue* sp; //stack pointer;
        
        inline void push(const ConstValue& val){
            if(sp >= stack + VM_STACK_SIZE){
                //TODO: THROW AN ERROR
            }
            *sp++ = val;
        }

        inline ConstValue pop(){
            if(sp <= stack){
                //TODO: THROW AN ERROR
            }
            return *--sp;
        }

        //memory
        InstructionArg read_bytes(InstructionPtr& ip, const Byte bytes_count);

        //
        void run_function(size_t func_id);
    };

}

#endif