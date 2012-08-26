#include "PluginViet.h"
#include "PluginChooser.h"
#include "../conf.h"
#include "../generic.h"
#include "SimpleEntryURL.h"
#include <cstdlib>

extern SDL_Surface* screen;
extern PluginBase* grp;

PluginViet::PluginViet(){
    std::list<LabelLink> lst = getLabelLinkList();
    for(std::list<LabelLink>::iterator it=lst.begin();it!=lst.end();it++){
	addEntry(new SimpleEntryURL(it->label, it->url, COLOR_FRONT_R, COLOR_FRONT_G, COLOR_FRONT_B));
    }

    draw();
}

std::list<LabelLink>& PluginViet::getLabelLinkList(){
    std::list<LabelLink>* ptr_lst = new std::list<LabelLink>;

    ptr_lst->push_back(LabelLink("VTV1", LINK_VTV1));
    ptr_lst->push_back(LabelLink("VTV2", LINK_VTV2));

    return *ptr_lst;
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
