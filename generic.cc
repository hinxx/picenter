#include "generic.h"
#include "conf.h"

#include<fstream>

void init(){
    // Initialize and global variables
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    const SDL_VideoInfo* curmode = SDL_GetVideoInfo();
    //std::cout << "Current mode: " << (int)curmode->vfmt->BitsPerPixel << std::endl;
    screen = SDL_SetVideoMode(curmode->current_w, curmode->current_h, curmode->vfmt->BitsPerPixel, SDL_SWSURFACE);

    // PI
    font = TTF_OpenFont("/usr/share/fonts/truetype/freefont/FreeMono.ttf", FONTSIZE);
    //font = TTF_OpenFont("/usr/share/fonts/dejavu/DejaVuSansMono.ttf", FONTSIZE);
    //font = TTF_OpenFont("/usr/share/fonts/bitstream-vera/VeraMono.ttf", FONTSIZE);

    // Desktop
    //font = TTF_OpenFont("/usr/local/lib/X11/fonts/freefont-ttf/FreeMono.ttf", FONTSIZE);
}
