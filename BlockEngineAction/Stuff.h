#pragma once
#include"Scene.h"
#include<conio.h>

constexpr auto EMPTY = ' ';
/*
* 提供最基础的坐标，样式
*/
class Stuff
{
protected:
	Coordinate* cdnt;
	char style;
	Scene* scene;
public:
	//坐标，样式，所在的场景
	Stuff(Coordinate* cdnt, char style, Scene& scene)
		:style(style),scene(&scene) 
	{
		this->cdnt = cdnt;
		this->style = style;
		this->scene = &scene;
	}
};

