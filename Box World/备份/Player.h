#pragma once
#include "formBlockEngineAction.h"
enum class Dir
{
	none, up, down, left, right
};

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
	int ak;
	int keys;
	int coin;
	int position;
	bool isPlayerFaildToMove{ false };
	Dir dir = Dir::none;
	Dir tryToMove = Dir::none;
	Part part = Part::none;

	Coordinate touch;

	 
	//尝试往上走，如果碰到东西就返回真
	bool moveUp();
	//尝试往下走，如果碰到东西就返回真
	bool moveDown();
	//尝试往左走，如果碰到东西就返回真
	bool moveLeft();
	//尝试往右走，如果碰到东西就返回真
	bool moveRight();
public:
	Player() {}

	Player(Coordinate* cdnt, char style, Scene& scene) 
		: Pointer(cdnt, style, scene)
	{
		Pixel(cdnt, style);
		hp = 50;
		hp_max = 50;
		ak = 4;
		position = 0;

		coin = 0;
		keys = 0;
	}
	
	//玩家输入
	void input();
	//玩家是否死亡
	bool isdead();
	//玩家是否碰到跳转点
	bool isJump();
	//显示玩家信息
	void showPlayerInfo(bool debug = false);
//---------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------//
	//设置玩家所在地图
	void setPosition(int position)									{ this->position = position; }
	//设置玩家角色
	void setPlayerPart(Part part)									{ this->part = part; }
	//设置玩家场景与位置
	void setPlayerSceneAndPosition(Scene& scene, Coordinate* cdnt)  { this->scene = &scene,
																	  this->cdnt = cdnt; }
	//设置玩家样式
	void setPlayerStyle(char c)										{ this->style = c; }

	//减少玩家 hit血量
	void decreaseHp(int hit)	{ hp -= hit; }

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
	//获取玩家攻击力
	int getAk()					{ return ak; }
	//获取玩家生命值
	int getHp()					{ return hp; }
};

