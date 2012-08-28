#include "SimpleEntryFile.h"
#include "PluginFile.h"
#include "PluginManager.h"
#include "../conf.h"
#include "../generic.h"
#include "../Log.h"

#include <string>
#include <list>
#include <dirent.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#ifdef LOG
extern Log DebugLog;
#endif

extern SDL_Surface* screen;

typedef PluginEntry __Base;

std::string& string_replace(std::string& input, const char* toreplace, const char* with)
{
    return input.replace(input.find(toreplace), sizeof(toreplace)-3, with);
}

DirFileList& getDirFileList(const std::string base)
{
    DirFileList* list = new DirFileList;
    DIR* dir =opendir(base.c_str());
    struct dirent* ent;
    if(dir!=NULL)
    {
	while((ent=readdir(dir))!=NULL)
	{
	    bool ndir;
	    std::string npath;

	    if((int)ent->d_type==4)
		ndir = true; // dir
	    else
		ndir = false; // file
	    //ll->path	= std::string(base)+std::string(ent->d_name);
	    std::string str_base = std::string(base);
	    if(str_base[str_base.size()-1]=='/')
		npath	= std::string(base)+std::string(ent->d_name);
	    else
		npath	= std::string(base)+std::string("/")+std::string(ent->d_name);

	    DirFile* ll = new DirFile(npath, ndir);
	    //std::cout<<"    path: "<<ll->path<<std::endl;
	    list->push_back(*ll);
	}
	closedir(dir);
    }

    return *list;
}

DirFileSorted PluginFile::sortDirFileList(DirFileList& list)
{
    int cnt_dirs(0);
    int cnt_files(0);

    //std::cout<<"sort list..."<<std::endl;
    for(DirFileList::iterator it=list.begin();it!=list.end();it++)
    {
	if(
		(it->getURL().substr(it->getURL().size()-2, it->getURL().size())=="..") ||
		(it->getURL()[it->getURL().size()-1]=='.')||
		(it->getURL()[it->getURL().rfind('/')+1]=='.')
	  )
	  {
	    it=list.erase(it);
	    it--;
	    continue;
	  }
	  else if(it->isFile())
	  {
	      std::list<std::string> lst = getListFiletypes();

	      bool ok=false;
	      for(std::list<std::string>::iterator itt=lst.begin();itt!=lst.end();itt++)
	      {
		  if(it->getURL().substr(it->getURL().size()-3)==*itt)
		      ok=true;
	      }
	      if(ok==false)
	      {
		  it=list.erase(it);
		  it--;
		  continue;
	      }
	  }
    }

    for(DirFileList::iterator it=list.begin();it!=list.end();it++)
    {
	if(it->isDir())
	    cnt_dirs +=1;
	else if(it->isFile())
	    cnt_files +=1;
    }

#ifdef LOG
    //DebugLog<<"cnt_dirs:";
    //DebugLog<<cnt_dirs;
    //DebugLog<<"cnt_files:";
    //DebugLog<<cnt_files;
#endif

    std::vector<std::string>* ptr_list_dirs	= new std::vector<std::string>();
    std::vector<std::string>* ptr_list_files	= new std::vector<std::string>();

    for(DirFileList::iterator it=list.begin();it!=list.end();it++)
    {
	if(it->isDir())
	    ptr_list_dirs->push_back(it->getURL());
	else if(it->isFile())
	    ptr_list_files->push_back(it->getURL());
    }

#ifdef LOG
    //DebugLog<<"";
    //DebugLog<<"DIRS";
    //for(int ii=0;ii<cnt_dirs;ii++){
    //    DebugLog << (*ptr_list_dirs)[ii].c_str();
    //}
    //DebugLog<<"";
    //DebugLog<<"FILES";
    //for(int ii=0;ii<cnt_files;ii++){
    //    DebugLog <<(*ptr_list_files)[ii].c_str();
    //}
#endif

    std::sort(ptr_list_dirs->begin(),	ptr_list_dirs->end());	
    std::sort(ptr_list_files->begin(),	ptr_list_files->end());	

    //std::cout<<"sorted..."<<std::endl;

    DirFileSorted ret;
    ret.ptr_list_dirs	= ptr_list_dirs;
    ret.ptr_list_files	= ptr_list_files;

    return ret;
}

