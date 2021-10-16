#pragma once
#include"formBlockEngine.h"
/*
* 提供场景
*/
class Scene:public Canvas
{
public:
	Scene() {}
	Scene(int x_max,int y_max)
		: Canvas(x_max,y_max)
	{
		init();
		fill();
	}
	//获取坐标下的block - char类型
	char look(Coordinate cdnt);
	//将这个坐标的block替换成target
	void set(Coordinate cdnt, char target = ' ');
	//替换场景中所有的clear为target,target默认为' '
	void replace(char clear,char target = ' ');
};	

