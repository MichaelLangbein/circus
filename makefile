# Makefile-semantics:
# fileToBuild: dependencies to check for updates
# 	buildinstructions


# Includes are header files without a concrete implementation. 
# Adding an entry to -I makes that you don't need to spell out the full path in #include "neuron.hpp", 
# but you still need to give the full path to g++.
INCLUDES = -I./src/ -I./src/linalg/ -I./src/nn/
# Libraries are compiled object files. -L adds a directory of libraries, -l adds a single library.
LIBS = -L./build/

# How verbose should the compiler be?
WARNINGS = -Wall -Wextra
# Chose -g to enable debugging, chose nothing otherwise
DEBUGINFO = -g 
# What standard should be compiled?
STANDARD = -std=c++11
# -c : compile ( nur compile, nicht link !)
# -o : outputfile-name: name der fertigen binary
# -g : fuer debugger
COMPILE=g++ -c $(STANDARD) $(DEBUGINFO) $(WARNINGS) $(INCLUDES)
LINK=g++ $(STANDARD) $(DEBUGINFO) $(LIBS)



build/vector.o: src/linalg/vector.cpp
	$(COMPILE) src/linalg/vector.cpp -o build/vector.o

build/matrix.o: src/linalg/matrix.cpp
	$(COMPILE) src/linalg/matrix.cpp -o build/matrix.o

build/connection.o: src/nn/connection.cpp
	$(COMPILE) src/nn/connection.cpp -o build/connection.o

build/layer.o: src/nn/layer.cpp
	$(COMPILE) src/nn/layer.cpp -o build/layer.o

build/nn.o: src/nn/nn.cpp 
	$(COMPILE) src/nn/nn.cpp -o build/nn.o

build/main.o: src/main.cpp
	$(COMPILE) src/main.cpp -o build/main.o

build/main: build/main.o build/nn.o build/layer.o build/connection.o build/matrix.o build/vector.o
	$(LINK) build/main.o build/nn.o build/layer.o build/connection.o build/matrix.o build/vector.o -o build/main 

run:
	./build/main

analyse: build/main
	valgrind --leak-check=yes build/main

clean:
	rm build/*.o

all: build/main run

build/matrixTest.o: test/matrixTest.cpp
	$(COMPILE) test/matrixTest.cpp -o build/matrixTest.o

test: build/matrix.o build/vector.o build/matrixTest.o
	$(LINK) build/matrix.o build/vector.o build/matrixTest.o -o build/matrixTest
	./build/matrixTest 
	