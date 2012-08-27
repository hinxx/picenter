#ifndef ENTRYGROUP_FILE_H
#define ENTRYGROUP_FILE_H

#include <string>
#include <list>
#include <iostream>

#include "SimpleEntryFile.h"
#include "PluginEntry.h"
#include "../conf.h"

struct DirFile{
    DirFile(const std::string n_path, const char n_type) { m_path = n_path; m_type = n_type; }

    const bool isDir()		{ return m_type==1; }
    const bool isFile()		{ return m_type==2; }
    const char getType()	{ return m_type; }
    const std::string getURL()		{ return m_path; }

    std::string m_path;
    char m_type;
};

typedef std::list<DirFile> DirFileList;

struct DirFileSorted{
    std::vector<std::string>* ptr_list_dirs;
    std::vector<std::string>* ptr_list_files;
};

class PluginFile : public PluginEntry{
    public:
	PluginFile() : PluginEntry() { changeDir(PLUGIN_VIDEO_HOME); }
	~PluginFile()  {}

	virtual const char* title() { return "Video files"; }

	virtual bool input(const SDL_Event& event);
	void pressReturn();

    protected:
	virtual std::list<std::string>& getListFiletypes();

    private:
	//virtual const	unsigned short int  getNumberEntries() { return m_entries.size(); }
			void		    changeDir(const std::string dir);
			void		    changeDir(const std::string dir, const unsigned short int active);
			void		    clearList();

        std::string			    m_curDir;

	DirFileSorted sortDirFileList(DirFileList& list);
};

#endif
