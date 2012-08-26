#include "PluginJupiterbroadcasting.h"
#include "PluginChooser.h"
#include "../conf.h"
#include "../generic.h"
#include "SimpleEntryURL.h"
#include <cstdlib>

extern SDL_Surface* screen;
extern PluginBase* grp;

PluginJupiterbroadcasting::PluginJupiterbroadcasting(){
    addEntry(new SimpleEntryURL(std::string("LIVE"), std::string("http://videocdn-us.geocdn.scaleengine.net/jblive-iphone/live/jblive.stream/playlist.m3u8?wowzasessionid=1759286145"), COLOR_FRONT_R, COLOR_FRONT_G, COLOR_FRONT_B));

    draw();
}

void PluginJupiterbroadcasting::input(const SDL_Event& event){
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

void PluginJupiterbroadcasting::pressReturn(){
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
