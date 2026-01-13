CC=g++
CFLAGS=-I.
LIBS=-lJHCap
DEPS = JHCap.h
OBJ = console.o bmpfile.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

console: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o *~ core *.bmp console
