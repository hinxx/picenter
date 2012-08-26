#ifndef SIMPLE_ENTRY_H
#define SIMPLE_ENTRY_H

#include <string>
#include <SDL/SDL.h>

class SimpleEntry{
    public:
	SimpleEntry() {}
	SimpleEntry(const std::string& n_label, const std::string n_url, const char colorR, const char colorG, const char colorB);
	~SimpleEntry();

	const	std::string&	getLabel()	const	    { return m_label; }
	const	std::string&	getURL()	const	    { return m_url; }
		SDL_Surface*	getSurface()		    { return m_surf; }

		void		render(const std::string& n_label, const std::string n_url, const char colorR, const char colorG, const char colorB);

    private:
	std::string	m_label;
	std::string	m_url;
	SDL_Surface*	m_surf;
};

#endif
