#include <stdio.h>
#include <unistd.h>
#include "builtin-commands.h"

// list of builtin commands followed by their corresponding functions.
char *builtin_str[] = {"cd", "help", "exit"};

// array of builtin shell command function pointers 😭
int (*builtin_func[])(char **) = {
  &lsh_cd,
  &lsh_help,
  &lsh_exit
};

int lsh_num_builtins() { 
  return sizeof(builtin_str) / sizeof(char *); 
}
// builtin function implementations
int lsh_cd(char **args) {
  if (args[1] == NULL) {
    fprintf(stderr, "lsh: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("lsh");
    }
  }
  return 1;
}

int lsh_help(char **args) {
  int i;
  printf("4x1mux's LSH made by following Stephan Brennan's LSH\n");
  printf("Type program names, arguments and hit enter \n");
  printf("The following are built in: \n");

  for (i = 0; i < lsh_num_builtins(); i++) {
    printf("   %s\n", builtin_str[i]);
  }
  printf("Use the man command for information on other programs.\n");
  return 1;
}

int lsh_exit(char **args) { 
  return 0;
}
