
CXXFLAGS=-Wall -Wconversion -Wextra -pedantic


all: main

main: main.cpp DiGraph.o Util.o DirectedCycle.h ParcoursEnProfondeur.h SymbolGraph.h TopologicalSort.h


clean:
	rm -fr *.o main
install:
	echo "Don't install"
run:
	./main
