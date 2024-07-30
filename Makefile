CC=gcc

all: build/sample

build/sample: build/sample.o build/args.o
	mkdir -p build
	$(CC) build/sample.o build/args.o -o build/sample

build/sample.o: src/sample.c
	mkdir -p build
	$(CC) -c src/sample.c -o build/sample.o

build/args.o: src/args.c
	mkdir -p build
	$(CC) -c src/args.c -o build/args.o

.PHONY: clean
clean:
	rm -rf build
