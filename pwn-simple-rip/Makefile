CC=gcc
CFLAGS=-m32 -fno-stack-protector
LDFLAGS=-m32 -no-pie

BIN=server
SRC=bof2.c visualize.c 


.PHONY: all clean test

all: $(BIN) 

test: all
	python solve.py --host process

$(BIN): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $^

clean:
	rm -rf $(BIN) *.o
