DfsWithDirectedGraph.out :	DepthFirstPaths.o DfsWithDirectedGraph.o Graph.o LinkedList.o
			g++ DepthFirstPaths.o DfsWithDirectedGraph.o Graph.o LinkedList.o -o DfsWithDirectedGraph.out

DfsWithDirectedGraph.o 	 : 	DfsWithDirectedGraph.cpp
			g++ -c DfsWithDirectedGraph.cpp -std=c++11

DepthFirstPaths.o :	DepthFirstPaths.cpp 
			g++ -c DepthFirstPaths.cpp -std=c++11
			
Graph.o : Graph.cpp
			g++ -c Graph.cpp -std=c++11

LinkedList.o :	LinkedList.cpp
			g++ -c LinkedList.cpp -std=c++11
