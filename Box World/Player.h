#pragma once
#include "formBlockEngineAction.h"

enum class Part {
	none, Humen,Magic,
};
/*
��ң����������ͣ���ͨ���࣬��ħ������
��ͨ���༼�ܣ���ǹ�������ǹ�����С��������
ħ�����༼�ܣ�ǿ�����⣬Ͷ��ħ��������������
*/
class Player :
	public Pointer
{
	int hp, hp_max;
	int ak1,ak2,ak3;
	int keys;
	int coin;
	int level, max_level{ 3 };
	int position;
	bool isPlayerFaildToMove{ false };
	int step{};
	Dir dir = Dir::none;
	Dir tryToMove = Dir::none;
	Part part = Part::none;
	bool isDebug{ false };
	Coordinate touch;
	int score{};//�÷�
	//�����
	int Random(int min = 0, int max = 1);
	//���������ߣ�������������ͷ����� �ѷ���
	bool moveUp();
	//���������ߣ�������������ͷ����� �ѷ���
	bool moveDown();
	//���������ߣ�������������ͷ����� �ѷ���
	bool moveLeft();
	//���������ߣ�������������ͷ����� �ѷ���
	bool moveRight();
public:
	Player() {
		hp = 10;
		level = 1;
		position = 5;
		level = 1;
		coin = 0;
		keys = 0;
	}

	Player(Coordinate* cdnt, char style, Scene& scene) 
		: Pointer(cdnt, style, scene)
	{
		Pixel(cdnt, style);
		hp = 10;
		level = 1;
		position = 5;
		coin = 0;
		keys = 0;
	}
	
	//�������
	Dir input();
	//����Ƿ�����
	bool isdead();
	//��ʾ�����Ϣ
	void showPlayerInfo();
	//�������Ѫ��������Ļ��ɫ
	void changeScreenByHp(color c1 = color::Blue, color c2 = color::Purple, color c3 = color::Red);
	//������ҵ÷�
	void countPlayerScore();
//---------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------//
	//����������ڵ�ͼ
	void setPosition(int position)									{ this->position = position; }
	//������ҽ�ɫ
	void setPlayerPart(Part part)									{ this->part = part; }
	//�������λ��
	void setPlayerCoordinate(Coordinate* cdnt)						{ this->cdnt = cdnt; }
	//������ҳ�����λ��
	void setPlayerSceneAndPosition(Scene& scene, Coordinate* cdnt) {
																	  this->scene = &scene,
																	  this->cdnt = cdnt;
																	}
	//���������ʽ
	void setPlayerStyle(char c)										{ this->style = c; }
	//��������������ֵ
	void setPlayerMaxHp(int number)									{ this->hp_max = number; }
	//�����Ѫ������
	void setPlayerHpMax()											{ hp = hp_max; }


	//������ҵĽ�ɫ
	Part getPart()				{ return part; }
	//��ȡ�����ʽ
	char getStyle()				{ return style; }
	//��ȡ���x����
	int getX()					{ return cdnt->x; }
	//��ȡ���y����
	int getY()					{ return cdnt->y; }
	//��ȡ����ƶ��ķ���
	Dir getDir()				{ return dir; }
	//��ȡ�������ͼ�ƶ��ĳ���
	Dir getTryDir()				{ return tryToMove; }
	//��ȡ����������ŵ�ͼ
	int getPosition()			{ return position; }
	//��ȡ�������������
	Coordinate getTouch()		{ return touch; }
	//��ȡ���Ŀǰ������
	Coordinate getCodnt()		{ return *cdnt; }
	//��ȡ����Ƿ�û�гɹ��ƶ�
	bool getPlayerIsMove()		{ return isPlayerFaildToMove; }

	//��ȡ��ҹ�����1
	int getAk1()				{ return ak1; }
	//��ȡ��ҹ�����2
	int getAk2()				{ return ak2; }
	//��ȡ��ҹ�����3
	int getAk3()				{ return ak3; }

	//��ȡ�������ֵ
	int getHp()					{ return hp; }
	//��ȡ����������ֵ
	int getMaxHp()				{ return hp_max; }

	//��ȡ��ҵĲ�����
	int getStep()				{ return step; }
	//��ȡԿ����
	int getKeys()				{ return keys; }
	//��ȡ�ȼ�
	int getLevel()				{ return level; }
	//��ȡ�����
	int getCoin()				{ return coin; }
	//����Ƿ���debug
	bool isDebugMode()			{ return isDebug; }
//---------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------//
	//������� hitѪ��
	void decreaseHp(int hit) { hp -= hit; }
	//����Կ������Ĭ��1
	void addKey(int number = 1)		{ keys += number; }
	//���ӵȼ���Ĭ��1
	void addLevel(int number = 1);
	//���ӽ������Ĭ��1
	void addCoin(int number = 1)	{ coin += number; }
	//�������Ѫ��,�����ᳬ�����ֵ
	void addHp(int number)			{ hp+number > hp_max ? 0 : hp += number; }
	//������ҵ÷�
	void addScore(int number)		{ score += number; }
};

