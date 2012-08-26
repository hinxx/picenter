#include "PluginChooser.h"
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

PluginChooser::PluginChooser(){
#ifdef PLUGIN_VIDEO
    addEntry("Video files", "VIDEO", COLOR_PLUGIN_R, COLOR_PLUGIN_G, COLOR_PLUGIN_B);
#endif
#ifdef PLUGIN_VIET
    addEntry("Vietnam live TV", "VIET", COLOR_PLUGIN_R, COLOR_PLUGIN_G, COLOR_PLUGIN_B);
#endif
#ifdef PLUGIN_VIET2
    addEntry("Vietnam live TV (RTMP streams)", "VIET2", COLOR_PLUGIN_R, COLOR_PLUGIN_G, COLOR_PLUGIN_B);
#endif
#ifdef PLUGIN_JUPITERBROADCASTING
    addEntry("Jupiterbroadcasting", "JUPITERBROADCASTING", COLOR_PLUGIN_R, COLOR_PLUGIN_G, COLOR_PLUGIN_B);
#endif

    draw();
}

void PluginChooser::pressReturn(){
#ifdef PLUGIN_VIDEO
    if(getEntry(m_active).getURL()=="VIDEO"){
	//delete this;
	grp = new PluginFile();
    }
#endif
#ifdef PLUGIN_VIET
    if(getEntry(m_active).getURL()=="VIET"){
	//delete this;
	grp = new PluginViet();
    }
#endif
#ifdef PLUGIN_VIET2
    if(getEntry(m_active).getURL()=="VIET2"){
	//delete this;
	grp = new PluginViet2();
    }
#endif
#ifdef PLUGIN_JUPITERBROADCASTING
    if(getEntry(m_active).getURL()=="JUPITERBROADCASTING"){
	//delete this;
	grp = new PluginJupiterbroadcasting();
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
