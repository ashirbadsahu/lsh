#ifndef LSH_H
#define LSH_H

// constants for various operations
#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

// lsh function declarations
void lsh_loop(void);
char *lsh_read_line(void);
char **lsh_split_line(char *line);
int lsh_execute(char **args);

#endif // !LSH_H
