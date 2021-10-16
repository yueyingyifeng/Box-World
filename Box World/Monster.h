#pragma once
#include "formBlockEngineAction.h"
class Monster
	: public Pointer
{
	int hp{  };
	int ak1{  }, ak2{}, ak3{};

public:
	Monster() {}
	Monster(Coordinate* cdnt, char style, Scene& scene, int hp, int ak1, int ak2, int ak3)
		: Pointer(cdnt, style, scene), hp(hp), ak1(ak1), ak2(ak2), ak3(ak3)
	{
	}
	//让怪物死亡——清除怪
	void die()				{ Pixel(cdnt,' '); }
	//获取生命值
	int getHp()				{ return hp; }
	//获取攻击力1
	int getAk1()			{ return ak1; }
	//获取攻击力2
	int getAk2()			{ return ak2; }
	//获取攻击力3
	int getAk3()			{ return ak3; }
	//获取怪物样子
	char getStyle()			{ return style; }
	//获取怪物坐标
	Coordinate getCodnt()	{ return *cdnt;}

	//减少怪物 hit血量
	void decreaseHp(int hit)		{ hp -= hit; }
};

