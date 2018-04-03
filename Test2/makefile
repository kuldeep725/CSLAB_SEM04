kruskal.out :	kruskal.o heap.o Graph.o LinkedListOfStructures.o
			gcc kruskal.o heap.o Graph.o LinkedListOfStructures.o -o kruskal.out

kruskal.o 	 : 	kruskal.c
			gcc -c kruskal.c

heap.o :	heap.c 
			gcc -c heap.c
			
Graph.o : Graph.c
			gcc -c Graph.c 

LinkedListOfStructures.o :	LinkedListOfStructures.c
			gcc -c LinkedListOfStructures.c

clean :	
			rm *.o *.out