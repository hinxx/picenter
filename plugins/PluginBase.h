#ifndef PLUGIN_BASE_H
#define PLUGIN_BASE_H

class PluginBase{
    public:
	virtual void	    input(const SDL_Event& event)   = 0;
	virtual	void	    draw()			    = 0;
	virtual const char* title()			    = 0;
};

#endif
