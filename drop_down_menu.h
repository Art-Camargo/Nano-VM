// dropdown.h

#ifndef DROPDOWN_H
#define DROPDOWN_H

#include <stdbool.h>

#define CLEAR_SCREEN "\033[2J\033[H"
#define CURSOR_UP "\033[A"
#define CURSOR_DOWN "\033[B"
#define CLEAR_LINE "\033[K"
#define HIGHLIGHT "\033[7m"
#define RESET "\033[0m"

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_ENTER 10
#define KEY_ESC 27
#define KEY_Q 113

typedef struct {
    char **options;
    int num_options;
    int selected;
    char *title;
} Dropdown;


void init_terminal();
void reset_terminal();

Dropdown *create_dropdown(char *title, char **options, int num_options);
void free_dropdown(Dropdown *dropdown);

void display_dropdown(Dropdown *dropdown);
int run_dropdown(Dropdown *dropdown);

#endif 
