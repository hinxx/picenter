#ifndef PLUGIN_VIET_H
#define PLUGIN_VIET_H

#include "PluginEntry.h"

#define LINK_VTV1 "http://112.197.2.16:1935/live/vtv1.stream/playlist.m3u8"

class PluginViet : public PluginEntry{
    public:
	PluginViet();
	~PluginViet()  {}

	virtual const char* title() { return "Vietnamese live TV"; }

	virtual void input(const SDL_Event& event);
	void pressReturn();
};

#endif
