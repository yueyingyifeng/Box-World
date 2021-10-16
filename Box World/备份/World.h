#pragma once
#include"formBlockEngineAction.h"
#include"Player.h"
#include"MapList.h"
#include <string.h>


//怪物的样式
const char MON_STYLE{ '&' };
//游戏的整个系统
class World
{
	//此世界保存的场景表
	MapList* mapList;
	//此世界的保存的玩家
	Player* player;


	Dir MakePlayerStopPoint;		//保存玩家准备移动的方向
	Coordinate cdntOfPlayerStopPoint;//算出阻碍玩家移动的坐标,在refresh方法有用
	//输出一段提示信息,是否换行
	void Dialog(std::string msg,bool line = true);
	void Dialog(int msg, bool line = true);
	//随机数 从min到max
	inline int Random(int min = 0, int max = 1);
	//算出玩家试图朝向的前一个坐标
	Coordinate PlayerTryToMove(Dir dir);
	//根据Block得出对应操作
	void opterater(Block block);
	
	
public:
	//临时用的！！！！用于MonsterList类初始化数据用
	World() {
		mapList = nullptr;
		player = nullptr;
		MakePlayerStopPoint = Dir::none;
	}
	//加载场景列表，加载玩家
	World(MapList* mapList, Player& loadPlayer)
		:mapList(mapList), player(&loadPlayer)
	{
		MakePlayerStopPoint = Dir::none;
		//std::cout << "World.h 37:" << monList.getMonster(Coordinate(6, 3))->getAk();
	}
	//显示当前加载的地图
	void displayMap();

	//刷新,重要方法:玩家每一次操作均调用一次此方法
	void refresh();

	//根据玩家的的坐标绘画玩家
	void paintPlayer();

	//返回玩家所在场景的场景
	Map& getMap(int playerPosition);

	//添加场景列表
	void addMapList(MapList* mapList)	{ this->mapList = mapList; }
	//添加玩家
	void addPlayer(Player* player)		{ this->player = player; }
};

