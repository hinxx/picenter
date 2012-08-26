#include "PluginViet.h"
#include "PluginChooser.h"
#include "../conf.h"
#include "../generic.h"
#include "SimpleEntryURL.h"
#include <cstdlib>

extern SDL_Surface* screen;
extern PluginBase* grp;

PluginViet::PluginViet(){
    addEntry(new SimpleEntryURL("VTV1", std::string(LINK_VTV1), COLOR_FRONT_R, COLOR_FRONT_G, COLOR_FRONT_B));

    draw();
}

void PluginViet::input(const SDL_Event& event){
    PluginEntry::input(event);

    if(event.type==SDL_KEYDOWN){
	if(event.key.keysym.sym==SDLK_ESCAPE){
	    delete this;
	    grp = new PluginChooser();
	}
	else{
	    if(event.key.keysym.sym==SDLK_RETURN)
		pressReturn();

	    draw();
	}
    }
}

void PluginViet::pressReturn(){
    const std::string url = getEntry(m_active).getURL();

#ifdef PI
    std::string cmd = "omxplayer --adev ";
    //std::string cmd = "omxplayer --adev ";
    cmd += ADEV;
    cmd += ADDCMD;
#else
    std::string cmd = "mplayer";
#endif

    cmd += " '"+url+"'";

    SDL_FreeSurface(screen);
    TTF_Quit();
    SDL_Quit();

    system(cmd.c_str());

    // workaround for OMXPlayer stealing the framebuffer
#ifdef PI
    system("fbset -depth 8 && fbset -depth 16");
#endif

    init();
}
