all: split.so
.PHONY: all

split.o: split.c
	gcc -O2 -fpic -I/usr/local/include/lua -c split.c

split.so: split.o
	gcc -O -shared -fpic -o split.so split.o

clean:
	rm -f split.o split.so
