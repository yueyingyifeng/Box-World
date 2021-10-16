#pragma once
#include"MonsterList.h"
#include"SceneList.h"
enum Type{monster,scene};

/*
����Ϊ�������ݵļ��ϣ�����ң�
*/
class Resource
{
	MonsterList* monsterListData;
	SceneList* sceneListData;
public:
	//��ȡ���� �ֱ� ��ͼ��
	Resource(MonsterList* mList,SceneList* sList)
		: monsterListData(mList), sceneListData(sList)
	{}

	template<typename T>
	T get(int index);

};