//
//  MenuScene.h
//  Run
//
//  Created by liuyi on 14/10/24.
//
//

#ifndef __Run__MenuScene__
#define __Run__MenuScene__

#include "FFConfig.h"

class MenuScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);
    
    void listenKeyboardEvent();
    
    void keyboardPressed(EventKeyboard::KeyCode kCode , Event* evt);
    void keyboardReleased(EventKeyboard::KeyCode kCode , Event* evt);
    void exitGame();
};

#endif /* defined(__Run__MenuScene__) */
