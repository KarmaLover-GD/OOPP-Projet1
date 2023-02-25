# Tools & flags
CC=g++
CFLAGS=--std=c++17 -Wall -Wextra 
LD=g++
LDFLAGS=

# Files
EXEC=markov
MODULES=main.cpp markov_model.cpp 
OBJECTS=main.o markov_model.o

all: $(EXEC)

markov: $(OBJECTS)
    $(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS)

main.o: main.cpp 
    $(CC) -c main.cpp -o main.o $(CFLAGS)

markov_model.o: markov_model.cpp 
    $(CC) -c markov_model.cpp -o markov_model.o $(CFLAGS)


clean:
    rm -f *.o $(EXEC) *~