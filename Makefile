CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

wordgen: WordGen.o Distribution.o
	g++ -o wordgen WordGen.o Distribution.o

WordGen.o: WordGen.cpp Distribution.h
	g++ -c WordGen.cpp $(CFLAGS)

Distribution.o: Distribution.cpp Distribution.h
	g++ -c Distribution.cpp $(CFLAGS)

.PHONY: clean
clean:
	rm -f *.o main wordgen
