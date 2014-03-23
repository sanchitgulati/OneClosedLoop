//
//  LevelXML.h
//  OneClosedLoop
//
//  Created by Sanchit Gulati on 23/03/14.
//
//

#ifndef __OneClosedLoop__LevelXML__
#define __OneClosedLoop__LevelXML__

#include <iostream>
#include "cocos2d.h"
#include "pugixml.hpp"

USING_NS_CC;

class LevelXML
{
public:
    static pugi::xml_document doc;
    static bool init();
    static void traverse();
};

#endif /* defined(__OneClosedLoop__LevelXML__) */
