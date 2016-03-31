all: dir.so
.PNONY:all

dir.o: dir.c
	gcc -O2 -fpic -I/usr/local/include/lua -c dir.c
dir.so: dir.o
	gcc -O -fpic -shared -o dir.so dir.o

clean:
	rm -f dir.o dir.so
