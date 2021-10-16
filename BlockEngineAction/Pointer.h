#pragma once
#include "Stuff.h"
#include"formBlockEngine.h"
/*
* 提供单个Block的实体，一般来说此实体具备各种属性与能力
*/
class Pointer 
	: public Pencil
{
protected:
	Coordinate* cdnt;
	char style;
	Scene* scene;
	//是否会碰到 坐标，如果碰到 notTarget 就返回真 废弃
	bool isWillTouch(Coordinate cdnt, char notTarget);
	//试图向左移动，如果碰到 notTarget 则无视 废弃
	bool moveLeft(char notTarget = EMPTY);
	//试图向上移动，如果碰到 notTarget 则无视 废弃
	bool moveUp(char notTarget = EMPTY);
	//试图向右移动，如果碰到 notTarget 则无视 废弃
	bool moveRight(char notTarget = EMPTY);
	//试图向下移动，如果碰到 notTarget 则无视 废弃
	bool moveDown(char notTarget = EMPTY);
public:
	Pointer() {
		cdnt = nullptr;
		scene = nullptr;
		style = '?';
	}
	//坐标，样式，所在场景
	Pointer(Coordinate* cdnt, char style, Scene& scene)
		: Pencil(scene), cdnt(cdnt), style(style), scene(&scene)
	{
		Pixel(cdnt, style);
	}
	//接收输入
	void input();
	void input(char key);
};

