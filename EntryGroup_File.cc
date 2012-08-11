#include "EntryGroup_File.h"
#include "constants.h"
#include "generic.h"

#include <string>
#include <list>
#include <dirent.h>
#include <iostream>
#include <algorithm>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

typedef std::list<DirFile> DirFileList;

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
	    std::cout<<"    path: "<<ll->path<<std::endl;
	    list->push_back(*ll);
	}
	closedir(dir);
    }
    return *list;
}

struct DirFileSorted{
    std::vector<std::string>* ptr_list_dirs;
    std::vector<std::string>* ptr_list_files;
};

bool strcompare(const std::string a, const std::string b){
    for(unsigned int ii=0;ii<std::min(a.size(), b.size());ii++){
	if(a[ii]<b[ii])
	    return true;
    }
    return false;
}

DirFileSorted sortDirFileList(DirFileList& list){
    int cnt_dirs(0);
    int cnt_files(0);

    //std::cout<<"sort list..."<<std::endl;
    for(DirFileList::iterator it=list.begin();it!=list.end();it++){
	//std::cout<<"	    path: "<<it->path<<std::endl;
	if(
	    (it->path.substr(it->path.size()-2, it->path.size())=="..") ||
	    (it->path[it->path.size()-1]=='.')||
	    (it->path[it->path.rfind('/')+1]=='.')
	    ){
	    //std::cout<<"ERASE"<<std::endl;
	    it=list.erase(it);
	    it--;
            continue;
	}
	else{
	    if(it->isDir())
	    {
		//std::cout<<"DIR "<<it->path<<std::endl;
		cnt_dirs +=1;
	    }
	    else
	    {
		//std::cout<<"FILE "<<it->path<<std::endl;
		cnt_files +=1;
	    }
	}
    }
    std::cout<<"cnt_dirs: "<<cnt_dirs<<" cnt_files: "<<cnt_files<<std::endl;
    std::vector<std::string>* ptr_list_dirs	= new std::vector<std::string>(cnt_dirs);
    std::vector<std::string>* ptr_list_files	= new std::vector<std::string>(cnt_files);

    int iid=0;
    int iif=0;

    for(DirFileList::iterator it=list.begin();it!=list.end();it++){
	//std::cout<<it->path<<" "<<iid<<" "<<iif<<std::endl;
	if(it->isDir()){
	    //(*ptr_list_dirs)[iid] = it->path;
	    //iid += 1;
	    ptr_list_dirs->push_back(it->path);
	}
	else if(it->isFile()){
	    //(*ptr_list_files)[iif] = it->path;
	    //iif += 1;
	    ptr_list_files->push_back(it->path);
	}
    }

    std::sort(ptr_list_dirs->begin(),	ptr_list_dirs->end(),	strcompare);	
    std::sort(ptr_list_files->begin(),	ptr_list_files->end(),	strcompare);	

    //std::cout<<"sorted..."<<std::endl;

    DirFileSorted ret;
    ret.ptr_list_dirs	= ptr_list_dirs;
    ret.ptr_list_files	= ptr_list_files;

    return ret;
}

/* CLASS IMPLEMENTATION */


void EntryGroup_File::clearList(){
    std::cout<<"clear list of files/dirs..."<<std::endl;
    //for(std::vector<Entry_File*>::iterator it=m_entries.begin(); it!= m_entries.end(); it++){
    //    delete *it;
    //}
    m_entries.clear();
}

void EntryGroup_File::switchDir(const std::string dir){
    std::cout<<"switchDir: "<<dir<<std::endl;
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
	m_entries.push_back(new DirFile("..", 0));

    for(std::vector<std::string>::iterator it=vec_all.ptr_list_dirs->begin(); it!=vec_all.ptr_list_dirs->end(); it++){
	m_entries.push_back(new DirFile(it->c_str(), 1));
    }
    for(std::vector<std::string>::iterator it=vec_all.ptr_list_files->begin(); it!=vec_all.ptr_list_files->end(); it++){
	m_entries.push_back(new DirFile(it->c_str(), 2));
    }

    std::cout<<"count files/dirs: "<<m_entries.size()-1<<std::endl;

    delete vec_all.ptr_list_dirs;
    delete vec_all.ptr_list_files;

    m_active = 0;

    render();
}

#include <cstdlib>

void EntryGroup_File::pressReturn(){
    switch(m_entries[m_active]->getType()){
	case 0:{
		   std::string str_curdir = m_curDir;
		   std::string str_render;

		   const size_t pos = str_curdir.rfind('/');
		   if(pos>0)
		       str_render = str_curdir.substr(0,pos);
		   else
		       str_render = std::string("/");

		   switchDir(str_render);
		   break;
	       }

	case 1:{
		   std::cout<<"selected path: "<<m_entries[m_active]->getPath()<<std::endl;
		   switchDir(m_entries[m_active]->getPath());
		   break;
	       }

	case 2:{
		   std::string filepath = std::string(m_entries[m_active]->getPath());
                   // Desktop
		   //std::string cmd = "mplayer -fs ";
                   // for Raspberry PI
		   std::string cmd = "omxplayer -o hdmi ";

		   // std::cout<<filepath<<std::endl;
		   //filepath.replace(filepath.find(" "), filepath.size(), "\\ ");
		   cmd += "'"+filepath+"'";

		   SDL_FreeSurface(screen);
			TTF_Quit();
SDL_Quit();

		    std::cout<<"OPEN "<<cmd<<std::endl;
		   system(cmd.c_str());

init();
		   break;
	       }
    }
}

void EntryGroup_File::draw(){
    std::cout<<"EntryGroup_File::draw"<<std::endl;
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

    EntryGroup::draw();

    /*
    const unsigned short int pos = m_active-m_active%AMOUNT_ENTRIES;
    for(unsigned short int ii=pos; ii!=pos+AMOUNT_ENTRIES; ii++){
	if(ii<m_entries.size())
	    m_entries[ii]->draw(ii%AMOUNT_ENTRIES);
    }
    */

    SDL_Flip(screen); 
}

void EntryGroup_File::render(){
    EntryGroup::clear();

    std::cout<<"EntryGroup_File::render"<<std::endl;
    const unsigned short int pos = m_active-m_active%AMOUNT_ENTRIES;
    //std::cout<<pos<<" "<<m_entries.size()<<std::endl;
    for(unsigned short int ii=pos; ii!=pos+AMOUNT_ENTRIES; ii++){
            if(ii<m_entries.size())
	    {
		std::cout<<ii<<" "<<m_entries[ii]->getPath()<< " "<<(int)m_entries[ii]->getType()<<" pos "<<pos<<std::endl;
		if(m_entries[ii]->getType()>0){
		    const std::string str_type = m_entries[ii]->getPath();
		    std::string str_render;

		    const size_t pos2 = str_type.rfind('/');
		    str_render = str_type.substr(pos2+1);

		    SDL_Color color;
		    if(m_entries[ii]->isDir()){
			color.r = 0;
			color.g = 0;
			color.b = 255;
		    }
		    else{
			color.r = 255;
			color.g = 255;
			color.b = 255;
		    }

		    EntryGroup::render(ii-pos, str_render.c_str(), color);
		}
		else{
		    SDL_Color color;
		    color.r = 255;
		    color.g = 0;
		    color.b = 0;

		    EntryGroup::render(ii-pos, "..", color);
		}
		//render();
                //m_entries[ii]->render();
	    }
    }
    std::cout<<"END EntryGroup_File::render"<<std::endl;
}
