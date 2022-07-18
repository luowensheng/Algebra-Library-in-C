CC=gcc
CFLAGS=-I.
DEPS= variable.h globals.h regex_parser.h utils.h expression.h
OBJ= main.o algebra/variable.o algebra/globals.o algebra/expression.o


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm ./*.o
	rm ./algebra/*.o

     