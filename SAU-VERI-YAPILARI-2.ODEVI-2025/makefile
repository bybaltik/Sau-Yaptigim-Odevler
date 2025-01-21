all:derle calistir
derle:
	g++ -I ./include/ -o ./lib/main.o -c ./src/main.cpp
	g++ -I ./include/ -o ./lib/Bst.o -c ./src/Bst.cpp
	g++ -I ./include/ -o ./lib/CustomQueue.o -c ./src/CustomQueue.cpp  
	g++ -I ./include/ -o ./lib/NodeQueue.o -c ./src/NodeQueue.cpp
	
	g++ -I ./include/ -o ./bin/program ./lib/Bst.o ./lib/CustomQueue.o ./lib/NodeQueue.o ./src/main.cpp 
calistir:
	./bin/program