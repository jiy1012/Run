//
//  HeroSprite.cpp
//  Run
//
//  Created by liuyi on 14/10/24.
//
//

#include "HeroSprite.h"

bool HeroSprite::init(){
    Sprite::init();
    moveDirection = 0;
    moveLeft = false;
    moveRight = false;
    HeroSprite::createHero();
    HeroSprite::listenKeyboardEvent();
    return true;
}

void HeroSprite::createHero(){
    auto hero = Sprite::create("image/hero/right.png");
    hero->setAnchorPoint(Vec2(0.5,0));
    float init = HERO_SPRITE_INIT_DIRECTION;
    hero->setScaleX(init);
    this->addChild(hero);
}

void HeroSprite::heroMove(float dt){
    float distance = dt * (float) moveDirection * HERO_SPRITE_SPEED;
    setScaleX(moveDirection);
//    float positionX = MAX(MIN(getPositionX()+distance, GET_WIN_WIDTH),0);
    float positionX = getPositionX()+distance;
    setPositionX(positionX);
    CCLOG("HERO SPRITE POSITION X:%f",positionX);
}

void HeroSprite::update(float dt){
    if(moveDirection != 0){
        heroMove(dt);
    }
}

void HeroSprite::listenKeyboardEvent()
{
    this->_eventDispatcher->removeAllEventListeners();
    auto keylistener = EventListenerKeyboard::create();
    keylistener->onKeyPressed = CC_CALLBACK_2(HeroSprite::keyboardPressed,this);
    keylistener->onKeyReleased = CC_CALLBACK_2(HeroSprite::keyboardReleased,this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener,this);
}

void HeroSprite::keyboardPressed(EventKeyboard::KeyCode kCode , Event* evt)
{
    //EventKeyboard::KeyCode::KEY_UP_ARROW
    //EventKeyboard::KeyCode::KEY_ENTER
    CCLOG("Pressed hero %d",(int) kCode);
    switch (kCode)
    {
        case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            moveLeft = true;
            changeDirection();
//            direction = -1;
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            moveRight = true;
            changeDirection();
//            direction = 1;
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            break;
        default:
            break;
    }
}
void HeroSprite::keyboardReleased(EventKeyboard::KeyCode kCode , Event* evt)
{
    CCLOG("Released hero %d",(int) kCode);
    switch (kCode)
    {
        case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            moveLeft = false;
            changeDirection();
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            moveRight = false;
            changeDirection();
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE:
            HeroSprite::exitGame();
            break;
        default:
            break;
    }
}

void HeroSprite::changeDirection()
{
    if (moveLeft && moveRight) {
        moveDirection = 0;
    }else if (moveLeft){
        moveDirection = -1;
    }else if (moveRight){
        moveDirection = 1;
    }else{
        moveDirection = 0;
    }

}

void HeroSprite::exitGame()
{
    MessageBox("You press the quit button.","quit game");
    Director::getInstance()->end();
}