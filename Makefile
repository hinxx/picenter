CC	= g++
HOST	= $(uname -a)

ifeq (HOST, raspberrypi)
	CFLAGS	= -Wall -march=armv6 -mfpu=vfp -mfloat-abi=hard -Iplugins
else
	CFLAGS	= -Wall -Iplugins
endif

LDFLAGS	= -lSDL -lSDL_ttf

OBJ = main.o generic.o
OBJPLUGINS = plugins/EntryGroup.o plugins/EntryGroup_File.o

include settings.mak

ifdef LOG
    CFLAGS += -DLOG
endif

picenter: $(OBJ) $(OBJPLUGINS) Makefile settings.mak
	$(CC) $(CFLAGS) -o picenter $(OBJ) $(OBJPLUGINS) $(LDFLAGS)

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJPLUGINS) picenter
