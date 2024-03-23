CC=gcc
CFLAGS=-Wall -g
#----ProgramName----#
NAME=json-parser
IDIR=./include
DEP1= node

DEPS= $(IDIR)/$(DEP1).h 
OBJ= ./src/json-parser.o ./src/$(DEP1).o

%.o:%.c $(DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS) -I$(IDIR)

./bin/$(NAME): $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -rf ./bin/$(NAME) ./src/*.o

