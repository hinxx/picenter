#include "PluginBase.h"

bool PluginBase::input(const SDL_Event& event){
    if(event.type==SDL_KEYDOWN){
	if(event.key.keysym.sym==SDLK_ESCAPE)
	    return true;
    }

    return false;
}
