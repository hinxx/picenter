#include "PluginJupiterbroadcasting.h"
#include "PluginManager.h"
#include "../conf.h"
#include "../generic.h"
#include "SimpleEntryURL.h"
#include <cstdlib>

extern SDL_Surface* screen;

typedef PluginEntry __Base;

PluginJupiterbroadcasting::PluginJupiterbroadcasting(){
    addEntry(new SimpleEntryURL(std::string("LIVE"), std::string("http://videocdn-us.geocdn.scaleengine.net/jblive-iphone/live/jblive.stream/playlist.m3u8?wowzasessionid=1759286145"), COLOR_FRONT_R, COLOR_FRONT_G, COLOR_FRONT_B));

    draw();
}

bool PluginJupiterbroadcasting::input(const SDL_Event& event){
    if(__Base::input(event)==true)
	return true;
    else{
	if(event.type==SDL_KEYDOWN){
	    if(event.key.keysym.sym==SDLK_RETURN)
		pressReturn();

	    draw();
	}
    }

    return false;
}

void PluginJupiterbroadcasting::pressReturn(){
    const std::string url = static_cast<SimpleEntryURL*>(m_entries[m_active])->getURL();

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
