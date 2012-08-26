#include "PluginChooser.h"
#include "../conf.h"

#include <cstdlib>
#include <SDL/SDL_ttf.h>

#ifdef PLUGIN_VIDEO
#include "PluginFile.h"
#endif

extern SDL_Surface* screen;
extern PluginBase* grp;

PluginChooser::PluginChooser(){
#ifdef PLUGIN_VIDEO
    addEntry("Video files", "VIDEO", COLOR_PLUGIN_R, COLOR_PLUGIN_G, COLOR_PLUGIN_B);
#endif

    draw();
}

void PluginChooser::pressReturn(){
#ifdef PLUGIN_VIDEO
    if(getEntry(m_active).getURL()=="VIDEO"){
	delete this;
	grp = new PluginFile();
    }
#endif
}

void PluginChooser::input(const SDL_Event& event){
    PluginEntry::input(event);

    if(event.type==SDL_KEYDOWN){
	if(event.key.keysym.sym==SDLK_RETURN)
	    pressReturn();
	else if(event.key.keysym.sym==SDLK_ESCAPE){
	    SDL_FreeSurface(screen);
	    TTF_Quit();
	    SDL_Quit();
	    exit(0);
	}
    }
}
