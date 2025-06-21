CC = clang
CFLAGS = -std=c99 -Wall -Wextra $(shell pkg-config --cflags raylib)
LDFLAGS = $(shell pkg-config --libs raylib)
SRC = src/main.c
OUT = main

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

clean:
	rm -f $(OUT)
