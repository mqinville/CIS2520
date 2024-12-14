a2q1: q1.h q1.o q1fn.o
	gcc -Wall -std=c99 -pedantic q1.o q1_functions.o

q1.o: q1.h q1.c  
	gcc -Wall -std=c99 -pedantic q1.c

q1_functions.o: q1.h q1_functions.c
	gcc -Wall -std=c99 -pedantic q1_functions.c

clean:
	rm *.o


