LIBRARY=sudo apt-get install libncursesw5-dev
CC=g++
OBJS=CreateField.o fireworks.o getScore.o menu.o play.o the_winner.o 
MAIN=main.cpp
LFLAGS=-lncurses
CFLAGS=-Wall
NAME=game.out
NOT=./additional/not.txt
AND=./additional/and.txt
OR=./additional/or.txt

game: $(OBJS)
	$(CC) $(MAIN) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

config:
	$(LIBRARY)

clean:
	\rm *~ $(NAME) -f

cleanAll:
	\rm -if *~ *.o $(NAME)
run: game 
	./$(NAME) --or $(OR) --not $(NOT) --and $(AND)

