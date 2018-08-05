# Includes are header files without a concrete implementation.
INCLUDES = -I./src/
# Libraries are compiled object files. -L adds a directory of libraries, -l adds a single library.
LIBS = -L./build/
# How verbose should the compiler be?
WARNINGS = -Wall -Wextra
# Chose -g to enable debugging, chose nothing otherwise
DEBUGINFO = -g 
# Compilen
# -c : compile ( nur compile, nicht link !)
# -o : object-file: name der fertigen binary
# -g : fuer debugger
COMPILE=g++ -c $(DEBUGINFO) $(WARNINGS) $(INCLUDES)
LINK=g++  $(DEBUGINFO) $(LIBS)



neuron.o:
	$(COMPILE) src/neuron.cpp -o build/neuron.o

main.o:
	$(COMPILE) src/main.cpp -o build/main.o


# Linken
main: main.o neuron.o
	$(LINK) build/main.o build/neuron.o -o build/main 

run:
	./build/main

clean:
	rm build/*.o

all: main run