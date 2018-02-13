Prim.out :	Prim.o heap.o Graph.o LinkedListOfStructures.o
			gcc Prim.o heap.o Graph.o LinkedListOfStructures.o -o Prim.out

Prim.o 	 : 	Prim.c
			gcc -c Prim.c

heap.o :	heap.c 
			gcc -c heap.c
			
Graph.o : Graph.c
			gcc -c Graph.c 

LinkedListOfStructures.o :	LinkedListOfStructures.c
			gcc -c LinkedListOfStructures.c

clean :	
			rm *.o *.out