all:derle calistir
derle:
	g++ -I ./include/ -o ./lib/Main.o -c ./src/Main.cpp
	g++ -I ./include/ -o ./lib/LinkedList.o -c ./src/LinkedList.cpp
	
	g++ -I ./include/ -o ./bin/program ./lib/LinkedList.o ./src/Main.cpp 
calistir:
	./bin/program.exe