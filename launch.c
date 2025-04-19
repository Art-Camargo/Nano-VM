#include "instructions.h"
#include <stdio.h>
#include <stdlib.h>

void alu(int opcode, int *registers[4], int op1, int op2, int op3) {
  switch (opcode) {
      case 0:
          *registers[op1] = *registers[op2] + *registers[op3];
          break;

      case 1: 
          *registers[op1] = *registers[op2] - *registers[op3];
          break;

      case 2:
          *registers[op1] = *registers[op2] * *registers[op3];
          break;

      case 3: 
          if (*registers[op3] != 0) *registers[op1] = *registers[op2] / *registers[op3];
          else *registers[op1] = 0;
          break;

      default:
          fprintf(stderr, "Opcode inválido na ALU: %d\n", opcode);
          break;
  }
}

int handle_jump(int opcode, int *regs[], Instruction instr, int current_pc) {
  switch (opcode) {
      case JMP:
          return instr.op1;
      case JEQ:
          return (*regs[instr.op1] == *regs[instr.op2]) ? instr.op3 : current_pc;
      case JGT:
          return (*regs[instr.op1] > *regs[instr.op2]) ? instr.op3 : current_pc;
      case JLT:
          return (*regs[instr.op1] < *regs[instr.op2]) ? instr.op3 : current_pc;
      default:
          return current_pc;
  }
}

void launch_program(int data_memory[MEMORY_SIZE], Instruction memory[MEMORY_SIZE]) {
  int pc = 0, a0 = 0, a1 = 0, a2 = 0, a3 = 0;
  int *registers[4] = { &a0, &a1, &a2, &a3 };
  

  while (pc < MEMORY_SIZE) {
    Instruction instruction = memory[pc++];
    switch (instruction.opcode) {
        case ADD:
        case SUB:
        case MUL:
        case DIV:
            alu(instruction.opcode, registers, instruction.op1, instruction.op2, instruction.op3);
            break;

        case MV:
            *registers[instruction.op1] = data_memory[instruction.op2];
            break;

        case ST:
            data_memory[instruction.op1] = *registers[instruction.op2];
            break;
        
        case JMP:
        case JEQ:
        case JGT:
        case JLT:
            pc = handle_jump(instruction.opcode, registers, instruction, pc);
            break;

        case W:
            printf("%d\n", data_memory[instruction.op1]);
            break;

        case R:
            scanf("%d", &data_memory[instruction.op1]);
            break;

        case STP:
            return;

        default:
            continue;
    }
  }
  
}