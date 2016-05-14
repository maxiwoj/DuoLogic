IDIR=include
CC=g++
LFLAGS=-lncurses 
CFLAGS=-w -I $(IDIR)
LIBS=./lib/libncurses.so.5 ./lib/libtinfo.so.5

NAME=game
NOT=./additional/not.txt
AND=./additional/and.txt
OR=./additional/or.txt

ODIR=obj
CDIR=src

_OBJ = CreateField.o fireworks.o getScore.o menu.o play.o the_winner.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(CDIR)/%.cpp
	@mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

game: $(OBJ)
	$(CC) -o $@ $^ -Wl,-rpath,./lib $(LIBS)

config:
	$(LIBRARY)

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
	rm -if *~ *.o $(NAME)
	rm -fR obj	
	
run: game 
	./$(NAME) --or $(OR) --not $(NOT) --and $(AND)

