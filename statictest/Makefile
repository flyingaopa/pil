all: st.so
	cp st.so c1-st.so
	cp st.so c2-st.so
.PNONY: all

st.o: st.c
	gcc -O2 -fpic -I/home/cloud/lua-5.3.2/install/include -c st.c

st.so: st.o
	gcc -O -fpic -shared -o st.so st.o

clean:
	rm -f *.o *.so
