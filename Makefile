CC = emcc
CFLAGS = -O2 -Wall -std=c99 -s USE_GLFW=3 -s ALLOW_MEMORY_GROWTH=1 -DPLATFORM_WEB
LDFLAGS = -s WASM=1 -s EXIT_RUNTIME=1 -s USE_GLFW=3 -s ALLOW_MEMORY_GROWTH=1
SRC = src/main.c
OUT = index.html

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

clean:
	rm -f index.html index.js index.wasm
