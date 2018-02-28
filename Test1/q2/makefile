a.out :		q2.o heap.o Graph.o LinkedListOfStructures.o
			gcc q2.o heap.o Graph.o LinkedListOfStructures.o -o a.out

q2.o : 	q2.c
			gcc -c q2.c			

heap.o :	heap.c 
			gcc -c heap.c
			
Graph.o : Graph.c
			gcc -c Graph.c 

LinkedListOfStructures.o :	LinkedListOfStructures.c
			gcc -c LinkedListOfStructures.c
clean :	
			rm *.o *.out