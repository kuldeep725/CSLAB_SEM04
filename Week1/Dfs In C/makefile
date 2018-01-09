all : DfsWithDirectedGraph.out valgrind
DfsWithDirectedGraph.out :	DepthFirstPaths.o DfsWithDirectedGraph.o Graph.o LinkedList.o
			gcc DepthFirstPaths.o DfsWithDirectedGraph.o Graph.o LinkedList.o -o DfsWithDirectedGraph.out

DfsWithDirectedGraph.o 	 : 	DfsWithDirectedGraph.c
			gcc -c DfsWithDirectedGraph.c

DepthFirstPaths.o :	DepthFirstPaths.c 
			gcc -c DepthFirstPaths.c
			
Graph.o : Graph.c
			gcc -c Graph.c 

valgrind :
			valgrind ./DfsWithDirectedGraph.out

LinkedList.o :	LinkedList.c
			gcc -c LinkedList.c

clean :	
			rm *.o *.out