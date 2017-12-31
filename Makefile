CC=/usr/local/Cellar/llvm/5.0.0/bin/clang
CFLAGS=-I. -g
DEPS=../log/log.c

all: test

clean:
	rm -f test *.o

test: test.c stack.c $(DEPS)
	$(CC) -o test test.c stack.c $(DEPS) $(CFLAGS)


