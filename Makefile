CC=g++
CFLAGS=-std=c++14

benchmark:
	$(CC) $(CFLAGS) -o ./benchmark ./benchmark.cpp

print:
	$(CC) $(CFLAGS) -o ./print ./print.cpp

run: benchmark
	./benchmark

demo: print
	./print

clean:
	rm ./benchmark ./print

.PHONY: all run clean
