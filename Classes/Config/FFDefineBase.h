//
//  FFDefineBase.h
//  Run
//
//  Created by liuyi on 14-10-17.
//
//

#ifndef Run_FFDefineBase_h
#define Run_FFDefineBase_h

//获取屏幕长宽
#define GET_WIN_WIDTH Director::getInstance()->getWinSize().width
#define GET_WIN_HEIGHT Director::getInstance()->getWinSize().height
//获取visible屏幕长宽
#define GET_VISIBLE_WIDTH Director::getInstance()->getVisibleSize().width
#define GET_VISIBLE_HEIGHT Director::getInstance()->getVisibleSize().height

//类型转换
#define ITOA(i) CCString::createWithFormat("%d",i)->getCString()
#define ITOF(i) CCString::createWithFormat("%d",i)->floatValue()

#define FTOA(f) CCString::createWithFormat("%f",f)->getCString()
#define FTOI(f) CCString::createWithFormat("%f",f)->intValue()

#define ATOI(a) CCString::createWithFormat("%s",a)->intValue()
#define ATOF(a) CCString::createWithFormat("%s",a)->floatValue()







//project define
#define HERO_SPRITE_INIT_DIRECTION 1;
#define HERO_SPRITE_SPEED 200;
#define GAME_SPRITE_SPEED 0;


#endif
