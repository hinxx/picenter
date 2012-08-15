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

    while(true){
	while(SDL_PollEvent(&event)){
	    grp->input(event);
	}
	SDL_Delay(20);
    }
}
