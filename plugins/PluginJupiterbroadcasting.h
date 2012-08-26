#ifndef PLUGIN_JUPITERBROADCASTING_H
#define PLUGIN_JUPITERBROADCASTING_H

#include "PluginEntry.h"

#include <list>
#include <string>


class PluginJupiterbroadcasting : public PluginEntry{
    public:
	PluginJupiterbroadcasting();
	~PluginJupiterbroadcasting()  {}

	virtual const char* title() { return "Jupiterbroadcasting"; }

	virtual void input(const SDL_Event& event);
	void pressReturn();
};

#endif
