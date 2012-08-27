#include "PluginManager.h"
#include "../conf.h"

#include <cstdlib>
#include <SDL/SDL_ttf.h>

#ifdef PLUGIN_VIDEO
#include "PluginFile.h"
#endif

#ifdef PLUGIN_VIET
#include "PluginViet.h"
#endif

#ifdef PLUGIN_VIET2
#include "PluginViet2.h"
#endif

#ifdef PLUGIN_JUPITERBROADCASTING
#include "PluginJupiterbroadcasting.h"
#endif

extern SDL_Surface* screen;
extern PluginBase* grp;

enum Plugin {
#ifdef PLUGIN_VIDEO
    VIDEO,
#endif
#ifdef PLUGIN_VIET
    VIET,
#endif
#ifdef PLUGIN_VIET2
    VIET2,
#endif
#ifdef PLUGIN_JUPITERBROADCASTING
    JUPITERBROADCASTING,
#endif
};

PluginManager::PluginManager(){
#ifdef PLUGIN_VIDEO
    addEntry("Video files", COLOR_PLUGIN_R, COLOR_PLUGIN_G, COLOR_PLUGIN_B);
#endif
#ifdef PLUGIN_VIET
    addEntry("Vietnam live TV", COLOR_PLUGIN_R, COLOR_PLUGIN_G, COLOR_PLUGIN_B);
#endif
#ifdef PLUGIN_VIET2
    addEntry("Vietnam live TV (RTMP streams)", COLOR_PLUGIN_R, COLOR_PLUGIN_G, COLOR_PLUGIN_B);
#endif
#ifdef PLUGIN_JUPITERBROADCASTING
    addEntry("Jupiterbroadcasting", COLOR_PLUGIN_R, COLOR_PLUGIN_G, COLOR_PLUGIN_B);
#endif

    draw();
}

void PluginManager::pressReturn(){
#ifdef PLUGIN_VIDEO
    if(m_active==VIDEO){
	//delete this;
	grp = new PluginFile();
    }
#endif
#ifdef PLUGIN_VIET
    if(m_active==VIET){
	//delete this;
	grp = new PluginViet();
    }
#endif
#ifdef PLUGIN_VIET2
    if(m_active==VIET2){
	//delete this;
	grp = new PluginViet2();
    }
#endif
#ifdef PLUGIN_JUPITERBROADCASTING
    if(m_active==JUPITERBROADCASTING){
	//delete this;
	grp = new PluginJupiterbroadcasting();
    }
#endif
}

void PluginManager::input(const SDL_Event& event){
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
