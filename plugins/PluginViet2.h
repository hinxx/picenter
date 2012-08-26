#ifndef PLUGIN_VIET2_H
#define PLUGIN_VIET2_H

#include "PluginEntry.h"

#include <list>
#include <string>

struct LabelLink2{
    LabelLink2(const char* nlabel, const char* nurl, const char* nswfurl, const char* npageurl) { label=std::string(nlabel); url=std::string(nurl); swfurl=std::string(nswfurl); pageurl=std::string(npageurl);}

    std::string label;
    std::string url;
    std::string swfurl;
    std::string pageurl;
};

class PluginViet2 : public PluginEntry{
    public:
	PluginViet2();
	~PluginViet2()  {}

	virtual const char* title() { return "Vietnamese live TV"; }

	virtual void input(const SDL_Event& event);
	void pressReturn();

    private:
	std::vector<LabelLink2> my_entries;
};

#endif
