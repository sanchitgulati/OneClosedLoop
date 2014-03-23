#include "MainMenuScene.h"
#include "Util.h"

USING_NS_CC;

std::string MainMenu::creditStrings[CREDIT_SIZE] = {
    "A Game By Sanchit Gulati",
    "Deisgn By Radhika Dutt"
};

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenu::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::create() )
    {
        return false;
    }
    blendFunc = { GL_ONE, GL_ONE_MINUS_SRC_ALPHA };
    visibleSize = Director::getInstance()->getVisibleSize();
    winSize = Director::getInstance()->getWinSize();
    origin = Director::getInstance()->getVisibleOrigin();
    
    
    fontSize = Constants::defaultFontSize*(winSize.width/480);
    edgeMargin = winSize.width/20.0f;
    Constants::vEdgeMargin = edgeMargin; //Saving For Later, like : TableLevel
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MainMenu::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                 origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    //Sanchit Gulati
    
    lBackground = LayerColor::create(Color4B(BG_RGBA), winSize.width, winSize.height);
    this->addChild(lBackground,zBg);
    
    sLogo = Sprite::create("whiteCircle.png");
    sLogo->setAnchorPoint(Point(0, 1));
    sLogo->setPosition(edgeMargin,winSize.height-edgeMargin);
    sLogo->setScale(Util::getScreenRatio(sLogo)*0.1);
    sLogo->setColor(Color3B(LOGO_RGB));
//    sLogo->setBlendFunc(blendFunc);
    
    Sprite* sInnerCircle = Sprite::create("whiteCircle.png");
    sInnerCircle->setAnchorPoint(Point(0,0));
    sInnerCircle->setScale(0.8f);
    sInnerCircle->setColor(Color3B(INNER_LOGO_RGB));
    this->addChild(sLogo,zLogo);
    sLogo->addChild(sInnerCircle,zLogo);
    Rect sLogoParentBounding = sInnerCircle->getParent()->getBoundingBox();
    sInnerCircle->setPosition(Point(sLogoParentBounding.size.width/2, sLogoParentBounding.size.height/2));
    
    
    lblLabel = LabelTTF::create("One Closed Loop", Constants::fontName.c_str(), fontSize);
    lblLabel->setColor(Color3B(H1_LABEL_RGB));
    lblLabel->setAnchorPoint(Point(0,1));
    lblLabel->setPosition(Point(edgeMargin + sLogo->getBoundingBox().size.width, winSize.height-edgeMargin));
    this->addChild(lblLabel, zLogo);
    

    
    iTicker = Ticker::create(creditStrings, CREDIT_SIZE, Constants::fontName.c_str(), fontSize*0.4);
    float deltaHeight = lblLabel->getBoundingBox().size.height;
    float deltaWidth =  sLogo->getBoundingBox().size.width + lblLabel->getBoundingBox().size.width;
    iTicker->setColor(Color3B(H1_LABEL_RGB));
    iTicker->setAnchorPoint(Point(1,1));
    iTicker->setPosition(Point(edgeMargin + deltaWidth , winSize.height- edgeMargin - deltaHeight));
    this->addChild(iTicker,zLogo);
    
    iLevel = TableLevel::create();
    iLevel->setPosition(Point(0,0));
    this->addChild(iLevel,zLogo);
    
    LevelXML::init();
    LevelXML::traverse();
    
    
    this->scheduleUpdate();
    return true;
}


void MainMenu::update(float dt)
{
    
}


void MainMenu::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
