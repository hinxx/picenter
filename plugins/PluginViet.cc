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

    ptr_lst->push_back(LabelLink("VTV1", LINK_VTV1a));
    ptr_lst->push_back(LabelLink("VTV1 #2", LINK_VTV1b));
    ptr_lst->push_back(LabelLink("VTV2", LINK_VTV2));
    ptr_lst->push_back(LabelLink("VTV3", LINK_VTV3a));
    ptr_lst->push_back(LabelLink("VTV3 #2", LINK_VTV3b));
    ptr_lst->push_back(LabelLink("VTV4", LINK_VTV4));
    ptr_lst->push_back(LabelLink("VTV6", LINK_VTV6));
    ptr_lst->push_back(LabelLink("VTV9", LINK_VTV9));
    ptr_lst->push_back(LabelLink("HTV2", LINK_HTV2));
    ptr_lst->push_back(LabelLink("HTV7", LINK_HTV7a));
    ptr_lst->push_back(LabelLink("HTV7 #2", LINK_HTV7b));
    ptr_lst->push_back(LabelLink("HTV9", LINK_HTV9a));
    ptr_lst->push_back(LabelLink("HTV9 #2", LINK_HTV9b));
    ptr_lst->push_back(LabelLink("HTVCHD YeahTV", LINK_HTVCHD_YEAHTVa));
    ptr_lst->push_back(LabelLink("HTVCHD YeahTV #2", LINK_HTVCHD_YEAHTVb));
    ptr_lst->push_back(LabelLink("VTC1", LINK_VTC1));
    ptr_lst->push_back(LabelLink("VCTV3", LINK_VCTV3));
    ptr_lst->push_back(LabelLink("VTC6", LINK_VTC6a));
    ptr_lst->push_back(LabelLink("VTC6 #2", LINK_VTC6b));
    ptr_lst->push_back(LabelLink("VCTV7", LINK_VCTV7));
    ptr_lst->push_back(LabelLink("VTC9", LINK_VTC9));
    ptr_lst->push_back(LabelLink("VTC13", LINK_VTC13));
    ptr_lst->push_back(LabelLink("VCTV9", LINK_VCTV9));
    ptr_lst->push_back(LabelLink("ITV", LINK_ITV));
    ptr_lst->push_back(LabelLink("SCTV1", LINK_SCTV1));
    ptr_lst->push_back(LabelLink("SCTV2", LINK_SCTV2));
    ptr_lst->push_back(LabelLink("SCTV3", LINK_SCTV3));
    ptr_lst->push_back(LabelLink("SCTV4", LINK_SCTV4));
    ptr_lst->push_back(LabelLink("SCTV5", LINK_SCTV5));
    ptr_lst->push_back(LabelLink("SCTV6", LINK_SCTV6));
    ptr_lst->push_back(LabelLink("SCTV7", LINK_SCTV7));
    ptr_lst->push_back(LabelLink("SCTV8", LINK_SCTV8));
    ptr_lst->push_back(LabelLink("SCTV9", LINK_SCTV9));
    ptr_lst->push_back(LabelLink("SCTV10", LINK_SCTV10));
    ptr_lst->push_back(LabelLink("SCTV11", LINK_SCTV11));
    ptr_lst->push_back(LabelLink("SCTV12", LINK_SCTV12));
    ptr_lst->push_back(LabelLink("SCTV13", LINK_SCTV13));
    ptr_lst->push_back(LabelLink("SCTV14", LINK_SCTV14));
    ptr_lst->push_back(LabelLink("SCTV15", LINK_SCTV15));
    ptr_lst->push_back(LabelLink("SCTV16", LINK_SCTV16));
    ptr_lst->push_back(LabelLink("SCTV17", LINK_SCTV17));
    ptr_lst->push_back(LabelLink("SCTV18", LINK_SCTV18));
    ptr_lst->push_back(LabelLink("Long An", LINK_LONG_AN));
    ptr_lst->push_back(LabelLink("Hanoi", LINK_HANOI));
    ptr_lst->push_back(LabelLink("Vinh Long 1", LINK_VINH_LONG1));
    ptr_lst->push_back(LabelLink("Vinh Long 2", LINK_VINH_LONG2));
    ptr_lst->push_back(LabelLink("Hau Giang", LINK_HAU_GIANG));
    ptr_lst->push_back(LabelLink("Soc Trang", LINK_SOC_TRANG));
    ptr_lst->push_back(LabelLink("Dong Thap", LINK_DONG_THAP));
    ptr_lst->push_back(LabelLink("Quang Nam", LINK_QUANG_NAM));
    ptr_lst->push_back(LabelLink("Binh Thuan", LINK_BINH_THUAN));
    ptr_lst->push_back(LabelLink("ANTV", LINK_ANTV));
    ptr_lst->push_back(LabelLink("Dong Nai 1", LINK_DONG_NAI1));
    ptr_lst->push_back(LabelLink("Dong Nai 2", LINK_DONG_NAI2));
    ptr_lst->push_back(LabelLink("Cantho 1", LINK_CANTHO1));
    ptr_lst->push_back(LabelLink("Cantho 2", LINK_CANTHO2));
    ptr_lst->push_back(LabelLink("DanangTV", LINK_DANANGTV));
    ptr_lst->push_back(LabelLink("TRT1 Hue", LINK_TRT1_HUE));
    ptr_lst->push_back(LabelLink("TTXVN", LINK_TTXVN));
    ptr_lst->push_back(LabelLink("LifeTV", LINK_LIFETVa));
    ptr_lst->push_back(LabelLink("LifeTV #2", LINK_LIFETVb));
    ptr_lst->push_back(LabelLink("Binh Duong 1", LINK_BINH_DUONG1));
    ptr_lst->push_back(LabelLink("Binh Duong 2", LINK_BINH_DUONG2));
    ptr_lst->push_back(LabelLink("Daklak", LINK_DAKLAK));
    ptr_lst->push_back(LabelLink("An Giang", LINK_AN_GIANG));
    ptr_lst->push_back(LabelLink("Tien Giang", LINK_TIEN_GIANG));
    ptr_lst->push_back(LabelLink("Bac Lieu", LINK_BAC_LIEU));
    ptr_lst->push_back(LabelLink("Can Tho", LINK_CAN_THO));
    ptr_lst->push_back(LabelLink("Thai Nguyen", LINK_THAI_NGUYEN));
    ptr_lst->push_back(LabelLink("Phu Tho", LINK_PHU_THO));
    ptr_lst->push_back(LabelLink("Vinh Phuc", LINK_VINH_PHUC));

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
