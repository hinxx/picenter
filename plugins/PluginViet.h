#ifndef PLUGIN_VIET_H
#define PLUGIN_VIET_H

#include "PluginEntry.h"

#include <list>
#include <string>

#define LINK_VTV1 "http://112.197.2.16:1935/live/vtv1.stream/playlist.m3u8"
#define LINK_VTV2 "http://112.197.2.16:1935/live/vtv2.stream/playlist.m3u8"

struct LabelLink{
    LabelLink(const char* nlabel, const char* nurl) { label=std::string(nlabel); url=std::string(nurl); }

    std::string label;
    std::string url;
};

class PluginViet : public PluginEntry{
    public:
	PluginViet();
	~PluginViet()  {}

	virtual const char* title() { return "Vietnamese live TV"; }

	virtual void input(const SDL_Event& event);
	void pressReturn();

    private:
	std::list<LabelLink>& getLabelLinkList();
};

#endif
