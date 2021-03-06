//
//  HeroSprite.h
//  Run
//
//  Created by liuyi on 14/10/24.
//
//

#ifndef __Run__HeroSprite__
#define __Run__HeroSprite__

#include "FFConfig.h"
class HeroSprite :	public Sprite
{
public:
    CREATE_FUNC( HeroSprite );
    bool init();
    void createHero();
    
    void heroMove(float dt);
    void heroJump(float dt);
    
    int moveDirection;
    bool moveLeft;
    bool moveRight;
    
    float jumping;
    float oPositionY;
    float tempPositionY;
    
    Sprite* heroSprite;
    Action* heroAction;
    
    void update(float dt);
    
    void changeDirection();
    void runningAnimation();
    
    void listenKeyboardEvent();
    void keyboardPressed(EventKeyboard::KeyCode kCode , Event* evt);
    void keyboardReleased(EventKeyboard::KeyCode kCode , Event* evt);
    
    void exitGame();
};

#endif /* defined(__Run__HeroSprite__) */
