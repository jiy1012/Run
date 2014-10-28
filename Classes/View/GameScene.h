//
//  GameScene.h
//  Run
//
//  Created by liuyi on 14/10/24.
//
//

#ifndef __Run__GameScene__
#define __Run__GameScene__

#include "FFConfig.h"
#include "HeroSprite.h"

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
    
    HeroSprite* hero;
    //
    void update(float dt);
    
};
#endif /* defined(__Run__GameScene__) */
