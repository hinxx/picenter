#include "PluginViet.h"
#include "PluginManager.h"
#include "../conf.h"
#include "../generic.h"
#include "SimpleEntryURL.h"
#include <cstdlib>

extern SDL_Surface* screen;

typedef PluginEntry __Base;

PluginViet::PluginViet(){
    addAll();

    draw();
}

void PluginViet::addLabelLink(const char* label, const char* url){
    addEntry(new SimpleEntryURL(label, url, COLOR_FRONT_R, COLOR_FRONT_G, COLOR_FRONT_B));
}

void PluginViet::addAll(){
    addLabelLink("VTV1", LINK_VTV1a);
    addLabelLink("VTV1 #2", LINK_VTV1b);
    addLabelLink("VTV2", LINK_VTV2);
    addLabelLink("VTV3", LINK_VTV3);
    addLabelLink("VTV4", LINK_VTV4);
    addLabelLink("VTV6", LINK_VTV6);
    addLabelLink("VTV9", LINK_VTV9);
    addLabelLink("HTV2", LINK_HTV2);
    addLabelLink("HTV7", LINK_HTV7a);
    addLabelLink("HTV7 #2", LINK_HTV7b);
    addLabelLink("HTV9", LINK_HTV9a);
    addLabelLink("HTV9 #2", LINK_HTV9b);
    addLabelLink("HTVCHD YeahTV", LINK_HTVCHD_YEAHTVa);
    addLabelLink("HTVCHD YeahTV #2", LINK_HTVCHD_YEAHTVb);
    addLabelLink("VTC1", LINK_VTC1);
    addLabelLink("VCTV3", LINK_VCTV3);
    addLabelLink("VTC6", LINK_VTC6a);
    addLabelLink("VTC6 #2", LINK_VTC6b);
    addLabelLink("VCTV7", LINK_VCTV7);
    addLabelLink("VTC9", LINK_VTC9);
    addLabelLink("VTC13", LINK_VTC13);
    addLabelLink("VCTV9", LINK_VCTV9);
    addLabelLink("ITV", LINK_ITV);
    addLabelLink("SCTV1", LINK_SCTV1);
    addLabelLink("SCTV2", LINK_SCTV2);
    addLabelLink("SCTV3", LINK_SCTV3);
    addLabelLink("SCTV4", LINK_SCTV4);
    addLabelLink("SCTV5", LINK_SCTV5);
    addLabelLink("SCTV6", LINK_SCTV6);
    addLabelLink("SCTV7", LINK_SCTV7);
    addLabelLink("SCTV8", LINK_SCTV8);
    addLabelLink("SCTV9", LINK_SCTV9);
    addLabelLink("SCTV10", LINK_SCTV10);
    addLabelLink("SCTV11", LINK_SCTV11);
    addLabelLink("SCTV12", LINK_SCTV12);
    addLabelLink("SCTV13", LINK_SCTV13);
    addLabelLink("SCTV14", LINK_SCTV14);
    addLabelLink("SCTV15", LINK_SCTV15);
    addLabelLink("SCTV16", LINK_SCTV16);
    addLabelLink("SCTV17", LINK_SCTV17);
    addLabelLink("SCTV18", LINK_SCTV18);
    addLabelLink("Long An", LINK_LONG_AN);
    addLabelLink("Hanoi", LINK_HANOI);
    addLabelLink("Vinh Long 1", LINK_VINH_LONG1);
    addLabelLink("Vinh Long 2", LINK_VINH_LONG2);
    addLabelLink("Hau Giang", LINK_HAU_GIANG);
    addLabelLink("Soc Trang", LINK_SOC_TRANG);
    addLabelLink("Dong Thap", LINK_DONG_THAP);
    addLabelLink("Quang Nam", LINK_QUANG_NAM);
    addLabelLink("Binh Thuan", LINK_BINH_THUAN);
    addLabelLink("ANTV", LINK_ANTV);
    addLabelLink("Dong Nai 1", LINK_DONG_NAI1);
    addLabelLink("Dong Nai 2", LINK_DONG_NAI2);
    addLabelLink("Cantho 1", LINK_CANTHO1);
    addLabelLink("Cantho 2", LINK_CANTHO2);
    addLabelLink("DanangTV", LINK_DANANGTV);
    addLabelLink("TRT1 Hue", LINK_TRT1_HUE);
    addLabelLink("TTXVN", LINK_TTXVN);
    addLabelLink("LifeTV", LINK_LIFETVa);
    addLabelLink("LifeTV #2", LINK_LIFETVb);
    addLabelLink("Binh Duong 1", LINK_BINH_DUONG1);
    addLabelLink("Binh Duong 2", LINK_BINH_DUONG2);
    addLabelLink("Daklak", LINK_DAKLAK);
    addLabelLink("An Giang", LINK_AN_GIANG);
    addLabelLink("Tien Giang", LINK_TIEN_GIANG);
    addLabelLink("Bac Lieu", LINK_BAC_LIEU);
    addLabelLink("Can Tho", LINK_CAN_THO);
    addLabelLink("Thai Nguyen", LINK_THAI_NGUYEN);
    addLabelLink("Phu Tho", LINK_PHU_THO);
    addLabelLink("Vinh Phuc", LINK_VINH_PHUC);
}

bool PluginViet::input(const SDL_Event& event){
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

void PluginViet::pressReturn(){
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
