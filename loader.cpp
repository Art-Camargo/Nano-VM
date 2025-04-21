#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "instructions.h"
#include <string>

using namespace std;


FILE *read_file(char *filename) {
  FILE *file = fopen(filename, "r");
  if (!file) {
      fprintf(stderr, "Error opening file: %s\n", filename);
      exit(EXIT_FAILURE);
  }
  return file;
}



void load_program(char *filename, Instruction mem[MEMORY_SIZE]) {
  FILE *file = read_file(filename);
  char buffer[256];
  int instruction_count = 0;
  
  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    string line(buffer);
    if (line[0] == '#' || line.empty()) continue;
    Instruction instruction;
    int opcode, op1, op2, op3;
    sscanf(line.c_str(), "%d %d %d %d", &opcode, &op1, &op2, &op3);
    if (opcode < 0 || opcode > 14) continue;
    instruction.opcode = opcode;
    instruction.op1 = op1;
    instruction.op2 = op2;
    instruction.op3 = op3;
    mem[instruction_count++] = instruction;
  }

  printf("Loaded %d instructions\n", instruction_count);
  fclose(file); 
}