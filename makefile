all: forkin.o
	gcc forkin.o

run:
	./a.out

forkin.o: forkin.c
	gcc -c forkin.c

clean:
	rm *.o
	rm *.out
