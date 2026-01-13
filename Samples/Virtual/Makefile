CC=g++
CFLAGS=-I.
LIBS=-lJHCap
DEPS = JHCap.h
OBJ = virtual.o bmpfile.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

virtual: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o *~ core *.bmp virtual 
