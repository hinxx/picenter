#ifndef PLUGIN_MANAGER_H
#define PLUGIN_MANAGER_H

#include "PluginEntry.h"

class PluginManager : public PluginEntry{
    public:
	PluginManager();

	virtual const char* title() { return "Plugin chooser"; }

	virtual void pressReturn();

	virtual void input(const SDL_Event& event);
};

#endif
