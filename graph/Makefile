test : test.o graph.o connected.o stack.o queue.o criticalPath.o
	gcc $^ -o $@

test.o : test.c
	gcc -c test.c
graph.o : graph.c
	gcc -c graph.c
connected.o : connected.c
	gcc -c connected.c
criticalPath.o : criticalPath.c
	gcc -c criticalPath.c
stack.o : stack.c stack.h
	gcc -c stack.c
queue.o : queue.c queue.h
	gcc -c queue.c

clean :
	rm test *.o