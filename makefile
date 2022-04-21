
# @author Liza Veselova
CC=g++
CFLAGS=-g -std=c++11 -O3 -Wall -Wpointer-arith -Wcast-qual -Wwrite-strings

TARGET = 
fraction: driver.cpp fraction.o
	$(CC) $(CFLAGS) -o fraction driver.cpp fraction.o

fraction.o: fraction.cpp fraction.h fraction_exception.h
	$(CC) $(CFLAGS) -c fraction.cpp

clean:
	rm *.o fraction







	  # the compiler: gcc for C program, define as g++ for C++
  CC = g++

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -g -Wall

  # the build target executable:
  TARGET = myprog

  all: $(TARGET)

  $(TARGET): $(TARGET).c
  	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

  clean:
  	$(RM) $(TARGET)