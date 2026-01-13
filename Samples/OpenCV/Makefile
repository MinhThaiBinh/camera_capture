CC=g++
CFLAGS=-I.
LIBS=-lJHCap -lopencv_core -lopencv_highgui -lopencv_imgproc
DEPS = JHCap.h
OBJ = opencv.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

opencv: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o *~ core *.bmp opencv
