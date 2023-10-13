CC = gcc
CFLAGS = -g -Wall -Werror -O2
LDFLAGS = -lncurses

snake: scommons.o score.o snake.o letters.o menus.o main.o

clean:
	rm -f snake *.o
