#pragma once
#include "Stuff.h"
#include"formBlockEngine.h"

class Entity :protected Stuff,public Pencil
{
protected:
	//是否会碰到 坐标，如果碰到 notTarget 就无视
	bool isWillTouch(Coordinate cdnt, char notTarget);
	//试图向左移动，如果碰到 notTarget 则无视
	bool moveLeft(char notTarget = EMPTY);
	//试图向上移动，如果碰到 notTarget 则无视
	bool moveUp(char notTarget = EMPTY);
	//试图向右移动，如果碰到 notTarget 则无视
	bool moveRight(char notTarget = EMPTY);
	//试图向下移动，如果碰到 notTarget 则无视
	bool moveDown(char notTarget = EMPTY);
	//碰到交互方法
	void touch();
public:
	//坐标，样式，所在场景
	Entity(Coordinate *cdnt, char style, Scene& scene) 
		: Stuff(cdnt, style, scene), Pencil(scene)
	{
		Pixel(*cdnt,style);
	}
	//接收输入
	void input();
};