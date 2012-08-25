#ifndef ENTRYGROUP_FILE_H
#define ENTRYGROUP_FILE_H

#include <string>
#include <list>
#include <iostream>

#include "PluginEntry.h"
#include "../conf.h"

class DirFile{
    public:
	DirFile(const std::string& npath, const char ntype) {path = npath; type = ntype;std::cout<<type<<std::endl;}

	const bool isDir()		{ return type==1; }
	const bool isFile()		{ return type==2; }
	const char getType()		{ return type; }
	const std::string& getPath()	{ return path; }
	virtual std::list<std::string>&	getListFiletypes();

    //private:
	std::string path;
	char type;
};

class PluginFile : public PluginEntry{
    public:
	PluginFile() : PluginEntry() { changeDir(PLUGIN_VIDEO_HOME); }
	~PluginFile()  {}

	virtual void pressReturn();

	virtual void draw();
	virtual void render();
	virtual void input(const SDL_Event& event);

	virtual const size_t getCountEntries() { return m_entries.size(); }

    private:
	virtual const	unsigned short int  getNumberEntries() { return m_entries.size(); }
			void		    changeDir(const std::string dir);
			void		    changeDir(const std::string dir, const unsigned short int active);
			void		    clearList();

	std::vector<DirFile*>	    m_entries;
        std::string			    m_curDir;
};

#endif
