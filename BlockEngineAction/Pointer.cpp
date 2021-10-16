#include "Pointer.h"

bool Pointer::isWillTouch(Coordinate cdnt, char notTarget)
{
	return (scene->look(Coordinate(cdnt.x, cdnt.y)) == notTarget) ?  true : false  ;
}
//��Ϊ�ɰ��ƶ���ʽ
bool Pointer::moveLeft(char notTarget)
{
	if (isWillTouch(Coordinate(cdnt->x - 1, cdnt->y), notTarget)) {
		return false;//�������ʲô�����ͷ��ؼ�
	}
	else {
		Pixel(*cdnt);
		Pixel(--cdnt->x, cdnt->y, style);
		return true;//û�����򷵻���
	}
}

bool Pointer::moveUp(char notTarget)
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

bool Pointer::moveRight(char notTarget)
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

bool Pointer::moveDown(char notTarget)
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

void Pointer::input()
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

void Pointer::input(char key)
{

	switch (key)
	{
	case 'A':
	case 'a':
		Pixel(*cdnt);
		Pixel(--cdnt->x, cdnt->y, style);
		break;
	case 'W':
	case 'w':
		Pixel(*cdnt);
		Pixel(cdnt->x, --cdnt->y, style);
		break;
	case 'D':
	case 'd':
		Pixel(*cdnt);
		Pixel(++cdnt->x, cdnt->y, style);
		break;
	case 'S':
	case 's':
		Pixel(*cdnt);
		Pixel(cdnt->x, ++cdnt->y, style);
		break;
	default:
		std::cout << "not this command" << std::endl;
		break;
	}
}
