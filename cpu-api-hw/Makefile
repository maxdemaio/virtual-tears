
all: cpu-api1 cpu-api2 cpu-api3 cpu-api4 test

clean:
	rm -f cpu-api1 cpu-api2 test

cpu-api1: cpu-api1.c
	gcc -o cpu-api1 cpu-api1.c -Wall

cpu-api2: cpu-api2.c
	gcc -o cpu-api2 cpu-api2.c -Wall

cpu-api3: cpu-api3.c
	gcc -o cpu-api3 cpu-api3.c -Wall

cpu-api4: cpu-api4.c
	gcc -o cpu-api4 cpu-api4.c -Wall

test: test.c
	gcc -o test test.c -Wall
