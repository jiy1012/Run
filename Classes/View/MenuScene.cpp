//
//  MenuScene.cpp
//  Run
//
//  Created by liuyi on 14/10/24.
//
//

#include "MenuScene.h"
#include "GameScene.h"

Scene* MenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MenuScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MenuScene::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Run", "Arial", 24);
    auto tip = LabelTTF::create("press ENTER button", "Arial", 24);
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    tip->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/4 + origin.y));
    // add the label as a child to this layer
    this->addChild(label, 1);
    this->addChild(tip);
    // add "MenuScene" splash screen"
    auto sprite = Sprite::create("image/scene/MenuScene.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->listenKeyboardEvent();
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}

void MenuScene::listenKeyboardEvent()
{
    this->_eventDispatcher->removeAllEventListeners();
    auto keylistener = EventListenerKeyboard::create();
    //	keylistener->onKeyPressed = CC_CALLBACK_2(MenuScene::keyboardPressed,this);
    keylistener->onKeyReleased = CC_CALLBACK_2(MenuScene::keyboardReleased,this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener,this);
}

void MenuScene::keyboardPressed(EventKeyboard::KeyCode kCode , Event* evt)
{
    //EventKeyboard::KeyCode::KEY_UP_ARROW
    //EventKeyboard::KeyCode::KEY_ENTER
    CCLOG("press %d",(int) kCode);
}
void MenuScene::keyboardReleased(EventKeyboard::KeyCode kCode , Event* evt)
{
    
    if(EventKeyboard::KeyCode::KEY_ESCAPE == kCode)
    {
        MenuScene::exitGame();
    }
    else if(EventKeyboard::KeyCode::KEY_KP_ENTER == kCode)
    {
        Director::getInstance()->replaceScene(GameScene::createScene());
    }
    CCLOG("Released %d",(int) kCode);
}

void MenuScene::exitGame()
{
    MessageBox("You press the quit button.","quit game");
    Director::getInstance()->end();
}

void MenuScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}