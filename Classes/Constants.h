//
//  Constants.h
//  OneClosedLoop
//
//  Created by Sanchit Gulati on 22/03/14.
//
//

#ifndef __OneClosedLoop__Constants__
#define __OneClosedLoop__Constants__

#include <iostream>
#include "cocos2d.h"

#define CREDIT_SIZE 2

#define BG_RGBA 237,237,237,255
#define BG_RGB 237,237,237

#define LOGO_RGBA 128,215,232,255
#define LOGO_RGB 128,215,232

#define INNER_LOGO_RGBA 83,190,230,255
#define INNER_LOGO_RGB 83,190,230

#define H1_LABEL_RGBA 79,79,79,255
#define H1_LABEL_RGB 79,79,79

class Constants
{
public:
    static std::string fontName;
    static int defaultFontSize;
    
    
    //Variables
    static float vEdgeMargin;
};

#endif /* defined(__OneClosedLoop__Constants__) */
