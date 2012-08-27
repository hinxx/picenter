#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <cstring>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "PluginBase.h"
#include "PluginManager.h"
#include "conf.h"
#include "generic.h"
#include "Log.h"

SDL_Surface* screen;
TTF_Font* font;
PluginBase* grp;

#ifdef LOG
Log DebugLog("debug.log");
#endif

int main(){
    init();

    SDL_Event event;

    //grp = new PluginFile();
    grp = new PluginManager();

    grp->draw();

    while(true){
	while(SDL_PollEvent(&event)){
	    grp->input(event);
	}
	SDL_Delay(WAIT_TIME);
    }
}
