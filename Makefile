all:
	g++ -Wall -I/usr/local/include -L/usr/local/lib -o picenter -lSDL -lSDL_ttf main.cc EntryGroup.cc EntryGroup_File.cc generic.cc
