//
//  Ticker.h
//  OneClosedLoop
//
//  Created by Sanchit Gulati on 23/03/14.
//
//

#ifndef __OneClosedLoop__Ticker__
#define __OneClosedLoop__Ticker__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class Ticker : public LabelTTF
{
    Ticker(std::string *messageArray, int size, const char* fontName, int fontSize, float delay);
    Ticker(std::string *messageArray, int size, const char* fontName, int fontSize, cocos2d::CCSize dimension, cocos2d::CCTextAlignment hAlignment, float delay);
    Ticker(std::string *messageArray, int size, const char* fontName, int fontSize, cocos2d::CCSize dimension, cocos2d::CCTextAlignment hAlignment, cocos2d::CCVerticalTextAlignment vAlignment, float delay);
    
    std::string *_messageArray;
    int _size;
    float _delay;
    int ctr;
public:
    static Ticker* create(std::string *messageArray, int size, const char* fontName, int fontSize, float delay = 2);
    static Ticker* create(std::string *messageArray, int size, const char* fontName, int fontSize, cocos2d::CCSize dimension, cocos2d::CCTextAlignment hAlignment, float delay = 2);
    static Ticker* create(std::string *messageArray, int size, const char* fontName, int fontSize, cocos2d::CCSize dimension, cocos2d::CCTextAlignment hAlignment, cocos2d::CCVerticalTextAlignment vAlignment, float delay = 2);
    void updateTicker(float);
    void updateString();
};

#endif /* defined(__OneClosedLoop__Ticker__) */
