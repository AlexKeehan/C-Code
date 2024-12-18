CC = gcc           # define gcc as compiler
CFLAGS = -g -Wall  # define compiler flags, -g is debug, -Wall turns on all warngings

default: studprog

studprog: filemain.o person.o student.o
	$(CC) $(CFLAGS) -o studprog filemain.o person.o student.o

filemain.o: filemain.c person.h student.h
	$(CC) $(CFLAGS) -c filemain.c

person.o: person.c person.h
	$(CC) $(CFLAGS) -c person.c

student.o: student.c student.h person.h
	$(CC) $(CFLAGS) -c student.c

clean:
	rm -f studprog *.o
