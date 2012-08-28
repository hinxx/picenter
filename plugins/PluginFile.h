#ifndef ENTRYGROUP_FILE_H
#define ENTRYGROUP_FILE_H

#include <string>
#include <list>
#include <iostream>

#include "SimpleEntryFile.h"
#include "PluginEntry.h"
#include "../conf.h"

class DirFile
{
    public:
	DirFile(const std::string n_path, const bool n_type) { m_path = n_path; m_type = n_type; }

	const bool isDir()		{ return m_type==true; }
	const bool isFile()		{ return m_type==false; }
	const char getType()		{ return m_type; }
	const std::string getURL()	{ return m_path; }

    private:
	std::string m_path;
	bool m_type;
};

typedef std::list<DirFile> DirFileList;

struct DirFileSorted
{
    std::vector<std::string>* ptr_list_dirs;
    std::vector<std::string>* ptr_list_files;
};

class PluginFile : public PluginEntry
{
    public:
	PluginFile() : PluginEntry() { changeDir(PLUGIN_VIDEO_HOME); }
	~PluginFile()  {}

	virtual const char* title() { return "Video files"; }

	virtual bool input(const SDL_Event& event);
	void pressReturn();

    protected:
	virtual std::list<std::string>& getListFiletypes();

    private:
			void		    changeDir(const std::string dir);
			void		    changeDir(const std::string dir, const unsigned short int active);

        std::string			    m_curDir;

	DirFileSorted sortDirFileList(DirFileList& list);
};

#endif
