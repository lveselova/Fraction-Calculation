
# @author Liza Veselova
CC=g++
CFLAGS=-g -std=c++11 -O3 -Wall -Wpointer-arith -Wcast-qual -Wwrite-strings

p5: driver.cpp fraction.o
	$(CC) $(CFLAGS) -o fraction driver.cpp fraction.o

fraction.o: fraction.cpp fraction.h fraction_exception.h
	$(CC) $(CFLAGS) -c fraction.cpp

clean:
	rm *.o fraction