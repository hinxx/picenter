#include "EntryGroup.h"
#include "config.h"
#include "generic.h"

#include <SDL/SDL_ttf.h>
#include <iostream>

EntryGroup::EntryGroup(){
    SDL_Color color_blue;
    color_blue.r = 0;
    color_blue.g = 0;
    color_blue.b = 255;

    m_surf_active = TTF_RenderText_Solid(font, ">", color_blue);

    m_rect.w = FONTSIZE;
    m_rect.h = FONTSIZE;
    m_rect.x = 0;

    // need to be fixed
    m_rect2.w = 200;
    m_rect2.h = 200;
    m_rect2.x = 20;
}

EntryGroup::~EntryGroup(){
    SDL_FreeSurface(m_surf_active);
    for(int ii=0;ii<AMOUNT_ENTRIES;ii++)
	SDL_FreeSurface(m_surfaces[ii]);
}

void EntryGroup::pressDown(){
	m_active+=1;	

	if(m_active==getCountEntries())
	    m_active=0;

std::cout<<"Pressed down"<<std::endl;
	if(m_active%AMOUNT_ENTRIES==0)
	    render();
}

void EntryGroup::pressUp(){
	if(m_active==0)
	    m_active=getCountEntries()-1;
	else
	    m_active-=1;	

std::cout<<"Pressed up"<<std::endl;
	if(m_active%AMOUNT_ENTRIES==AMOUNT_ENTRIES-1)
	    render();
}

void EntryGroup::draw(){
    m_rect.y = ENTRY_Y+m_active%AMOUNT_ENTRIES*FONTSIZE;
    std::cout<<"m_active "<<m_active<<" m_rect.y "<<m_rect.y<<std::endl;
    SDL_BlitSurface(m_surf_active, NULL, screen, &m_rect);

    for(size_t ii=0;ii<AMOUNT_ENTRIES;ii++){
	if(m_surfaces[ii]!=NULL){
	    m_rect2.y = ENTRY_Y+ii*FONTSIZE;	
	    SDL_BlitSurface(m_surfaces[ii], NULL, screen, &m_rect2);
	}
    }
}

void EntryGroup::render(const size_t idx, const char* title, const SDL_Color color){
    std::cout<<"render "<<title<<" idx "<<idx<<std::endl;
    if(m_surfaces[idx]!=NULL)
	SDL_FreeSurface(m_surfaces[idx]);

    m_surfaces[idx] = TTF_RenderText_Solid(font, title, color);
}

void EntryGroup::clear(){
    for(size_t ii=0;ii<AMOUNT_ENTRIES;ii++){
	if(m_surfaces[ii]!=NULL)
	    SDL_FreeSurface(m_surfaces[ii]);
	    m_surfaces[ii] = NULL;
	}
}
