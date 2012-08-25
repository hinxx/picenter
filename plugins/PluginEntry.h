#ifndef PLUGIN_ENTRY_H
#define PLUGIN_ENTRY_H

#include <vector>
#include <SDL/SDL.h>

#include "../conf.h"
#include "SimpleEntry.h"
#include "PluginBase.h"

class PluginEntry : public PluginBase{
    public:
	PluginEntry();
	~PluginEntry();

	virtual void pressReturn() = 0;
	void pressDown();
	void pressUp();

	virtual	void	draw();
		void	clearEntries();

	virtual const size_t getCountEntries() = 0;

		void	addEntry(const std::string& n_label, const std::string n_url, const char colorR, const char colorG, const char colorB);

		SimpleEntry& getEntry(const size_t which)	{ return *(m_entries[which]); }

    private:
	SDL_Surface* m_surf_active;
	SDL_Rect m_rect;
	SDL_Rect m_rect2;
	//SDL_Surface*	m_surfaces[AMOUNT_ENTRIES];

    protected:
	size_t m_active;
	std::vector<SimpleEntry*> m_entries;
};

#endif
