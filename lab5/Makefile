all: ODBC

%.o: %.c
	gcc -g -O0 -Wall -Werror -c $<

ODBC: main.o read.o insert.o delete.o search.o
	gcc -o $@ $^ -lodbc

clean:
	rm -rf *.o ODBC *~
