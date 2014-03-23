#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__

#include "cocos2d.h"
#include "Constants.h"
#include "Ticker.h"
#include "TableLevel.h"
#include "LevelXML.h"

enum zindex
{
    zBg,
    zLogo
};

enum gamestate
{
    gsMenu,
};

USING_NS_CC;

class MainMenu : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    /*More Functions*/
    
    void update(float);
    
    /*Sanchit's Code*/
    static std::string creditStrings[CREDIT_SIZE];
    Size visibleSize;
    ccBlendFunc blendFunc;
    Size winSize;
    Point origin;
    float fontSize;
    float edgeMargin;
    
    LayerColor* lBackground;
    Sprite* sLogo;
    LabelTTF* lblLabel;
    Ticker *iTicker;
    TableLevel* iLevel;
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);
};

#endif // __MAINMENU_SCENE_H__