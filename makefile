CC=gcc
CFLAGS=-Wall -g
#----ProgramName----#
NAME=json-parser
IDIR=./include
OBJ=./src/json-parser.o 

%.o:%.c 
	$(CC) -c -o $@ $< $(CFLAGS) -I$(IDIR)

./bin/$(NAME): $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -rf ./bin/$(NAME) ./src/*.o

