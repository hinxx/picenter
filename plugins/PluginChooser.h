#ifndef PLUGIN_CHOOSER_H
#define PLUGIN_CHOOSER_H

#include "PluginEntry.h"

class PluginChooser : public PluginEntry{
    public:
	PluginChooser();

	virtual const char* title() { return "Plugin chooser"; }

	virtual void pressReturn();

	virtual void input(const SDL_Event& event);
};

#endif
