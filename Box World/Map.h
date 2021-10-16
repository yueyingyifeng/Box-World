#pragma once
#include "formBlockEngineAction.h"
#include"MonsterList.h"

/*
��ͼ����ʾ��ֵı���
*/
class Map :
    public Scene
{
    //�˵�ͼ������Ĺ�
    MonsterList* monList;

public:
    Map() {}
    Map(int x_max, int y_max)
        : Scene(x_max, y_max)
    {
        monList = nullptr;
    }

    void addMonList(MonsterList* monList) { this->monList = monList; }
    MonsterList* getMonList() { return monList; }

};

