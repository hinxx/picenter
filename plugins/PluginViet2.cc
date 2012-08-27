#include "PluginViet2.h"
#include "PluginManager.h"
#include "../conf.h"
#include "../generic.h"
#include "SimpleEntryURL.h"
#include <cstdlib>

extern SDL_Surface* screen;
extern PluginBase* grp;

#include<iostream>
PluginViet2::PluginViet2(){
    my_entries.clear();

    add("VTV1", "rtmp://66.160.142.197:1935/live/vtv11", "http://vtc.com.vn/player.swf", "http://vtc.com.vn/#/VOX1/15");
    add("VTV2", "rtmp://66.160.142.197:1935/live/vtv2", "http://vtc.com.vn/player.swf", "http://vtc.com.vn/#/VOX2/23");
    add("VTV3", "rtmp://66.160.142.197:1935/live/vtv31", "http://vtc.com.vn/player.swf", "http://vtc.com.vn/#/VOX3/27");
    add("VTV4", "rtmp://66.160.142.197:1935/live/vtv4", "http://vtc.com.vn/player.swf", "http://vtc.com.vn/#/VOX4/2");
    //add("VTV6", "rtmp://112.197.2.11:1935/live/vtv6", "http://tv24.com.vn/WebMedia/mediaplayer/vplayer.swf", "http://www.vtc.com.vn/#/HTV/5");
    add("HanoiTV", "rtmp://66.160.142.197:1935/live/hanoill", "http://vtc.com.vn/player.swf", "http://vtc.com.vn/#/HTV/5");
    add("HTV7", "rtmp://66.160.142.197:1935/live/htv7", "http://vtc.com.vn/player.swf", "http://vtc.com.vn/#/HTV7/24");
    add("HTV9", "rtmp://66.160.142.197:1935/live/htv91", "http://vtc.com.vn/player.swf", "http://vtc.com.vn/#/HTV9/4");
    add("VTC", "rtmp://66.160.142.197:1935/live/vtc11", "http://vtc.com.vn/player.swf", "http://vtc.com.vn/#/VTC1/10");

    draw();
}

void PluginViet2::input(const SDL_Event& event){
    PluginEntry::input(event);

    if(event.type==SDL_KEYDOWN){
	if(event.key.keysym.sym==SDLK_ESCAPE){
	    delete this;
	    grp = new PluginManager();
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
    //system("mplayer stream.tmp");
    system("omxplayer -o hdmi -r stream.tmp");
    system("killall -9 rtmpdump");
    system("rm stream.tmp");

    // workaround for OMXPlayer stealing the framebuffer
#ifdef PI
    system("fbset -depth 8 && fbset -depth 16");
#endif

    init();
}

void PluginViet2::add(const char* nlabel, const char* nurl, const char* nswfurl, const char* npageurl){
    addEntry(new SimpleEntryURL(std::string(nlabel), std::string(nurl), COLOR_FRONT_R, COLOR_FRONT_G, COLOR_FRONT_B));
    my_entries.push_back(LabelLink2(nlabel, nurl, nswfurl, npageurl));
}
