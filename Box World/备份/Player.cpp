#include "Player.h"

bool Player::moveUp()
{
	if (isWillTouch(Coordinate(cdnt->x, cdnt->y - 1), EMPTY)) {
		cdnt->y--;
		tryToMove = Dir::none;
		isPlayerFaildToMove = false;
		return false;
	}
	else {
		tryToMove = Dir::up;//�������ͼ�����ƶ���ȴʧ�ܣ�������tryToMove����
		isPlayerFaildToMove = true;//���������ƶ�ʧ��
		return true;
	}
}

bool Player::moveDown()
{
	if (isWillTouch(Coordinate(cdnt->x, cdnt->y + 1), EMPTY)) {
		cdnt->y++;
		tryToMove = Dir::none;
		isPlayerFaildToMove = false;
		return false;
	}
	else {
		tryToMove = Dir::down;
		isPlayerFaildToMove = true;
		return true;
	}
}

bool Player::moveLeft()
{
	if (isWillTouch(Coordinate(cdnt->x - 1, cdnt->y), EMPTY)) {
		cdnt->x--;
		tryToMove = Dir::none;
		isPlayerFaildToMove = false;
		return false;
	}
	else {
		tryToMove = Dir::left;
		isPlayerFaildToMove = true;
		return true;
	}
}

bool Player::moveRight()
{
	if (isWillTouch(Coordinate(cdnt->x + 1, cdnt->y), EMPTY)) {
		cdnt->x++;
		tryToMove = Dir::none;
		isPlayerFaildToMove = false;
		return false;
	}
	else {
		tryToMove = Dir::right;
		isPlayerFaildToMove = true;
		return true;
	}
}

void Player::input()
{
	char key = _getch();
	switch (key)
	{
	case 'W':
	case 'w':
		if (moveUp()) {
			dir = Dir::none;
		}
		else {
			dir = Dir::up;
		}
	
		break;
	case 'S':
	case 's':
		if (moveDown()) {
			dir = Dir::none;
		}
		else {
			dir = Dir::down;
		}
		break;
	case 'A':
	case 'a':
		if (moveLeft()) {
			dir = Dir::none;
		}
		else {
			dir = Dir::left;
		}
		break;
	case 'D':
	case 'd':
		if (moveRight()) {
			dir = Dir::none;
		}
		else {
			dir = Dir::right;
		}
		break;
	default:
		break;
	}
}

bool Player::isdead()
{
	return (hp <= 0) ? true : false;
}

void Player::showPlayerInfo(bool debug /*= false*/)
{
	std::cout 
		<< "---------------------" << std::endl
		<< "����ֵ: " << hp << "  ���: " << coin << std::endl
		<< "������: " << ak << "  Կ��: " << keys << std::endl;
	if (debug) {
		std::cout
			<< "---------------------" << std::endl
			<< "�������ֵ: " << hp_max << std::endl
			<< "x: " << cdnt->x << "  y: " << cdnt->y << std::endl;
	}
}
