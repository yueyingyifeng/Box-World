#pragma once
#include "Monster.h"
/*
* 此类保存所新建的表
* 需要将此类实例放入World类中才能让玩家与怪互动
*/
class MonsterList
{
	Monster* monster_data;
	int size;

	//复制数组 原数组，目标数组，目标长度
	void arr_Copy(Monster* original, Monster* target, int targetSize);
	//复制数组 原数组，目标数组，目标长度,除了这个index
	void arr_Copy(Monster* original, Monster* target, int targetSize,int notThisOne);

public:
	MonsterList() {
		size = 0;
		monster_data = nullptr;
	}
	//存放怪数组，数组大小
	MonsterList(Monster* monster, int size)
		:  monster_data(monster),size(size)
	{
		
	}
	//根据坐标获取对应怪
	Monster* getMonster(Coordinate cdnt);
	//获取当前还剩几个怪
	// 
	//根据index移除一个怪
	void removeMon(int index);
	//根据 坐标 获取怪的下标
	int findMonsterByCdnt(Coordinate cdnt);
	//检查列表是否为空
	bool isEmpty() { return size <= 0 ? true : false; }
	
};

