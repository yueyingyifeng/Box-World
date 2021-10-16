#pragma once
#include"Map.h"
//����
const char cEmpty{ ' ' };
//ǽ
const char cWall{ '#' };
//Կ��
const char cKey{ '!' };
//��
const char cDoor{ '%' };
//���ͱ�ǵ�
const char cPortal{ '+' };
//���
const char cCoin{ 'c' };
//�̵�
const char cStore{ '$' };
//С��
const char cMon_s{ '&' };
//���
const char cMon_b{ '@' };
//Boss
const char cBoss{ 'B' };
/*
* ���ౣ�����½��ı�
* ��Ҫ������ʵ������World���в���������볡������
*/
class MapList
{
	Map* map_data;
	int size;

	void arr_copy(Map* From, Map* to, int length) {
		for (int n{}; n < length; n++) {
			to[n] = From[n];
		}
	}
public:
	MapList() {
		size = 0;
		map_data = nullptr;
	}
	MapList(Map* map_data, int size)
		: map_data(map_data), size(size)
	{

	}
	//��ȡָ���±�ĳ��� ע������ָ�룬���޸�Ϊ������
	Map& getMap(int index) {
		return map_data[index];
	}

	//���һ�ŵ�ͼ
	void addScene(Map& scene) {
		Map* temp = new Map[size + 1];

		arr_copy(map_data, temp, size);
		temp[size++] = scene;

		this->map_data = new Map[size];
		arr_copy(temp, map_data, size);
	}
};

