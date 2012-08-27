#ifndef SIMPLE_ENTRY_H
#define SIMPLE_ENTRY_H

#include <string>
#include <SDL/SDL.h>

class SimpleEntry{
    public:
	SimpleEntry() {}
	SimpleEntry(const std::string& n_label, const char colorR, const char colorG, const char colorB);
	~SimpleEntry();

	const	std::string&	getLabel()	const	    { return m_label; }
		SDL_Surface*	getSurface()		    { return m_surf; }

		void		render(const std::string& n_label, const char colorR, const char colorG, const char colorB);

    private:
	std::string	m_label;
	SDL_Surface*	m_surf;
};

#endif
