#pragma once
#include "Monster.h"
/*
* ���ౣ�����½��ı�
* ��Ҫ������ʵ������World���в����������ֻ���
*/
class MonsterList
{
	Monster* monster_data;
	int size;

	//�������� ԭ���飬Ŀ�����飬Ŀ�곤��
	void arr_Copy(Monster* original, Monster* target, int targetSize);
	//�������� ԭ���飬Ŀ�����飬Ŀ�곤��,�������index
	void arr_Copy(Monster* original, Monster* target, int targetSize,int notThisOne);

public:
	MonsterList() {
		size = 0;
		monster_data = nullptr;
	}
	//��Ź����飬�����С
	MonsterList(Monster* monster, int size)
		:  monster_data(monster),size(size)
	{
		
	}
	//���������ȡ��Ӧ��
	Monster* getMonster(Coordinate cdnt);
	//��ȡ��ǰ��ʣ������
	// 
	//����index�Ƴ�һ����
	void removeMon(int index);
	//���� ���� ��ȡ�ֵ��±�
	int findMonsterByCdnt(Coordinate cdnt);
	//����б��Ƿ�Ϊ��
	bool isEmpty() { return size <= 0 ? true : false; }
	
};

