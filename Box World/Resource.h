#pragma once
#include"MonsterList.h"
#include"SceneList.h"
enum Type{monster,scene};

/*
此类为所有内容的集合（除玩家）
*/
class Resource
{
	MonsterList* monsterListData;
	SceneList* sceneListData;
public:
	//读取内容 怪表 地图表
	Resource(MonsterList* mList,SceneList* sList)
		: monsterListData(mList), sceneListData(sList)
	{}

	template<typename T>
	T get(int index);

};