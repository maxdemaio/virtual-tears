
all: cpu-api test

clean:
	rm -f p1 p2 p3 p4

cpu-api: cpu-api.c
	gcc -o cpu-api cpu-api.c -Wall

test: test.c
	gcc -o test test.c -Wall
