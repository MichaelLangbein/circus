# Includes are header files without a concrete implementation.
INCLUDES = -I.
# Libraries are compiled object files. -L adds a directory of libraries , -l adds a single library.
LIBS = -L.
# How verbose should the compiler be?
WARNINGS = -Wall -Wextra
# Chose -g to enable debugging, chose nothing otherwise
DEBUGINFO = -g 


# Compilen
# -c : compile ( nur compile, nicht link !)
# -g : fuer debugger

neuron.o:
	gcc $(DEBUGINFO) -c $(WARNINGS) $(INCLUDES) src/neuron.cpp -o build/neuron.o

main.o:
	gcc $(DEBUGINFO) -c $(WARNINGS) $(INCLUDES) src/main.cpp -o build/main.o

# Linken
# -o : object-file: name der fertigen binary
# -g : fuer debugger

main: main.o neuron.o
	gcc $(DEBUGINFO) $(LIBS) build/main.o build/neuron.o -o build/main 

run:
	./main

clean:
	rm build/*.o

all: main clean run