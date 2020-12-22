CC=gcc
CFLAGS=-Wall -g -lSDL2 -lSDL2main -lm -lSDL2_ttf
SRC=main.c\
    tasks.c
OBJ=$(SRC:.c=.o)

%.o: %.c $(DEPS)
	$(CC) -c -o obj/$@ $< $(CFLAGS)

Factory: $(OBJ)
	cd obj;\
	$(CC) -o ../$@ $^ $(CFLAGS)
