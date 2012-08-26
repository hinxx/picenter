CC	:= g++
HOST	:= $(shell uname -n)

ifeq ($(HOST), raspberrypi)
	CFLAGS	:= -Wall -march=armv6 -mfpu=vfp -mfloat-abi=hard -Iplugins -DPI
else
	CFLAGS	:= -Wall -Iplugins -I/usr/local/include -L/usr/local/lib
endif

LDFLAGS	= -lSDL -lSDL_ttf

OBJ = main.o generic.o
OBJPLUGINS = plugins/SimpleEntry.o plugins/PluginEntry.o plugins/PluginChooser.o

include settings.mak

ifdef LOG
    CFLAGS += -DLOG
endif

ifdef DEBUG
    CFLAGS += -g
endif

ifdef PLUGIN_VIDEO
    OBJPLUGINS += plugins/PluginFile.o plugins/SimpleEntryFile.o
    CFLAGS += -DPLUGIN_VIDEO
endif

ifdef PLUGIN_VIET
    OBJPLUGINS += plugins/PluginViet.o
    CFLAGS += -DPLUGIN_VIET
endif

ifdef PLUGIN_VIET2
    OBJPLUGINS += plugins/PluginViet2.o
    CFLAGS += -DPLUGIN_VIET2
endif

ifdef PLUGIN_JUPITERBROADCASTING
    OBJPLUGINS += plugins/PluginJupiterbroadcasting.o
    CFLAGS += -DPLUGIN_JUPITERBROADCASTING
endif

picenter: $(OBJ) $(OBJPLUGINS) Makefile settings.mak conf.h
	$(CC) $(CFLAGS) -o picenter $(OBJ) $(OBJPLUGINS) $(LDFLAGS)

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJPLUGINS) picenter

remake: clean picenter
