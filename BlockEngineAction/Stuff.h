#pragma once
#include"Scene.h"
#include<conio.h>

constexpr auto EMPTY = ' ';
/*
* �ṩ����������꣬��ʽ
*/
class Stuff
{
protected:
	Coordinate* cdnt;
	char style;
	Scene* scene;
public:
	//���꣬��ʽ�����ڵĳ���
	Stuff(Coordinate* cdnt, char style, Scene& scene)
		:style(style),scene(&scene) 
	{
		this->cdnt = cdnt;
		this->style = style;
		this->scene = &scene;
	}
};

