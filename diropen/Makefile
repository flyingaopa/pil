all: dir.so
.PNONY:all

dir.o: dir.c
	gcc -O2 -fpic -I/home/cloud/lua-5.3.2/install/include -c dir.c
dir.so: dir.o
	gcc -O -fpic -shared -o dir.so dir.o

clean:
	rm -f dir.o dir.so
