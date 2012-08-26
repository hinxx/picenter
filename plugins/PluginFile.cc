#include "SimpleEntryFile.h"
#include "PluginFile.h"
#include "PluginChooser.h"
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
extern PluginBase* grp;

std::string& string_replace(std::string& input, const char* toreplace, const char* with){
    return input.replace(input.find(toreplace), sizeof(toreplace)-3, with);
}

DirFileList& getDirFileList(const std::string base){
    //std::cout<<"BASE "<<base<<std::endl;
    DirFileList* list = new DirFileList;
    DIR* dir =opendir(base.c_str());
    struct dirent* ent;
    if(dir!=NULL){
	while((ent=readdir(dir))!=NULL){
	    char ndir;
	    std::string npath;

	    if((int)ent->d_type==4)
		ndir = 1; // dir
	    else
		ndir = 2; // file
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


bool strcompare(const std::string a, const std::string b){
    for(unsigned int ii=0;ii<std::min(a.size(), b.size());ii++){
	if(a[ii]<b[ii])
	    return true;
    }
    return false;
}

DirFileSorted PluginFile::sortDirFileList(DirFileList& list){
    int cnt_dirs(0);
    int cnt_files(0);

    //std::cout<<"sort list..."<<std::endl;
    for(DirFileList::iterator it=list.begin();it!=list.end();it++){
	//std::cout<<"	    path: "<<it->path<<std::endl;
	if(
		(it->getURL().substr(it->getURL().size()-2, it->getURL().size())=="..") ||
		(it->getURL()[it->getURL().size()-1]=='.')||
		(it->getURL()[it->getURL().rfind('/')+1]=='.')
	  ){
	    //std::cout<<"ERASE"<<std::endl;
	    it=list.erase(it);
	    it--;
	    continue;
	}else if(it->isFile()){
	    std::list<std::string> lst = getListFiletypes();

	    bool ok=false;
	    for(std::list<std::string>::iterator itt=lst.begin();itt!=lst.end();itt++){
		if(it->getURL().substr(it->getURL().size()-3)==*itt){
		    ok=true;
		}
	    }
	    if(ok==false){
		it=list.erase(it);
		it--;
		continue;
	    }
	}
    }

    for(DirFileList::iterator it=list.begin();it!=list.end();it++){
	if(it->isDir())
	{
	    //std::cout<<"DIR "<<it->path<<std::endl;
	    cnt_dirs +=1;
	}
	else if(it->isFile())
	{
	    //std::cout<<"FILE "<<it->path<<std::endl;
	    cnt_files +=1;
	}
    }

#ifdef LOG
    //DebugLog<<"cnt_dirs:";
    //DebugLog<<cnt_dirs;
    //DebugLog<<"cnt_files:";
    //DebugLog<<cnt_files;
#endif

    //std::vector<std::string>* ptr_list_dirs	= new std::vector<std::string>(cnt_dirs);
    //std::vector<std::string>* ptr_list_files	= new std::vector<std::string>(cnt_files);
    std::vector<std::string>* ptr_list_dirs	= new std::vector<std::string>();
    std::vector<std::string>* ptr_list_files	= new std::vector<std::string>();

    for(DirFileList::iterator it=list.begin();it!=list.end();it++){
	if(it->isDir()){
	    ptr_list_dirs->push_back(it->getURL());
	}
	else if(it->isFile()){
	    ptr_list_files->push_back(it->getURL());
	}
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

    //std::sort(ptr_list_dirs->begin(),	ptr_list_dirs->end(),	strcompare);	
    //std::sort(ptr_list_files->begin(),	ptr_list_files->end(),	strcompare);	

    //std::cout<<"sorted..."<<std::endl;

    DirFileSorted ret;
    ret.ptr_list_dirs	= ptr_list_dirs;
    ret.ptr_list_files	= ptr_list_files;

    return ret;
}

/* CLASS IMPLEMENTATION */


void PluginFile::clearList(){
    std::cout<<"clear list of files/dirs..."<<std::endl;
    //for(std::vector<Entry_File*>::iterator it=m_entries.begin(); it!= m_entries.end(); it++){
    //    delete *it;
    //}
    m_entries.clear();
}

void PluginFile::changeDir(const std::string dir){
    std::cout<<"changeDir: "<<dir<<std::endl;
    m_curDir = dir;

    // clear list
    clearList();

    // fill list
    std::cout<<"vor sortdir"<<std::endl;
    DirFileSorted vec_all = sortDirFileList(getDirFileList(dir));
    std::cout<<"nach sortdir"<<std::endl;
    //const unsigned short int countEntries = vec_all.ptr_list_dirs->size()+vec_all.ptr_list_files->size()+1;
    //std::cout<<"countEntries: "<<countEntries<<std::endl;
    //m_entries.resize(countEntries);

    //if(std::string(dir)!=std::string("/"))
    //m_entries.push_back(new SimpleEntryFile("..", 0));
    //addEntry(std::string(".."), std::string(".."), COLOR_DIR_R, COLOR_DIR_G, COLOR_DIR_B);
	addEntry(new SimpleEntryFile("..", 0));

    for(std::vector<std::string>::iterator it=vec_all.ptr_list_dirs->begin(); it!=vec_all.ptr_list_dirs->end(); it++){
	//m_entries.push_back(new SimpleEntryFile(it->c_str(), 1));
	//addEntry(*it, *it, 1, COLOR_DIR_R, COLOR_DIR_G, COLOR_DIR_B);
	addEntry(new SimpleEntryFile(*it, 1));
    }
    for(std::vector<std::string>::iterator it=vec_all.ptr_list_files->begin(); it!=vec_all.ptr_list_files->end(); it++){
	//m_entries.push_back(new SimpleEntryFile(it->c_str(), 2));
	//addEntry(*it, *it, 2, COLOR_FRONT_R, COLOR_FRONT_G, COLOR_FRONT_B);
	addEntry(new SimpleEntryFile(*it, 2));
    }

    std::cout<<"count files/dirs: "<<m_entries.size()-1<<std::endl;

    delete vec_all.ptr_list_dirs;
    delete vec_all.ptr_list_files;

    m_active = 0;

    draw();
    //render();
}

void PluginFile::changeDir(const std::string dir, const unsigned short int active){
    changeDir(dir);
    if(active>getCountEntries()-1)
	m_active=getCountEntries()-1;
    else
	m_active=active;
    //render();
}

#include <cstdlib>

void PluginFile::pressReturn(){
    switch(static_cast<SimpleEntryFile*>(m_entries[m_active])->getType()){
	case 0:{
		   std::string str_curdir = m_curDir;
		   std::string str_render;

		   const size_t pos = str_curdir.rfind('/');
		   if(pos>0)
		       str_render = str_curdir.substr(0,pos);
		   else
		       str_render = std::string("/");

		   changeDir(str_render);
		   break;
	       }

	case 1:{
		   std::cout<<"selected path: "<<m_entries[m_active]->getURL()<<std::endl;
		   changeDir(m_entries[m_active]->getURL());
		   break;
	       }

	case 2:{
		   const std::string url = getEntry(m_active).getURL();

#ifdef PI
		   std::string cmd = "omxplayer --adev ";
		   //std::string cmd = "omxplayer --adev ";
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

		   break;
	       }
    }
}

/*
void PluginFile::render(){
    //PluginEntry::clearEntries();

    std::cout<<"PluginFile::render"<<std::endl;
    //const unsigned short int pos = m_active-m_active%AMOUNT_ENTRIES;
    //std::cout<<pos<<" "<<m_entries.size()<<std::endl;
    //for(unsigned short int ii=pos; ii!=pos+AMOUNT_ENTRIES; ii++){
    for(size_t ii=0; ii<getCountEntries(); ii++){
	//if(ii<m_entries.size())
	{
	    //std::cout<<ii<<" "<<m_entries[ii]->getURL()<< " "<<(int)m_entries[ii]->getType()<<" pos "<<pos<<std::endl;
	    if(static_cast<SimpleEntryFile*>(m_entries[ii])->getType()>0){
		const std::string str_type = static_cast<SimpleEntryFile*>(m_entries[ii])->getURL();
		std::string str_render;

		const size_t pos2 = str_type.rfind('/');
		str_render = str_type.substr(pos2+1);

		//SDL_Color color;
		if(static_cast<SimpleEntryFile*>(m_entries[ii])->isDir()){
		    //color.r = COLOR_DIR_R;
		    //color.g = COLOR_DIR_G;
		    //color.b = COLOR_DIR_B;
		    addEntry(str_render, str_type, COLOR_DIR_R, COLOR_DIR_G, COLOR_DIR_B);
		}
		else{
		    //color.r = COLOR_FRONT_R;
		    //color.g = COLOR_FRONT_G;
		    //color.b = COLOR_FRONT_B;
		    addEntry(str_render, str_type, COLOR_FRONT_R, COLOR_FRONT_G, COLOR_FRONT_B);
		}

		//PluginEntry::render(ii-pos, str_render.c_str(), color);
	    }
	    else{
		//SDL_Color color;
		//color.r = COLOR_DIR_R;
		//color.g = COLOR_DIR_G;
		//color.b = COLOR_DIR_B;

		//PluginEntry::render(ii-pos, "..", color);
		addEntry(std::string(".."), std::string(".."), COLOR_DIR_R, COLOR_DIR_G, COLOR_DIR_B);
	    }
	    //render();
	    //m_entries[ii]->render();
	}
    }
    std::cout<<"END PluginFile::render"<<std::endl;
}
*/

void PluginFile::input(const SDL_Event& event){
    PluginEntry::input(event);

    if(event.type==SDL_KEYDOWN){
	if(event.key.keysym.sym==SDLK_ESCAPE){
	    delete this;
	    grp = new PluginChooser();
	}
	else{
	    if(event.key.keysym.sym==SDLK_RETURN)
		pressReturn();
	    else if(event.key.keysym.sym==SDLK_h)
		changeDir(PLUGIN_VIDEO_HOME);
	    else if(event.key.keysym.sym==SDLK_r)
		changeDir(m_curDir, m_active);
	    else if(event.key.keysym.sym==SDLK_PERIOD){
		    m_active = 0;
		    draw();
		}

	    draw();
	}
    }
}

std::list<std::string>& PluginFile::getListFiletypes(){
    std::list<std::string>* ret = new std::list<std::string>;

    ret->push_back(std::string("avi"));
    ret->push_back(std::string("mp4"));
    ret->push_back(std::string("mkv"));

    return *ret;
}
