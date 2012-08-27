#ifndef PLUGIN_MANAGER_H
#define PLUGIN_MANAGER_H

#include "PluginEntry.h"
#include "PluginBase.h"

class PluginManager : public PluginEntry{
    public:
	PluginManager();

	virtual const char* title() { return "Plugin chooser"; }

	virtual void	pressReturn();

	virtual bool	input(const SDL_Event& event);

	virtual	void	draw();

    private:
	PluginBase* plugin;
};

#endif
