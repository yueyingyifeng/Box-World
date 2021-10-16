#pragma once
#include"formBlockEngineAction.h"
#include"Player.h"
#include"MapList.h"
#include"Ui.h"
#include <string.h>

enum class TouchType{
	//������ ǽ    Կ�� ���  ��   ������    �̵�  С��  ���   boss
	nothing,wall,key,coin,door, portal, store,mon_s,mon_b,boss,
};
//�������ʽ
const char MON_STYLE{ '&' };
//��Ϸ������ϵͳ
class World
{
	//�����籣��ĳ�����
	MapList* mapList;
	//������ı�������
	Player* player;


	Dir MakePlayerStopPoint;		//�������׼���ƶ��ķ���
	Coordinate cdntOfPlayerStopPoint;//����谭����ƶ�������,��refresh��������
	
	

	//����� ��min��max
	inline int Random(int min = 0, int max = 1);
	//����
	void cls()						{ system("cls"); }
	//��ͣ
	void pas()						{ system("pause"); }
	//����������ڵĵ�ͼ
	Map& getMapByPlayerPosition()	{ return mapList->getMap(player->getPosition()); }
	//��������ͼ�����ǰһ��������ʲôBlock
	Block PlayerTryToMoveBlock(Dir dir);
	//�����ҳ����ǰһ������
	Coordinate PlayerTryToMove(Dir dir);
	//����Block�ó���Ӧ����
	TouchType opterater(Block block);
	//���ݵó��Ķ�Ӧ�����������ղ��� (>_<) �ó��Ĳ��� ��ҵ��ƶ�����
	void Next(TouchType type, Dir dir);
	//����ƶ�,���������
	void playerMove(Dir dir);
	//����ս��
	void battle(Dir prepare);
	//ת����ҵ�����һ�ŵ�ͼ
	void portal();
	//����
	void openTheDoor(Dir dir);
	//�̵�
	void store();
public:
	//��ʱ�õģ�����������MonsterList���ʼ��������
	World() {
		mapList = nullptr;
		player = nullptr;
		MakePlayerStopPoint = Dir::none;
	}
	//���س����б��������
	World(MapList* mapList, Player& loadPlayer)
		:mapList(mapList), player(&loadPlayer)
	{
		MakePlayerStopPoint = Dir::none;
	}
	//��ʾ��ǰ���صĵ�ͼ
	void displayMap();

	//ˢ��,��Ҫ����:���ÿһ�β���������һ�δ˷���
	void refresh(Dir playerMove);

	//������ҵĵ�����滭���
	void paintPlayer();

	//����������ڳ����ĳ���
	Map& getMap(int playerPosition);

	//��ӳ����б�
	void addMapList(MapList* mapList)	{ this->mapList = mapList; }
	//������
	void addPlayer(Player* player)		{ this->player = player; }
};

