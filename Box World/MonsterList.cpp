#include "MonsterList.h"

void MonsterList::arr_Copy(Monster* original, Monster* target, int targetSize)
{
	std::cout <<"MonsterList.cpp 5: " << target->getHp();
	for (int n{}; n < targetSize; n++) {
		target[n] = original[n];
	}
}

void MonsterList::arr_Copy(Monster* original, Monster* target, int targetSize, int notThisOne)
{
	for (int n{}, i{}; n < targetSize; n++) {
		if (n != notThisOne) {
			target[i++] = original[n];
		}
		
	}
}

Monster* MonsterList::getMonster(Coordinate cdnt)
{
	if (!isEmpty()) {

		for (int n{}; n < size; n++) {
			//std::cout << "MonsterList.cpp 24: " << monster_data[2].getAk();
			if (monster_data[n].getCodnt() == cdnt) {
				return &monster_data[n];
			}
		}

	}
}

void MonsterList::removeMon(int index)
{
	Monster* temp = new Monster[size-1];
	monster_data[index].die();
	arr_Copy(monster_data, temp, size--, index);//将还没改动的数据放入temp
	monster_data = new Monster[size];//根据新大小重新创建
	arr_Copy(temp, monster_data, size);//将改动后的数据再放回新的monster里面

}

int MonsterList::findMonsterByCdnt(Coordinate cdnt)
{
	for (int n{}; n < size; n++) {
		if (monster_data[n].getCodnt() == cdnt) {
			return n;
		}
	}
}
