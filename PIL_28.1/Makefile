all: filter.so
.PHONY: all

filter.o: filter.c
	gcc -O2 -fpic -I/usr/local/include/lua -c filter.c

filter.so: filter.o
	gcc -O -shared -fpic -o filter.so filter.o

clean:
	rm -f filter.o filter.so 
