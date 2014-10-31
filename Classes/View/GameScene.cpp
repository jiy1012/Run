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
    
    // create and initialize a label
    
    auto tip1 = LabelTTF::create("press RIGHT_ARROW to move", "Arial", 24);
    tip1->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - tip1->getContentSize().height));
    this->addChild(tip1, 1);
    auto tip2 = LabelTTF::create("press LEFT_ARROW to move", "Arial", 24);
    tip2->setPosition(Vec2(origin.x + visibleSize.width,
                           origin.y + visibleSize.height - tip2->getContentSize().height));
    this->addChild(tip2, 1);
    auto tip3 = LabelTTF::create("press SPACE to jump", "Arial", 24);
    tip3->setPosition(Vec2(origin.x + visibleSize.width*3/2,
                           origin.y + visibleSize.height - tip3->getContentSize().height));
    this->addChild(tip3, 1);
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
    
    if (positionX >= -getContentSize().width && positionX < getPositionX()) {
        setPositionX(positionX);
        CCLOG("GAME SPRITE POSITION X:%f",positionX);
    }

}
