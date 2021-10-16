#include "Entity.h"

bool Entity::isWillTouch(Coordinate cdnt, char notTarget)
{
	return (scene->look(Coordinate(cdnt.x, cdnt.y)) == notTarget) ? false : true;
}
void Entity::touch()
{
	std::cout << "you touch something,did't you" << std::endl;
}

bool Entity::moveLeft(char notTarget)
{
	if (isWillTouch(Coordinate(cdnt->x - 1, cdnt->y), notTarget)) {
		return false;//如果碰到什么东西就返回假
	}
	else {
		Pixel(*cdnt);
		Pixel(--cdnt->x, cdnt->y, style);
		return true;//没碰到则返回真
	}
}

bool Entity::moveUp(char notTarget)
{
	if (isWillTouch(Coordinate(cdnt->x, cdnt->y - 1), notTarget)) {
		return false;
	}
	else {
		Pixel(*cdnt);
		Pixel(cdnt->x, --cdnt->y, style);
		return true;
	}
}

bool Entity::moveRight(char notTarget)
{
	if (isWillTouch(Coordinate(cdnt->x + 1, cdnt->y), notTarget)) {
		return false;
	}
	else {
		Pixel(*cdnt);
		Pixel(++cdnt->x, cdnt->y, style);
		return true;
	}
}

bool Entity::moveDown(char notTarget)
{
	if (isWillTouch(Coordinate(cdnt->x, cdnt->y + 1), notTarget)) {
		return false;
	}
	else {
		Pixel(*cdnt);
		Pixel(cdnt->x, ++cdnt->y, style);
		return true;
	}
}

void Entity::input()
{
	char key = _getch();
	switch (key)
	{
	case 'A':
	case 'a':
		moveLeft();
		break;
	case 'W':
	case 'w':
		moveUp();
		break;
	case 'D':
	case 'd':
		moveRight();
		break; 
	case 'S':
	case 's':
		moveDown();
		break;
	default:
		std::cout << "not this command" << std::endl;
		break;
	}
}
