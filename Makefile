CC = gcc
GTK_FLAGS := $(shell pkg-config --cflags gtk+-3.0)
GTK_LIBS := $(shell pkg-config --libs gtk+-3.0)


all: 0exp.out 1exp.out 2exp.out

0exp.out: 0exp.c
	$(CC) $(GTK_FLAGS) -o 0exp.out 0exp.c $(GTK_LIBS)


1exp.out: 1exp.c
	$(CC) $(GTK_FLAGS) -o 1exp.out 1exp.c $(GTK_LIBS)

1exp.out: 2exp.c
	$(CC) $(GTK_FLAGS) -o 2exp.out 2exp.c $(GTK_LIBS)

clean:
	rm *.out
