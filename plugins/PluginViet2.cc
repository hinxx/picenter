#include "PluginViet2.h"
#include "PluginChooser.h"
#include "../conf.h"
#include "../generic.h"
#include "SimpleEntryURL.h"
#include <cstdlib>

extern SDL_Surface* screen;
extern PluginBase* grp;

#include<iostream>
PluginViet2::PluginViet2(){
    my_entries.clear();

    addEntry(new SimpleEntryURL(std::string("VTV3"), std::string(""), COLOR_FRONT_R, COLOR_FRONT_G, COLOR_FRONT_B));
    my_entries.push_back(LabelLink2("VTV3", "rtmp://66.160.142.197:1935/live/vtv31", "http://vtc.com.vn/player.swf", "http://vtc.com.vn/#/VOX3/27"));

    draw();
}

void PluginViet2::input(const SDL_Event& event){
    std::cout<<"HA"<<std::endl;
    PluginEntry::input(event);
    std::cout<<"HA"<<std::endl;

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

void PluginViet2::pressReturn(){
    system("mkfifo stream.tmp");
    std::string cmd = "rtmpdump -r ";
    cmd += my_entries[m_active].url;
    cmd += " -W ";
    cmd += my_entries[m_active].swfurl;
    cmd += " -p ";
    cmd += my_entries[m_active].pageurl;
    cmd += " -v -o stream.tmp &";

    //cmd += " '"+url+"'";

    SDL_FreeSurface(screen);
    TTF_Quit();
    SDL_Quit();

    system(cmd.c_str());
    system("mplayer stream.tmp");
    //system("omxplayer -o hdmi stream.tmp");
    system("killall -9 rtmpdump");
    system("rm stream.tmp");

    // workaround for OMXPlayer stealing the framebuffer
#ifdef PI
    system("fbset -depth 8 && fbset -depth 16");
#endif

    init();
}
