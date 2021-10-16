#pragma once
#include"Map.h"
//空气
const char cEmpty{ ' ' };
//墙
const char cWall{ '#' };
//钥匙
const char cKey{ '!' };
//门
const char cDoor{ '%' };
//传送标记点
const char cPortal{ '+' };
//金币
const char cCoin{ 'c' };
//商店
const char cStore{ '$' };
//小怪
const char cMon_s{ '&' };
//大怪
const char cMon_b{ '@' };
//Boss
const char cBoss{ 'B' };
/*
* 此类保存所新建的表
* 需要将此类实例放入World类中才能让玩家与场景互动
*/
class MapList
{
	Map* map_data;
	int size;

	void arr_copy(Map* From, Map* to, int length) {
		for (int n{}; n < length; n++) {
			to[n] = From[n];
		}
	}
public:
	MapList() {
		size = 0;
		map_data = nullptr;
	}
	MapList(Map* map_data, int size)
		: map_data(map_data), size(size)
	{

	}
	//获取指定下标的场景 注：返回指针，此修改为永久性
	Map& getMap(int index) {
		return map_data[index];
	}

	//添加一张地图
	void addScene(Map& scene) {
		Map* temp = new Map[size + 1];

		arr_copy(map_data, temp, size);
		temp[size++] = scene;

		this->map_data = new Map[size];
		arr_copy(temp, map_data, size);
	}
};

