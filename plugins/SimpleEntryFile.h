#ifndef SIMPLE_ENTRY_FILE_H
#define SIMPLE_ENTRY_FILE_H

#include "SimpleEntryURL.h"

class SimpleEntryFile : public SimpleEntryURL
{
    public:
	SimpleEntryFile(const std::string& n_label, const std::string& n_url, const bool n_type);

	const bool isDir()		{ return m_type==true; }
	const bool isFile()		{ return m_type==false; }
	const char getType()		{ return m_type; }

    private:
	bool m_type;
};

#endif
