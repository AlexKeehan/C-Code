CC = gcc
CFLAGS = -g -Wall

default: bamazon

bamazon: main.c bamazon.c bamazon.h
	$(CC) $(CFLAGS) -o bamazon main.c bamazon.c bamazon.h
main.o: main.c bamazon.c bamazon.h
	$(CC) $(CFLAGS) -c main.c

bamazon.o: bamazon.c bamazon.h
	$(CC) $(CFLAGS) -c bamazon.c

clean:
	rm -f bamazon *.o
