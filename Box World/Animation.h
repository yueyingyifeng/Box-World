#pragma once
#include"formBlockEngineAction.h"



class Animation
{
    Scene* ui;

    char c;
    Coordinate cdnt;
    //�ƶ�������ص�,Ĭ��һ��
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
    //ѡ���ĸ����ص�
    Animation& select(Coordinate cdnt);
    //�������������ƶ� Ĭ��һ��
    void refresh(Dir dir, int step = 1);
    
};

