//
//  GameScene.cpp
//  Run
//
//  Created by liuyi on 14/10/24.
//
//

#include "GameScene.h"

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
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
    
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("GAME", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add "GameScene" splash screen"
    auto sprite = Sprite::create("image/scene/GameScene.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    hero = HeroSprite::create();
    hero->setPosition(121,200);
    this->addChild( hero );
    this->scheduleUpdate();
    return true;
}

void GameScene::update(float dt)
{
    hero->update(dt);
    //	CCLOG("exec %f",dt);
    float distance = dt * GAME_SPRITE_SPEED;
    float positionX = getPositionX() - distance;
    
    if (positionX >= -getContentSize().width) {
        setPositionX(positionX);
        CCLOG("GAME SPRITE POSITION X:%f",positionX);
    }

}
