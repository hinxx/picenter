#ifndef SIMPLE_ENTRY_FILE_H
#define SIMPLE_ENTRY_FILE_H

#include "SimpleEntryURL.h"

class SimpleEntryFile : public SimpleEntryURL{
    public:
	SimpleEntryFile(const std::string& n_url, const char n_type);
	SimpleEntryFile(const std::string& n_label, const std::string n_url, const char n_type, const char colorR, const char colorG, const char colorB) : SimpleEntryURL(n_label, n_url, colorR, colorG, colorB) { m_type = n_type; }

	const bool isDir()		{ return m_type==1; }
	const bool isFile()		{ return m_type==2; }
	const char getType()		{ return m_type; }

    private:
	char m_type;
};

#endif
