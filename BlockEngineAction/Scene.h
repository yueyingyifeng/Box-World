#pragma once
#include"formBlockEngine.h"
/*
* �ṩ����
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
	//��ȡ�����µ�block - char����
	char look(Coordinate cdnt);
	//����������block�滻��target
	void set(Coordinate cdnt, char target = ' ');
	//�滻���������е�clearΪtarget,targetĬ��Ϊ' '
	void replace(char clear,char target = ' ');
};	

