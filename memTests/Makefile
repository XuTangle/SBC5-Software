CC=gcc
CFLAGS=-I.
DEPS = memTest.h

%.o: %.c $(DEPS)
        $(CC) -c -o $@ $< $(CFLAGS)

memTest: memTest.o dataTest.o addressTest.o deviceTest.o
        $(CC) -o memTest memTest.o dataTest.o addressTest.o deviceTest.o
