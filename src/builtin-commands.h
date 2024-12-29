#ifndef BUILTIN_COMMANDS_H
#define BUILTIN_COMMANDS_H

int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);

int lsh_num_builtins(); // to count number of builtin commands

extern int (*builtin_func[])(char **);
extern char *builtin_str[];
#endif // !BUILTIN_COMMANDS_H
