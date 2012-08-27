#ifndef SIMPLE_ENTRY_URL_H
#define SIMPLE_ENTRY_URL_H

#include "SimpleEntry.h"

class SimpleEntryURL : public SimpleEntry{
    public:
	SimpleEntryURL() {}
	SimpleEntryURL(const std::string& n_label, const std::string n_url, const char colorR, const char colorG, const char colorB) : SimpleEntry(n_label, colorR, colorG, colorB) { m_url = n_url; }

	const std::string& getURL()	{ return m_url; }

    protected:
	std::string m_url;
};

#endif
