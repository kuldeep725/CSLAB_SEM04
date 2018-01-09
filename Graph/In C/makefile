test.out :		Graph.o test.o 
				gcc test.o LinkedList.o Graph.o -o test.out

Graph.o : 		LinkedList.o Graph.c
				gcc -c Graph.c

LinkedList.o :	LinkedList.c
				gcc -c LinkedList.c

test.o 	 : 		test.c
				gcc -c test.c