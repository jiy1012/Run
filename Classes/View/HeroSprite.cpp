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
    jumping = false;
    oPositionY = 0;
    tempPositionY = 0;
    HeroSprite::createHero();
    HeroSprite::listenKeyboardEvent();
    return true;
}

void HeroSprite::createHero(){
    this->removeAllChildren();
    auto hero = Sprite::create("image/hero/right.png");
    hero->setAnchorPoint(Vec2(0.5,0));
    float init = HERO_SPRITE_INIT_DIRECTION;
    hero->setScaleX(init);
    heroSprite = hero;
    this->addChild(hero);
}

void HeroSprite::heroMove(float dt){
    float distance = dt * (float) moveDirection * HERO_SPRITE_SPEED;
    setScaleX(moveDirection);
    float positionX = getPositionX()+distance;
    setPositionX(positionX);
    CCLOG("HERO SPRITE POSITION X:%f",positionX);
}

void HeroSprite::heroJump(float dt){
    //y=ax2+bx+c
    //
    float s = -100*(jumping*jumping)+200*jumping;
    jumping += dt;
//    CCLOG("S:%f jump:%f tempY:%f oY:%f",s,jumping,tempPositionY,oPositionY);//cocos2d: S:1.650432 dt:0.016640
    
    float positionY = tempPositionY+s;
    if (positionY > oPositionY) {
        setPositionY(positionY);
    }else{
        setPositionY(oPositionY);
        jumping = 0;
    }
    
}


void HeroSprite::update(float dt){
    if(moveDirection != 0){
        heroMove(dt);
    }
    if (jumping > 0) {
        heroJump(dt);
    }
}

void HeroSprite::listenKeyboardEvent(){
    this->_eventDispatcher->removeAllEventListeners();
    auto keylistener = EventListenerKeyboard::create();
    keylistener->onKeyPressed = CC_CALLBACK_2(HeroSprite::keyboardPressed,this);
    keylistener->onKeyReleased = CC_CALLBACK_2(HeroSprite::keyboardReleased,this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener,this);
}

void HeroSprite::keyboardPressed(EventKeyboard::KeyCode kCode , Event* evt){
    //EventKeyboard::KeyCode::KEY_UP_ARROW
    //EventKeyboard::KeyCode::KEY_ENTER
    CCLOG("Pressed hero %d",(int) kCode);
    switch (kCode)
    {
        case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            moveLeft = true;
            changeDirection();
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            moveRight = true;
            changeDirection();
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
//            if (jumping <= 0) {
                jumping = 0.01;
//            }
            tempPositionY = getPositionY();
            if (oPositionY == 0) {
                oPositionY = getPositionY();
            }
            break;
        default:
            break;
    }
}
void HeroSprite::keyboardReleased(EventKeyboard::KeyCode kCode , Event* evt){
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
        case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
            break;
        default:
            break;
    }

}

void HeroSprite::changeDirection(){
    if (moveLeft && moveRight) {
        moveDirection = 0;
        heroSprite->stopAction(heroAction);
        createHero();
    }else if (moveLeft){
        moveDirection = -1;
        runningAnimation();
    }else if (moveRight){
        moveDirection = 1;
        runningAnimation();
    }else{
        moveDirection = 0;
        heroSprite->stopAction(heroAction);
        createHero();
    }

}

void HeroSprite::runningAnimation(){
    Vector<SpriteFrame*> allFrames;
    char name[100] = {};
    for (int i = 0; i<3; i++) {
        sprintf(name, "image/hero/right0%d.png",i);
        SpriteFrame* sf = SpriteFrame::create(name, Rect(0,0,60,100));
        allFrames.pushBack(sf);
    }
    Animation* ani = Animation::createWithSpriteFrames(allFrames,0.1);
    heroAction = heroSprite->runAction(RepeatForever::create(Animate::create(ani)));
}

void HeroSprite::exitGame(){
    MessageBox("You press the quit button.","quit game");
    Director::getInstance()->end();
}