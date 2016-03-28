all: split.so
.PHONY: all

split.o: split.c
	gcc -O2 -fpic -I/home/cloud/lua-5.3.2/install/include -c split.c

split.so: split.o
	gcc -O -shared -fpic -o split.so split.o

clean:
	rm -f split.o split.so
