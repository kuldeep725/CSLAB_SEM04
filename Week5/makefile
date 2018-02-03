dijkstra.out :	dijkstra.o heap.o Graph.o LinkedListOfStructures.o
			gcc dijkstra.o heap.o Graph.o LinkedListOfStructures.o -o dijkstra.out

dijkstra.o 	 : 	dijkstra.c
			gcc -c dijkstra.c

heap.o :	heap.c 
			gcc -c heap.c
			
Graph.o : Graph.c
			gcc -c Graph.c 

LinkedListOfStructures.o :	LinkedListOfStructures.c
			gcc -c LinkedListOfStructures.c

clean :	
			rm *.o *.out