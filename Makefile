CC	:= g++
HOST	:= $(shell uname -n)

ifeq ($(HOST), raspberrypi)
	CFLAGS	:= -Wall -march=armv6 -mfpu=vfp -mfloat-abi=hard -Iplugins -DPI
else
	CFLAGS	:= -Wall -Iplugins -I/usr/local/include -L/usr/local/lib
endif

LDFLAGS	= -lSDL -lSDL_ttf

OBJ = main.o generic.o
OBJPLUGINS = plugins/SimpleEntry.o plugins/PluginEntry.o plugins/PluginFile.o

include settings.mak

ifdef LOG
    CFLAGS += -DLOG
endif

picenter: $(OBJ) $(OBJPLUGINS) Makefile settings.mak conf.h
	$(CC) $(CFLAGS) -o picenter $(OBJ) $(OBJPLUGINS) $(LDFLAGS)

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJPLUGINS) picenter
