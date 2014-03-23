//
//  LevelXML.cpp
//  OneClosedLoop
//
//  Created by Sanchit Gulati on 23/03/14.
//
//


#include "LevelXML.h"


pugi::xml_document LevelXML::doc;

bool LevelXML::init()
{
    
	FileUtils *sharedFileUtils = FileUtils::getInstance();
    Data data = sharedFileUtils->getDataFromFile("levels.xml");
    
    unsigned char* pBuffer = data.getBytes();
    unsigned long nSize = data.getSize();
    
    if (!doc.load_buffer(pBuffer, nSize))
        return false;
    
    return true;
}



void LevelXML::traverse()
{
    pugi::xml_node levels = doc.child("bundle");
    
    log("Bundle");
    
    //[code_traverse_base_basic
    for (pugi::xml_node level = levels.first_child(); level; level = level.next_sibling())
    {
        
        log("Level");
        
        for (pugi::xml_attribute attr = level.first_attribute(); attr; attr = attr.next_attribute())
        {
            log(" Name %s Value %s ",attr.name(),attr.value());
            for (pugi::xml_attribute attr = level.first_attribute(); attr; attr = attr.next_attribute())
            {
                log(" Name %s Value %s ",attr.name(),attr.value());
            }
        }
    }
}