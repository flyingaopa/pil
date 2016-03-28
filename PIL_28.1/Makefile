all: filter.so
.PHONY: all

filter.o: filter.c
	gcc -O2 -fpic -I/home/cloud/lua-5.3.2/install/include -c filter.c

filter.so: filter.o
	gcc -O -shared -fpic -o filter.so filter.o

clean:
	rm -f filter.o filter.so 
