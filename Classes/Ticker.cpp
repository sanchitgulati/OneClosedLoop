//
//  Ticker.cpp
//  OneClosedLoop
//
//  Created by Sanchit Gulati on 23/03/14.
//
//

#include "Ticker.h"

USING_NS_CC;

Ticker::Ticker(std::string *messageArray, int size, const char *fontName, int fontSize, float delay) {
    _messageArray = messageArray;
    _size = size;
    _delay = delay;
    
    LabelTTF::initWithString(_messageArray[0].c_str(), fontName, fontSize);
    
    ctr = 0;
    
    schedule(schedule_selector(Ticker::updateTicker), _delay);
}

Ticker::Ticker(std::string *messageArray, int size, const char *fontName, int fontSize, Size dimension, TextHAlignment hAlignment, float delay) {
    _messageArray = messageArray;
    _size = size;
    _delay = delay;
    
    LabelTTF::initWithString(_messageArray[0].c_str(), fontName, fontSize, dimension, hAlignment);
    
    ctr = 0;
    
    schedule(schedule_selector(Ticker::updateTicker), _delay);
}

Ticker::Ticker(std::string *messageArray, int size, const char *fontName, int fontSize, Size dimension, TextHAlignment hAlignment, TextVAlignment vAlignment, float delay) {
    _messageArray = messageArray;
    _size = size;
    _delay = delay;
    
    LabelTTF::initWithString(_messageArray[0].c_str(), fontName, fontSize, dimension, hAlignment, vAlignment);
    
    ctr = 0;
    
    schedule(schedule_selector(Ticker::updateTicker), _delay);
}

Ticker* Ticker::create(std::string *messageArray, int size, const char* fontName, int fontSize, float delay) {
    Ticker *ticker = new Ticker(messageArray, size, fontName, fontSize, delay);
    ticker->autorelease();
    return ticker;
}

Ticker* Ticker::create(std::string *messageArray, int size, const char* fontName, int fontSize, Size dimension, TextHAlignment hAlignment, float delay) {
    Ticker *ticker = new Ticker(messageArray, size, fontName, fontSize, dimension, hAlignment, delay);
    ticker->autorelease();
    return ticker;
}

Ticker* Ticker::create(std::string *messageArray, int size, const char* fontName, int fontSize, Size dimension, TextHAlignment hAlignment, TextVAlignment vAlignment, float delay) {
    Ticker *ticker = new Ticker(messageArray, size, fontName, fontSize, dimension, hAlignment, vAlignment, delay);
    ticker->autorelease();
    return ticker;
}

void Ticker::updateTicker(float f) {
    FadeOut *fadeOutAction = FadeOut::create(_delay/4);
    FadeIn *fadeInAction = FadeIn::create(_delay/4);
    
    CallFunc *callAction = CallFunc::create(this, callfunc_selector(Ticker::updateString));
    runAction(Sequence::create(fadeOutAction, callAction, fadeInAction, NULL));
}

void Ticker::updateString() {
    ctr++;
    if (ctr == _size) {
        ctr = 0;
    }
    
    setString(_messageArray[ctr].c_str());
}