const std::string last(const std::string dirfile)
{
    const size_t pos = dirfile.rfind('/');
    return dirfile.substr(pos+1);
}

/* CLASS IMPLEMENTATION */

void PluginFile::changeDir(const std::string dir){
    std::cout<<"changeDir: "<<dir<<std::endl;
    m_curDir = dir;

    // clear list
    clear();

    // fill list
    DirFileSorted vec_all = sortDirFileList(getDirFileList(dir));
    //const unsigned short int countEntries = vec_all.ptr_list_dirs->size()+vec_all.ptr_list_files->size()+1;
    //std::cout<<"countEntries: "<<countEntries<<std::endl;
    //m_entries.resize(countEntries);

    //if(std::string(dir)!=std::string("/"))
    //m_entries.push_back(new SimpleEntryFile("..", 0));
    //addEntry(std::string(".."), std::string(".."), COLOR_DIR_R, COLOR_DIR_G, COLOR_DIR_B);

    // find the above directory
    std::string str_curdir = m_curDir;
    std::string dir_above;

    const size_t pos = str_curdir.rfind('/');
    if(pos>0)
	dir_above = str_curdir.substr(0, pos);
    else
	dir_above = std::string("/");

    // only add when current dir is not root
    if(m_curDir!=std::string("/"))
	addEntry(new SimpleEntryFile("..", dir_above, true));

    for(std::vector<std::string>::iterator it=vec_all.ptr_list_dirs->begin(); it!=vec_all.ptr_list_dirs->end(); it++)
	addEntry(new SimpleEntryFile(last(*it), *it, true));

    for(std::vector<std::string>::iterator it=vec_all.ptr_list_files->begin(); it!=vec_all.ptr_list_files->end(); it++)
	addEntry(new SimpleEntryFile(last(*it), *it, false));

    delete vec_all.ptr_list_dirs;
    delete vec_all.ptr_list_files;

    m_active = 0;

    draw();
}

void PluginFile::changeDir(const std::string dir, const unsigned short int active){
    changeDir(dir);
    if(active>getCountEntries()-1)
	m_active=getCountEntries()-1;
    else
	m_active=active;
}

#include <cstdlib>

void PluginFile::pressReturn(){
    if(static_cast<SimpleEntryFile*>(m_entries[m_active])->isDir()==true)
    {
	changeDir(static_cast<SimpleEntryFile*>(m_entries[m_active])->getURL());
    }
    else
    {
	const std::string url = static_cast<SimpleEntryFile*>(m_entries[m_active])->getURL();

#ifdef PI
	std::string cmd = "omxplayer --adev ";
	cmd += ADEV;
	cmd += ADDCMD;
#else
	std::string cmd = "mplayer";
#endif

	cmd += " '"+url+"'";

	SDL_FreeSurface(screen);
	TTF_Quit();
	SDL_Quit();

	system(cmd.c_str());

	// workaround for OMXPlayer stealing the framebuffer
#ifdef PI
	system("fbset -depth 8 && fbset -depth 16");
#endif

	init();
    }
}

bool PluginFile::input(const SDL_Event& event)
{
    if(__Base::input(event)==true)
	return true;
    else
    {
	if(event.type==SDL_KEYDOWN)
	{
	    if(event.key.keysym.sym==SDLK_RETURN)
		pressReturn();
	    else if(event.key.keysym.sym==SDLK_h)
		changeDir(PLUGIN_VIDEO_HOME);
	    else if(event.key.keysym.sym==SDLK_r)
		changeDir(m_curDir, m_active);
	    else if(event.key.keysym.sym==SDLK_PERIOD)
	    {
		m_active = 0;
		draw();
	    }

	    draw();
	}
    }

    return false;
}

std::list<std::string>& PluginFile::getListFiletypes()
{
    std::list<std::string>* ret = new std::list<std::string>;

    ret->push_back(std::string("avi"));
    ret->push_back(std::string("mp4"));
    ret->push_back(std::string("mkv"));

    return *ret;
}
