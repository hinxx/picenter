CC	= g++
HOST	= $(uname -a)

ifeq (HOST, raspberrypi)
	CFLAGS	= -Wall -march=armv6 -mfpu=vfp -mfloat-abi=hard
else
	CFLAGS	= -Wall
endif

LDFLAGS	= -lSDL -lSDL_ttf

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
