#include "SimpleEntry.h"
#include "../conf.h"
#include "../generic.h"

#include <cstdlib>
#include <iostream>
#include <SDL/SDL.h>

extern TTF_Font* font;

SimpleEntry::SimpleEntry(const std::string& n_label, const char colorR, const char colorG, const char colorB)
{
    render(n_label, colorR, colorG, colorB);
}

SimpleEntry::~SimpleEntry()
{
    if(m_surf){
	SDL_FreeSurface(m_surf);
    }
}

void SimpleEntry::render(const std::string& n_label, const char colorR, const char colorG, const char colorB){
    m_label = n_label;

    SDL_Color color;
    color.r = colorR;
    color.g = colorG;
    color.b = colorB;

    m_surf  = TTF_RenderText_Solid(font, n_label.c_str(), color);
}
