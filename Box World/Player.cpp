#include "Player.h"

int Player::Random(int min /*= 0*/, int max /*= 1*/)
{
	srand((unsigned int)time(NULL));
	return (rand() % (max - min + 1)) + min;
}

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

Dir Player::input()
{

	step++;
	char key = _getch();
	if (isDebug) {
		switch (key)
		{
		case 'c'://���ӽ��
			addCoin();
			break;
		case 'k'://����Կ��
			addKey();
			break;
		case 'l'://���ӵȼ�
			addLevel();
			break;
		case 'q'://��ɱ
			hp = -1;
			break;
		case '-'://��һ��Ѫ����������
			hp > 1 ? hp-- : 0;
			break;
		case '='://��һ��Ѫ�����ᳬ�����ֵ
			hp > 0 && hp < hp_max ? hp++ : 0;
			break;
		default:
			break;
		}
	}
	switch (key)
	{
	case 'W':
	case 'w':
		return Dir::up;
		break;
	case 'S':
	case 's':
		return Dir::down;
		break;
	case 'A':
	case 'a':
		return Dir::left;
		break;
	case 'D':
	case 'd':
		return Dir::right;
		break;
	case '|':
		isDebug = true;
	default:
		return Dir::none;
		break;
	}
	
}

bool Player::isdead()
{
	return (hp <= 0) ? true : false;
}

void Player::showPlayerInfo()
{
	/*std::cout 
		<< "---------------------���ڲ����԰�" << std::endl
		<< "��ǰ����ֵ: " << hp << "  ���: " << coin << std::endl
		<< "��󹥻���: " << ak1 << "  Կ��: " << keys << std::endl;*/
	if (isDebug) {
		std::cout
			<< "---------------------����ѿ�������ģʽ" << std::endl
			<< "�������ֵ: " << hp_max << std::endl
			<< "x: " << cdnt->x << "  y: " << cdnt->y << std::endl
			<< "���ڵ�ͼ:" << position << " ���߲���:" << step << std::endl;
	}
	changeScreenByHp();
}

void Player::changeScreenByHp(color bc1 /*= color::Blue*/, color bc2 /*= color::Purple*/, color bc3 /*= color::Red*/)
{
	if (hp == hp_max) {
		scene->setBgColor(bc1);
	}
	else if(hp <= 7) {
		scene->setBgColor(bc3);
	}
	else if (hp < hp_max) {
		if (part == Part::Humen) {
			scene->setBgColor(color::LightGreen);
		}
		else if (part == Part::Magic) {
			scene->setBgColor(bc2);
		}
	}
	
}

void Player::countPlayerScore()
{
	if (hp > 0) {
		std::cout << "������boss�ˣ�������Ĺ��½����ˡ��������и���......" << std::endl << std::endl;
	}
	else {
		switch (Random(0,6))
		{
		case 1:
			std::cout << "��û��" << std::endl;
			break;
		case 2:
			std::cout << "����ʧ��" << std::endl;
			break;
		case 3:
			std::cout << "����������û������" << std::endl;
			break;
		case 4:
			std::cout << "����������û������" << std::endl;
			break;
		case 5:
			std::cout << "��Ϸ������" << std::endl;
			break;
		case 6:
			std::cout << "�ص���" << std::endl;
			break;
		}
	}
	std::cout << std::endl;
	char k{};
	while (k != 'f') {
		std::cout << "��f���鿴�÷�" << std::endl;
		k = _getch();
	}
	score -= (step/6);		//������Ҫ����
	score += (coin * 11);	//�����������Ҽӷ�
	std::cout << "������յ÷���	-=| " << score << " |=-" << std::endl << std::endl;
	if (score >= 0) {
		if (score > 160) {
			std::cout << "������������������ܸ���" << std::endl;
		}
		else {
			switch (Random(1, 3)) {
			case 1:
				std::cout << "���û��ܸ�����" << std::endl;
				break;
			case 2:
				std::cout << "�Ҿ��û��ܸ���" << std::endl;
				break;
			case 3:
				std::cout << "���������,��Ӧ�û��ܸ���" << std::endl;
				break;
			}
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "����ô����������˵����Ϸ�����������Ų�" << std::endl << std::endl;
	}
}

void Player::addLevel(int number /*= 1*/)
{
	level + number > max_level ? 0 : level += number;
	switch (level)
	{
	case 1:
		if (part == Part::Magic) {
			hp_max = 10;
			ak1 = 5;
			ak2 = 3;
			ak3 = 1;
		}
		else if (part == Part::Humen) {
			hp_max = 8;
			ak1 = 5;
			ak2 = 2;
			ak3 = 1;
		}
		break;
	case 2:
		if (part == Part::Magic) {
			hp_max = 13;
			ak1 = 7;
			ak2 = 4;
			ak3 = 2;
		}
		else if (part == Part::Humen) {
			hp_max = 12;
			ak1 = 6;
			ak2 = 4;
			ak3 = 2;
		}
		break;
	case 3:
		if (part == Part::Magic) {
			hp_max = 15;
			ak1 = 11;
			ak2 = 7;
			ak3 = 3;
		}
		else if (part == Part::Humen) {
			hp_max = 14;
			ak1 = 10;
			ak2 = 6;
			ak3 = 2;
		}
		break;
	default:
		break;
	}
}
