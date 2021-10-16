#pragma once
#include "Stuff.h"
#include"formBlockEngine.h"

class Entity :protected Stuff,public Pencil
{
protected:
	//�Ƿ������ ���꣬������� notTarget ������
	bool isWillTouch(Coordinate cdnt, char notTarget);
	//��ͼ�����ƶ���������� notTarget ������
	bool moveLeft(char notTarget = EMPTY);
	//��ͼ�����ƶ���������� notTarget ������
	bool moveUp(char notTarget = EMPTY);
	//��ͼ�����ƶ���������� notTarget ������
	bool moveRight(char notTarget = EMPTY);
	//��ͼ�����ƶ���������� notTarget ������
	bool moveDown(char notTarget = EMPTY);
	//������������
	void touch();
public:
	//���꣬��ʽ�����ڳ���
	Entity(Coordinate *cdnt, char style, Scene& scene) 
		: Stuff(cdnt, style, scene), Pencil(scene)
	{
		Pixel(*cdnt,style);
	}
	//��������
	void input();
};