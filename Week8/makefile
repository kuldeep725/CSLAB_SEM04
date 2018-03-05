BellmanFord.out :	BellmanFord.o Graph.o LinkedListOfStructures.o
			gcc BellmanFord.o Graph.o LinkedListOfStructures.o -o BellmanFord.out

BellmanFord.o 	 : 	BellmanFord.c
			gcc -c BellmanFord.c
			
Graph.o : Graph.c
			gcc -c Graph.c 

LinkedListOfStructures.o :	LinkedListOfStructures.c
			gcc -c LinkedListOfStructures.c

clean :	
			rm *.o *.out