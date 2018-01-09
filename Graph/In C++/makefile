test.out :		Graph.o test.o 
				g++ test.o LinkedList.o Graph.o -o test.out

Graph.o : 		LinkedList.o Graph.cpp
				g++ -c Graph.cpp -std=c++11

LinkedList.o :	LinkedList.cpp
				g++ -c LinkedList.cpp -std=c++11

test.o 	 : 		test.cpp
				g++ -c test.cpp -std=c++11
clean 		:
			rm *.o *.out