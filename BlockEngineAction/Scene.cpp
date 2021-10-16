#include "Scene.h"

char Scene::look(Coordinate cdnt)
{
	return block[cdnt.index(cdnt, x_max)].get();
}

void Scene::set(Coordinate cdnt, char target /*= ' '*/)
{
	block[cdnt.index(cdnt, x_max)].set(target);
}


void Scene::replace(char clear, char target /*= ' '*/)
{
	for (int n{}; n < x_max * y_max; n++) {
		if (block[n].get() == clear) {
			block[n].set(target);
		}
	}
}
