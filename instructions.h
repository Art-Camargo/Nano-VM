#ifndef INSTRUCTION_H
#define INSTRUCTION_H



#define MEMORY_SIZE 320

typedef struct {
    int opcode;
    int op1;
    int op2;
    int op3;
} Instruction;

static const Instruction NOP_INSTRUCTION = { -1, -1, -1, -1 };

#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3
#define MV 4
#define ST 5
#define JMP 6
#define JEQ 7
#define JGT 8
#define JLT 9
#define W 10
#define R 11
#define STP 12


#endif
