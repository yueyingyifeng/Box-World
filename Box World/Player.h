#pragma once
#include "formBlockEngineAction.h"

enum class Part {
	none, Humen,Magic,
};
/*
玩家，有两种类型，普通人类，和魔法人类
普通人类技能：步枪射击，手枪射击，小刀，逃跑
魔法人类技能：强力激光，投掷魔法，棍击，逃跑
*/
class Player :
	public Pointer
{
	int hp, hp_max;
	int ak1,ak2,ak3;
	int keys;
	int coin;
	int level, max_level{ 3 };
	int position;
	bool isPlayerFaildToMove{ false };
	int step{};
	Dir dir = Dir::none;
	Dir tryToMove = Dir::none;
	Part part = Part::none;
	bool isDebug{ false };
	Coordinate touch;
	int score{};//得分
	//随机数
	int Random(int min = 0, int max = 1);
	//尝试往上走，如果碰到东西就返回真 已废弃
	bool moveUp();
	//尝试往下走，如果碰到东西就返回真 已废弃
	bool moveDown();
	//尝试往左走，如果碰到东西就返回真 已废弃
	bool moveLeft();
	//尝试往右走，如果碰到东西就返回真 已废弃
	bool moveRight();
public:
	Player() {
		hp = 10;
		level = 1;
		position = 5;
		level = 1;
		coin = 0;
		keys = 0;
	}

	Player(Coordinate* cdnt, char style, Scene& scene) 
		: Pointer(cdnt, style, scene)
	{
		Pixel(cdnt, style);
		hp = 10;
		level = 1;
		position = 5;
		coin = 0;
		keys = 0;
	}
	
	//玩家输入
	Dir input();
	//玩家是否死亡
	bool isdead();
	//显示玩家信息
	void showPlayerInfo();
	//根据玩家血量更改屏幕颜色
	void changeScreenByHp(color c1 = color::Blue, color c2 = color::Purple, color c3 = color::Red);
	//计算玩家得分
	void countPlayerScore();
//---------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------//
	//设置玩家所在地图
	void setPosition(int position)									{ this->position = position; }
	//设置玩家角色
	void setPlayerPart(Part part)									{ this->part = part; }
	//设置玩家位置
	void setPlayerCoordinate(Coordinate* cdnt)						{ this->cdnt = cdnt; }
	//设置玩家场景与位置
	void setPlayerSceneAndPosition(Scene& scene, Coordinate* cdnt) {
																	  this->scene = &scene,
																	  this->cdnt = cdnt;
																	}
	//设置玩家样式
	void setPlayerStyle(char c)										{ this->style = c; }
	//设置玩家生命最大值
	void setPlayerMaxHp(int number)									{ this->hp_max = number; }
	//让玩家血量回满
	void setPlayerHpMax()											{ hp = hp_max; }


	//返回玩家的角色
	Part getPart()				{ return part; }
	//获取玩家样式
	char getStyle()				{ return style; }
	//获取玩家x坐标
	int getX()					{ return cdnt->x; }
	//获取玩家y坐标
	int getY()					{ return cdnt->y; }
	//获取玩家移动的方向
	Dir getDir()				{ return dir; }
	//获取玩家曾试图移动的朝向
	Dir getTryDir()				{ return tryToMove; }
	//获取玩家所在哪张地图
	int getPosition()			{ return position; }
	//获取玩家碰到的坐标
	Coordinate getTouch()		{ return touch; }
	//获取玩家目前的坐标
	Coordinate getCodnt()		{ return *cdnt; }
	//获取玩家是否没有成功移动
	bool getPlayerIsMove()		{ return isPlayerFaildToMove; }

	//获取玩家攻击力1
	int getAk1()				{ return ak1; }
	//获取玩家攻击力2
	int getAk2()				{ return ak2; }
	//获取玩家攻击力3
	int getAk3()				{ return ak3; }

	//获取玩家生命值
	int getHp()					{ return hp; }
	//获取玩家最大生命值
	int getMaxHp()				{ return hp_max; }

	//获取玩家的操作数
	int getStep()				{ return step; }
	//获取钥匙数
	int getKeys()				{ return keys; }
	//获取等级
	int getLevel()				{ return level; }
	//获取金币数
	int getCoin()				{ return coin; }
	//玩家是否开启debug
	bool isDebugMode()			{ return isDebug; }
//---------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------//
	//减少玩家 hit血量
	void decreaseHp(int hit) { hp -= hit; }
	//增加钥匙数，默认1
	void addKey(int number = 1)		{ keys += number; }
	//增加等级，默认1
	void addLevel(int number = 1);
	//增加金币数，默认1
	void addCoin(int number = 1)	{ coin += number; }
	//增加玩家血量,但不会超过最大值
	void addHp(int number)			{ hp+number > hp_max ? 0 : hp += number; }
	//增加玩家得分
	void addScore(int number)		{ score += number; }
};

