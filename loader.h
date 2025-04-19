#ifndef LOADER_H
#define LOADER_H

#include <stdio.h>
#include "instructions.h"  // Para a struct Instruction e MEMORY_SIZE

FILE *read_file(char *filename);

/**
 * Carrega o programa de um arquivo .txt para a memória de instruções.
 * 
 * @param filename Caminho para o arquivo .txt com as instruções.
 * @param mem Memória de instruções (Instruction[]).
 * @param data_mem Memória de dados (int[]), caso queira inicializar algo junto.
 */
void load_program(char *filename, Instruction mem[MEMORY_SIZE]);

#endif
