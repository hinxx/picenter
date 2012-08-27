#ifndef PLUGIN_BASE_H
#define PLUGIN_BASE_H

#include <SDL/SDL.h>

class PluginBase{
    public:
	virtual ~PluginBase() {}

	virtual bool	    input(const SDL_Event& event);
	virtual	void	    draw()			    = 0;
	virtual const char* title()			    = 0;
};

#endif
