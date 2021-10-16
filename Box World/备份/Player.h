#pragma once
#include "formBlockEngineAction.h"
enum class Dir
{
	none, up, down, left, right
};

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
	int ak;
	int keys;
	int coin;
	int position;
	bool isPlayerFaildToMove{ false };
	Dir dir = Dir::none;
	Dir tryToMove = Dir::none;
	Part part = Part::none;

	Coordinate touch;

	 
	//���������ߣ�������������ͷ�����
	bool moveUp();
	//���������ߣ�������������ͷ�����
	bool moveDown();
	//���������ߣ�������������ͷ�����
	bool moveLeft();
	//���������ߣ�������������ͷ�����
	bool moveRight();
public:
	Player() {}

	Player(Coordinate* cdnt, char style, Scene& scene) 
		: Pointer(cdnt, style, scene)
	{
		Pixel(cdnt, style);
		hp = 50;
		hp_max = 50;
		ak = 4;
		position = 0;

		coin = 0;
		keys = 0;
	}
	
	//�������
	void input();
	//����Ƿ�����
	bool isdead();
	//����Ƿ�������ת��
	bool isJump();
	//��ʾ�����Ϣ
	void showPlayerInfo(bool debug = false);
//---------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------//
	//����������ڵ�ͼ
	void setPosition(int position)									{ this->position = position; }
	//������ҽ�ɫ
	void setPlayerPart(Part part)									{ this->part = part; }
	//������ҳ�����λ��
	void setPlayerSceneAndPosition(Scene& scene, Coordinate* cdnt)  { this->scene = &scene,
																	  this->cdnt = cdnt; }
	//���������ʽ
	void setPlayerStyle(char c)										{ this->style = c; }

	//������� hitѪ��
	void decreaseHp(int hit)	{ hp -= hit; }

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
	//��ȡ��ҹ�����
	int getAk()					{ return ak; }
	//��ȡ�������ֵ
	int getHp()					{ return hp; }
};

