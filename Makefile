CC	= g++
CFLAGS	= -Wall
LDFLAGS	= -I/usr/local/include -L/usr/local/lib -lSDL -lSDL_ttf

OBJ = main.o EntryGroup.o EntryGroup_File.o generic.o

include settings.mak

ifdef LOG
    CFLAGS += -DLOG
endif

picenter: $(OBJ) Makefile settings.mak
	$(CC) $(CFLAGS) -o picenter $(OBJ) $(LDFLAGS)

%.o: %.cc
	$(CC) $(CFLAGS) -c $<

clean:
	rm -r *.o picenter
