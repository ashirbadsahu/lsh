CC = gcc
CFLAGS = -g

SRC = src/main.c src/lsh.c src/builtin-commands.c
OBJ = $(SRC:.c=.o)
EXEC = lsh

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)