#include "PluginEntry.h"
#include "../conf.h"
#include "../generic.h"

#include <SDL/SDL_ttf.h>
#include <iostream>

PluginEntry::PluginEntry(){
    const SDL_VideoInfo* curmode = SDL_GetVideoInfo();

    m_surf_active = SDL_CreateRGBSurface(SDL_SWSURFACE, curmode->current_w, FONTSIZE, (int)curmode->vfmt->BitsPerPixel, COLOR_MARKED_R, COLOR_MARKED_G, COLOR_MARKED_B, 255);
    SDL_FillRect(m_surf_active, NULL, SDL_MapRGB(screen->format, COLOR_MARKED_R, COLOR_MARKED_G, COLOR_MARKED_B));

    m_rect.w = FONTSIZE;
    m_rect.h = FONTSIZE;
    m_rect.x = 0;

    // need to be fixed
    m_rect2.w = 200;
    m_rect2.h = 200;
    m_rect2.x = 20;
}

PluginEntry::~PluginEntry(){
    SDL_FreeSurface(m_surf_active);
//    for(int ii=0;ii<AMOUNT_ENTRIES;ii++)
//	SDL_FreeSurface(m_surfaces[ii]);
}

void PluginEntry::pressDown(){
	m_active+=1;	

	if(m_active==getCountEntries())
	    m_active=0;

	if(m_active%AMOUNT_ENTRIES==0)
	    draw();
}

void PluginEntry::pressUp(){
	if(m_active==0)
	    m_active=getCountEntries()-1;
	else
	    m_active-=1;	

	if(m_active%AMOUNT_ENTRIES==AMOUNT_ENTRIES-1 || m_active==getCountEntries()-1)
	    draw();
}

void PluginEntry::addEntry(const std::string& n_label, const std::string n_url, const char colorR, const char colorG, const char colorB)
{
    SimpleEntry* nEntry = new SimpleEntry(n_label, n_url, colorR, colorG, colorB);

    m_entries.push_back(nEntry);
}

void PluginEntry::draw(){
    m_rect.y = ENTRY_Y+m_active%AMOUNT_ENTRIES*FONTSIZE;
    SDL_BlitSurface(m_surf_active, NULL, screen, &m_rect);

    size_t top = m_active-m_active%AMOUNT_ENTRIES;

    for(size_t ii=top;ii<top+AMOUNT_ENTRIES;ii++){
	//if(m_entries[ii]->getSurface()!=NULL){
	if(ii<m_entries.size()){
	    m_rect2.y = ENTRY_Y+(ii%AMOUNT_ENTRIES)*FONTSIZE;	
	    SDL_BlitSurface(m_entries[ii]->getSurface(), NULL, screen, &m_rect2);
	}
    }
}

void PluginEntry::clearEntries(){
    for(size_t ii=0;ii<m_entries.size();ii++)
	delete m_entries[ii];

    m_entries.clear();
}
