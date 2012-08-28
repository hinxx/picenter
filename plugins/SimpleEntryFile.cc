#include "SimpleEntryFile.h"
#include "../conf.h"

SimpleEntryFile::SimpleEntryFile(const std::string& n_label, const std::string& n_url, const bool n_type)
{
    m_type = n_type; 
    m_url = n_url;

    if(isDir())
	render(n_label, COLOR_DIR_R, COLOR_DIR_G, COLOR_DIR_B);
    else
	render(n_label, COLOR_FRONT_R, COLOR_FRONT_G, COLOR_FRONT_B);
}
