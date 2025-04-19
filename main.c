#include "drop_down_menu.h"
#include "dir_options.h"
#include "instructions.h"
#include "launch.h"
#include "loader.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIR_SIZE 512
#define PROGRAMS_DIR "./programs"


Instruction memory[MEMORY_SIZE];
int data_memory[MEMORY_SIZE];
int program_counter = 0;

void init_memory() {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = NOP_INSTRUCTION;
        data_memory[i] = 0;
    }
}

void choose_file(char *program) {
    char options[MAX_FILES][MAX_FILENAME];
    char *title = "Choose a file:"; 
    int num_options = find_files(PROGRAMS_DIR, options, MAX_FILES);
    char *option_ptrs[MAX_FILES];
    for (int i = 0; i < num_options; i++) {
        option_ptrs[i] = options[i];
    }

    Dropdown *dropdown = create_dropdown(title, option_ptrs, num_options);
    if (!dropdown) {
        fprintf(stderr, "Failed to create dropdown\n");
        exit(EXIT_FAILURE);
    }
    init_terminal();
    int selected = run_dropdown(dropdown);
    reset_terminal();
    if (selected < 0) exit(EXIT_FAILURE);
    printf("You selected: %s\n", dropdown->options[selected]);
    strcpy(program, dropdown->options[selected]);
    free_dropdown(dropdown);
}


int main() {
  char program[MAX_FILENAME];
  char full_path[MAX_DIR_SIZE];
  choose_file(program);
  snprintf(full_path, sizeof(full_path), "%s/%s", PROGRAMS_DIR, program);
  init_memory();
  load_program(full_path, memory, data_memory);
  launch_program(data_memory, memory);
  printf("Program finished execution.\n");
  return 0;
}
