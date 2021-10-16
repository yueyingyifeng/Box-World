#pragma once
#include"formBlockEngineAction.h"



class Animation
{
    Scene* ui;

    char c;
    Coordinate cdnt;
    //移动这个像素点,默认一格
    void move(Dir dir, int step = 1);
public:
    Animation(Scene* ui)
        : ui(ui)
    {
        c = 1;
        cdnt = Coordinate(0, 0);
    }
    Animation(Scene* ui, char c)
        : ui(ui),c(c)
    {
        cdnt = Coordinate(0, 0);
    }
    //选中哪个像素点
    Animation& select(Coordinate cdnt);
    //朝这个方向进行移动 默认一格
    void refresh(Dir dir, int step = 1);
    
};

