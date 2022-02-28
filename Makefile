CC = gcc
BD = ./bin/
SC = ./src/

all : $(BD)dice_poker

$(BD)dice_poker : $(BD)main.o $(BD)game.o $(BD)bubble.o
	$(CC) -o $(BD)dice_poker $(BD)main.o $(BD)game.o $(BD)bubble.o -lm

$(BD)main.o : $(SC)main.c ./include/game.h ./include/globals.h
	$(CC) -c $(SC)main.c -o $(BD)main.o -lm

$(BD)game.o : $(SC)game.c ./include/bubble.h ./include/globals.h ./include/enums.h
	$(CC) -c $(SC)game.c -o $(BD)game.o -lm

$(BD)bubble.o : $(SC)bubble.c ./include/bubble.h
	$(CC) -c $(SC)bubble.c -o $(BD)bubble.o

clean :
	rm $(BD)dice_poker $(BD)main.o $(BD)game.o

run :
	$(BD)dice_poker
