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

	virtual	void	draw();
	virtual	void	input(const SDL_Event& event);
		void	clearEntries();

	virtual const size_t getCountEntries() const { return m_entries.size(); }

		void	addEntry(SimpleEntry* n_entry)	{ m_entries.push_back(n_entry); }
		void	addEntry(const std::string& n_label, const char colorR, const char colorG, const char colorB);
		void	addEntryURL(const std::string& n_label, const std::string n_url, const char colorR, const char colorG, const char colorB);

		SimpleEntry& getEntry(const size_t which)	{ return *(m_entries[which]); }
		SimpleEntry& getMarkedEntry()			{ return *(m_entries[m_active]); }

    private:
	SDL_Surface* m_surf_active;
	SDL_Rect m_rect;
	SDL_Rect m_rect2;
	//SDL_Surface*	m_surfaces[AMOUNT_ENTRIES];

	void pressDown();
	void pressUp();

    protected:
	size_t m_active;
	std::vector<SimpleEntry*> m_entries;
};

#endif
