#pragma once
#include"formBlockEngineAction.h"
#include"Player.h"
#include"MapList.h"
#include <string.h>


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
	//���һ����ʾ��Ϣ,�Ƿ���
	void Dialog(std::string msg,bool line = true);
	void Dialog(int msg, bool line = true);
	//����� ��min��max
	inline int Random(int min = 0, int max = 1);
	//��������ͼ�����ǰһ������
	Coordinate PlayerTryToMove(Dir dir);
	//����Block�ó���Ӧ����
	void opterater(Block block);
	
	
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
		//std::cout << "World.h 37:" << monList.getMonster(Coordinate(6, 3))->getAk();
	}
	//��ʾ��ǰ���صĵ�ͼ
	void displayMap();

	//ˢ��,��Ҫ����:���ÿһ�β���������һ�δ˷���
	void refresh();

	//������ҵĵ�����滭���
	void paintPlayer();

	//����������ڳ����ĳ���
	Map& getMap(int playerPosition);

	//��ӳ����б�
	void addMapList(MapList* mapList)	{ this->mapList = mapList; }
	//������
	void addPlayer(Player* player)		{ this->player = player; }
};

