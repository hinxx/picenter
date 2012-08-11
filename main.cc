#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <cstring>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "EntryGroup.h"
#include "EntryGroup_File.h"
#include "constants.h"
#include "generic.h"

SDL_Surface* screen;
TTF_Font* font;

int main(){
init();

    SDL_Event event;

    EntryGroup* grp = new EntryGroup_File();

    grp->draw();

    bool running=true;

    while(running){
	while(SDL_PollEvent(&event)){
	    if(event.type==SDL_KEYDOWN){
		if(event.key.keysym.sym==SDLK_RETURN)
		    grp->pressReturn();
		else if(event.key.keysym.sym==SDLK_DOWN)
		    grp->pressDown();
		else if(event.key.keysym.sym==SDLK_UP)
		    grp->pressUp();
		else if(event.key.keysym.sym==SDLK_ESCAPE){
		    SDL_FreeSurface(screen);
		    TTF_Quit();
		    SDL_Quit();
                    running=false;
                    break;
		}

		grp->draw();
	    }
	}
	SDL_Delay(20);
    }
}
