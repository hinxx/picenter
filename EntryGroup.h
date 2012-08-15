#ifndef ENTRYGROUP_H
#define ENTRYGROUP_H

#include <vector>
#include <SDL/SDL.h>
#include "constants.h"

class EntryGroup{
    public:
	EntryGroup();
	~EntryGroup();

	virtual void pressReturn() = 0;
	void pressDown();
	void pressUp();

	virtual void render() = 0;
	virtual void input(const SDL_Event& event) = 0;
	virtual	void draw();
		void render(const size_t idx, const char* title, const SDL_Color color);
		void clear();

	virtual const unsigned short int getCountEntries() = 0;

    private:
	SDL_Surface* m_surf_active;
	SDL_Rect m_rect;
	SDL_Rect m_rect2;
	SDL_Surface*	m_surfaces[AMOUNT_ENTRIES];

    protected:
	unsigned short int m_active;
};

#endif
