#include "PluginChooser.h"
#include "PluginFile.h"
#include "../conf.h"

#include <cstdlib>
#include <SDL/SDL_ttf.h>

extern SDL_Surface* screen;
extern PluginBase* grp;

PluginChooser::PluginChooser(){
#ifdef PLUGIN_VIDEO
    addEntry("Video files", "VIDEO", COLOR_PLUGIN_R, COLOR_PLUGIN_G, COLOR_PLUGIN_B);
#endif

    draw();
}

void PluginChooser::pressReturn(){
    //switch(getEntry(m_active).getURL()){
    //    case "VIDEO":
    //        grp = new PluginFile();
    //}
    if(getEntry(m_active).getURL()=="VIDEO"){
	delete this;
	grp = new PluginFile();
    }
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
