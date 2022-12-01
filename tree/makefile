test : test.o initTree.o printTree.o opsonTree.o huffmanTree.o stack.o queue.o
	gcc $^ -o $@

test.o : test.c binaryTree.h
	gcc -c test.c
initTree.o : initTree.c binaryTree.h
	gcc -c initTree.c
printTree.o : printTree.c binaryTree.h
	gcc -c printTree.c
opsonTree.o : opsonTree.c binaryTree.h
	gcc -c opsonTree.c
huffmanTree.o : huffmanTree.c huffmanTree.h
	gcc -c huffmanTree.c
stack.o : stack.c stack.h
	gcc -c stack.c
queue.o : queue.c queue.h
	gcc -c queue.c

clean : 
	rm test test.o initTree.o printTree.o opsonTree.o huffmanTree.o queue.o stack.o