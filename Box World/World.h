#pragma once
#include"formBlockEngineAction.h"
#include"Player.h"
#include"MapList.h"
#include"Ui.h"
#include <string.h>

enum class TouchType{
	//空气， 墙    钥匙 金币  门   传送门    商店  小怪  大怪   boss
	nothing,wall,key,coin,door, portal, store,mon_s,mon_b,boss,
};
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
	
	

	//随机数 从min到max
	inline int Random(int min = 0, int max = 1);
	//清屏
	void cls()						{ system("cls"); }
	//暂停
	void pas()						{ system("pause"); }
	//返回玩家所在的地图
	Map& getMapByPlayerPosition()	{ return mapList->getMap(player->getPosition()); }
	//算出玩家试图朝向的前一个坐标是什么Block
	Block PlayerTryToMoveBlock(Dir dir);
	//算出玩家朝向的前一个坐标
	Coordinate PlayerTryToMove(Dir dir);
	//根据Block得出对应操作
	TouchType opterater(Block block);
	//根据得出的对应操作进行最终操作 (>_<) 得出的操作 玩家的移动方向
	void Next(TouchType type, Dir dir);
	//玩家移动,并绘制玩家
	void playerMove(Dir dir);
	//进入战斗
	void battle(Dir prepare);
	//转移玩家到另外一张地图
	void portal();
	//开门
	void openTheDoor(Dir dir);
	//商店
	void store();
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
	}
	//显示当前加载的地图
	void displayMap();

	//刷新,重要方法:玩家每一次操作均调用一次此方法
	void refresh(Dir playerMove);

	//根据玩家的的坐标绘画玩家
	void paintPlayer();

	//返回玩家所在场景的场景
	Map& getMap(int playerPosition);

	//添加场景列表
	void addMapList(MapList* mapList)	{ this->mapList = mapList; }
	//添加玩家
	void addPlayer(Player* player)		{ this->player = player; }
};

