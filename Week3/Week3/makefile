DfsWithDirectedGraph.out :	TopologicalSort.o DepthFirstPaths.o Graph.o LinkedList.o
			gcc TopologicalSort.o DepthFirstPaths.o Graph.o LinkedList.o -o TopologicalSort.out

TopologicalSort.o 	 : 	TopologicalSort.c
			gcc -c TopologicalSort.c

DepthFirstPaths.o :	DepthFirstPaths.c 
			gcc -c DepthFirstPaths.c
			
Graph.o : Graph.c
			gcc -c Graph.c 

LinkedList.o :	LinkedList.c
			gcc -c LinkedList.c

clean :	
			rm *.o *.out