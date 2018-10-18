# ADDBRA001 Makefile Template

## FLAGS ==================================================================
CC=g++ -std=c++11
LIBS=-lm
## ========================================================================

ann2: ann2.o
	$(CC) ann2.o -o ann2 $(LIBS)


ann2.o: ann2.cpp
	$(CC) -c ann2.cpp

clean:
	@rm -f *.o
	@rm ann2

install:

	@mv ann2 ~/bin
