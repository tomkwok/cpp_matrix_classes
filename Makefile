CC?=gcc
CXX?=g++
CFLAGS=-std=c++14 -O3

benchmark:
	$(CXX) $(CFLAGS) -o ./benchmark ./benchmark.cpp

print:
	$(CXX) $(CFLAGS) -o ./print ./print.cpp

run: benchmark
	./benchmark

demo: print
	./print

clean:
	rm ./benchmark ./print

all: benchmark print

.PHONY: all run clean
