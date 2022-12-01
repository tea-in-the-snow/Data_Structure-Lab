test : test.o myString.o myMatrix.o
	gcc $^ -o $@

test.o : test.c
	gcc -c test.c
myString.o : myString.c
	gcc -c myString.c
myMatrix.o : myMatrix.c
	gcc -c myMatrix.c

clean :
	rm test test.o myString.o