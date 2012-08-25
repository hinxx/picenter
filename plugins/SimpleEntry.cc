#include "SimpleEntry.h"
#include "../conf.h"
#include "../generic.h"

#include <cstdlib>
#include <SDL/SDL.h>

extern TTF_Font* font;

SimpleEntry::SimpleEntry(const std::string& n_label, const std::string n_url, const char colorR, const char colorG, const char colorB)
{
    m_label = n_label;
    m_url   = n_url;

    SDL_Color color;
    color.r = colorR;
    color.g = colorG;
    color.b = colorB;

    m_surf  = TTF_RenderText_Solid(font, n_label.c_str(), color);
}

SimpleEntry::~SimpleEntry()
{
    SDL_FreeSurface(m_surf);
}

