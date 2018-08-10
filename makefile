# Makefile-semantics:
# fileToBuild: dependencies to check for updates
# 	buildinstructions


# Includes are header files without a concrete implementation. 
# Adding an entry to -I makes that you don't need to spell out the full path in #include "neuron.hpp", 
# but you still need to give the full path to g++.
INCLUDES = -I./src/
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


build/neuron.o: src/neuron.cpp
	$(COMPILE) src/neuron.cpp -o build/neuron.o

build/connection.o: src/connection.cpp
	$(COMPILE) src/connection.cpp -o build/connection.o

build/layer.o: src/layer.cpp
	$(COMPILE) src/layer.cpp -o build/layer.o

build/nn.o: src/nn.cpp 
	$(COMPILE) src/nn.cpp -o build/nn.o

build/main.o: src/main.cpp
	$(COMPILE) src/main.cpp -o build/main.o

build/main: build/main.o build/nn.o build/layer.o build/connection.o
	$(LINK) build/main.o build/nn.o build/layer.o build/connection.o -o build/main 

run:
	./build/main

build/neuronTest.o: test/neuronTest.cpp
	$(COMPILE) test/neuronTest.cpp -o build/neuronTest.o

test: build/neuron.o build/neuronTest.o
	$(LINK) build/neuron.o build/neuronTest.o -o build/neuronTest
	./build/neuronTest 

clean:
	rm build/*.o

all: build/main run
