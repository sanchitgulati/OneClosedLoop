//
//  TableLevel.cpp
//  OneClosedLoop
//
//  Created by Sanchit Gulati on 23/03/14.
//
//

#include "TableLevel.h"

USING_NS_CC;
USING_NS_CC_EXT;


bool TableLevel::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    winSize = Director::getInstance()->getWinSize();
    tableSize = this->getContentSize();
    cellSize = Size(tableSize.width - 2*Constants::vEdgeMargin,220);
    tableSize = Size(winSize.width,winSize.height*0.80);
	TableView* tableView = TableView::create(this,Size(tableSize.width,tableSize.height));
	tableView->setDirection(ScrollView::Direction::VERTICAL);
    tableView->setAnchorPoint(Point(0,0));
    tableView->setPosition(Point(Constants::vEdgeMargin,0));
	tableView->setDelegate(this);
	tableView->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
	this->addChild(tableView);
	tableView->reloadData();
    
    return true;
}

void TableLevel::tableCellTouched(TableView* table, TableViewCell* cell)
{
//    CCLOG("cell touched at index: %ld", cell->getIdx());
    switch (cell->getIdx())
    {
        case 0:
        {
            Scene *s = Game::createScene();
            Director::getInstance()->replaceScene(CCTransitionFade::create(0.5,s));
        }
            break;
        default:
            break;
    }
}

Size TableLevel::tableCellSizeForIndex(TableView *table, ssize_t idx)
{
    return cellSize;
}

TableViewCell* TableLevel::tableCellAtIndex(TableView *table, ssize_t idx)
{
    auto string = String::createWithFormat("%ld", idx);
    TableViewCell *cell = table->dequeueCell();
    if (!cell) {
        cell = new TableViewCell(); //Can Be Customized, refer to TestCpp
        cell->autorelease();
        Sprite* sprite = Sprite::create("whiteRect.png");
        Size temp = sprite->getBoundingBox().size;
        sprite->setScale((cellSize.width/temp.width),1);
        if(idx == 1)
            sprite->setColor(Color3B(230,120,5));
        else if(idx == 0)
            sprite->setColor(Color3B(130,120,5));
        else if(idx == 2)
            sprite->setColor(Color3B(130,20,5));
        else if(idx == 3)
            sprite->setColor(Color3B(130,220,235));
        sprite->setAnchorPoint(Point::ZERO);
        sprite->setPosition(Point(0, 0));
        cell->addChild(sprite);
        
        auto label = LabelTTF::create(string->getCString(), Constants::fontName, Constants::defaultFontSize);
        label->setPosition(Point::ZERO);
		label->setAnchorPoint(Point::ZERO);
        label->setTag(123);
        cell->addChild(label);
    }
    else
    {
        auto label = (LabelTTF*)cell->getChildByTag(123);
        label->setString(string->getCString());
    }
    
    
    return cell;
}

ssize_t TableLevel::numberOfCellsInTableView(TableView *table)
{
    return 4;
}
