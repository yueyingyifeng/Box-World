#pragma once
#include "Stuff.h"
#include"formBlockEngine.h"
/*
* �ṩ����Block��ʵ�壬һ����˵��ʵ��߱���������������
*/
class Pointer 
	: public Pencil
{
protected:
	Coordinate* cdnt;
	char style;
	Scene* scene;
	//�Ƿ������ ���꣬������� notTarget �ͷ����� ����
	bool isWillTouch(Coordinate cdnt, char notTarget);
	//��ͼ�����ƶ���������� notTarget ������ ����
	bool moveLeft(char notTarget = EMPTY);
	//��ͼ�����ƶ���������� notTarget ������ ����
	bool moveUp(char notTarget = EMPTY);
	//��ͼ�����ƶ���������� notTarget ������ ����
	bool moveRight(char notTarget = EMPTY);
	//��ͼ�����ƶ���������� notTarget ������ ����
	bool moveDown(char notTarget = EMPTY);
public:
	Pointer() {
		cdnt = nullptr;
		scene = nullptr;
		style = '?';
	}
	//���꣬��ʽ�����ڳ���
	Pointer(Coordinate* cdnt, char style, Scene& scene)
		: Pencil(scene), cdnt(cdnt), style(style), scene(&scene)
	{
		Pixel(cdnt, style);
	}
	//��������
	void input();
	void input(char key);
};

