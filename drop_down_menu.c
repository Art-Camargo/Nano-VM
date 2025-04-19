#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

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

void init_terminal() {
  struct termios term;
  tcgetattr(STDIN_FILENO, &term);
  term.c_lflag &= ~(ICANON | ECHO); 
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void reset_terminal() {
  struct termios term;
  tcgetattr(STDIN_FILENO, &term);
  term.c_lflag |= (ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

Dropdown *create_dropdown(char *title, char **options, int num_options) {
  Dropdown *dropdown = (Dropdown *)malloc(sizeof(Dropdown));
  if (!dropdown)
    return NULL;

  dropdown->options = options;
  dropdown->num_options = num_options;
  dropdown->selected = 0;
  dropdown->title = title;

  return dropdown;
}

void display_dropdown(Dropdown *dropdown) {
  printf(CLEAR_SCREEN);
  printf("%s\n\n", dropdown->title);

  for (int i = 0; i < dropdown->num_options; i++) {
    if (i == dropdown->selected) {
      printf("%s> %s%s\n", HIGHLIGHT, dropdown->options[i], RESET);
    } else {
      printf("  %s\n", dropdown->options[i]);
    }
  }
}

int read_key() {
  char c;
  if (read(STDIN_FILENO, &c, 1) == 1) {
    return c;
  }
  return 0;
}

void handle_arrow_key(Dropdown *dropdown) {
  switch (read_key()) {
  case KEY_UP:
    if (dropdown->selected > 0) {
      dropdown->selected--;
      display_dropdown(dropdown);
    }
    break;

  case KEY_DOWN:
    if (dropdown->selected < dropdown->num_options - 1) {
      dropdown->selected++;
      display_dropdown(dropdown);
    }
    break;
  }
}

int run_dropdown(Dropdown *dropdown) {
  bool is_running = true;
  display_dropdown(dropdown);

  while (is_running) {
    switch (read_key()) {
    case KEY_ESC: 
      if (read_key() == '[') {
        handle_arrow_key(dropdown);
      } else {
        dropdown->selected = -1;
        is_running = false;
      }
      break;
    case KEY_ENTER:
      is_running = false;
      break;
    case KEY_Q:
      dropdown->selected = -1;
      is_running = false;
      break;
    }
  }

  return dropdown->selected;
}

void free_dropdown(Dropdown *dropdown) { free(dropdown); }