#ifndef ENTRYGROUP_FILE_H
#define ENTRYGROUP_FILE_H

#include "EntryGroup.h"
#include "constants.h"

#include <string>
#include <iostream>

class DirFile{
    public:
	DirFile(const std::string& npath, const char ntype) {path = npath; type = ntype;std::cout<<type<<std::endl;}

	const bool isDir()		{ return type==1; }
	const bool isFile()		{ return type==2; }
	const char getType()		{ return type; }
	const std::string& getPath()	{ return path; }

    //private:
	std::string path;
	char type;
};

class EntryGroup_File : public EntryGroup{
    public:
	EntryGroup_File() : EntryGroup() { switchDir(HOME); }
	~EntryGroup_File()  {}

	virtual void pressReturn();

	virtual void draw();
	virtual void render();
	virtual void input(const SDL_Event& event);

	virtual const unsigned short int getCountEntries() { return m_entries.size(); }

    private:
	virtual const	unsigned short int  getNumberEntries() { return m_entries.size(); }
			void		    switchDir(const std::string dir);
			void		    clearList();

	std::vector<DirFile*>	    m_entries;
        std::string			    m_curDir;
};

#endif
