#pragma once
#include "formBlockEngineAction.h"
#include"MonsterList.h"

/*
地图的显示与怪的保存
*/
class Map :
    public Scene
{
    //此地图所保存的怪
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

