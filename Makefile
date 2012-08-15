CC	= g++
CFLAGS	= -Wall
LDFLAGS	= -I/usr/local/include -L/usr/local/lib -lSDL -lSDL_ttf

OBJ = main.o EntryGroup.o EntryGroup_File.o generic.o

picenter: $(OBJ)
	$(CC) $(CFLAGS) -o picenter $(OBJ) $(LDFLAGS)

%.o: %.cc
	$(CC) $(CFLAGS) -c $<

clean:
	rm -r *.o picenter
