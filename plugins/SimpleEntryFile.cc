#include "SimpleEntryFile.h"
#include "../conf.h"

#include<iostream>
SimpleEntryFile::SimpleEntryFile(const std::string& n_url, const char n_type){
    m_type = n_type; 
    m_url = n_url;

    if(m_type>0){
	const std::string str_type = n_url;
	std::string str_render;

	const size_t pos2 = str_type.rfind('/');
	str_render = str_type.substr(pos2+1);

	//SDL_Color color;
	if(isDir()){
	    render(str_render, COLOR_DIR_R, COLOR_DIR_G, COLOR_DIR_B);
	}
	else{
	    render(str_render, COLOR_FRONT_R, COLOR_FRONT_G, COLOR_FRONT_B);
	}

	//PluginEntry::render(ii-pos, str_render.c_str(), color);
    }
    else{
	render(std::string(".."), COLOR_DIR_R, COLOR_DIR_G, COLOR_DIR_B);
    }
}
