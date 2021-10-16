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
	//�ù����������������
	void die()				{ Pixel(cdnt,' '); }
	//��ȡ����ֵ
	int getHp()				{ return hp; }
	//��ȡ������1
	int getAk1()			{ return ak1; }
	//��ȡ������2
	int getAk2()			{ return ak2; }
	//��ȡ������3
	int getAk3()			{ return ak3; }
	//��ȡ��������
	char getStyle()			{ return style; }
	//��ȡ��������
	Coordinate getCodnt()	{ return *cdnt;}

	//���ٹ��� hitѪ��
	void decreaseHp(int hit)		{ hp -= hit; }
};

