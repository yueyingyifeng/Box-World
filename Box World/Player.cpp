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
		tryToMove = Dir::up;//玩家曾试图朝上移动但却失败，但记入tryToMove变量
		isPlayerFaildToMove = true;//并标记玩家移动失败
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
		case 'c'://增加金币
			addCoin();
			break;
		case 'k'://增加钥匙
			addKey();
			break;
		case 'l'://增加等级
			addLevel();
			break;
		case 'q'://自杀
			hp = -1;
			break;
		case '-'://减一滴血但不会死亡
			hp > 1 ? hp-- : 0;
			break;
		case '='://加一滴血但不会超过最大值
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
		<< "---------------------仅内部测试版" << std::endl
		<< "当前生命值: " << hp << "  金币: " << coin << std::endl
		<< "最大攻击力: " << ak1 << "  钥匙: " << keys << std::endl;*/
	if (isDebug) {
		std::cout
			<< "---------------------玩家已开启调试模式" << std::endl
			<< "最大生命值: " << hp_max << std::endl
			<< "x: " << cdnt->x << "  y: " << cdnt->y << std::endl
			<< "所在地图:" << position << " 已走步数:" << step << std::endl;
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
		std::cout << "你打败了boss了，在这里的故事结束了。但还会有更多......" << std::endl << std::endl;
	}
	else {
		switch (Random(0,6))
		{
		case 1:
			std::cout << "你没了" << std::endl;
			break;
		case 2:
			std::cout << "你消失了" << std::endl;
			break;
		case 3:
			std::cout << "这个世界对你没意义了" << std::endl;
			break;
		case 4:
			std::cout << "你对这个世界没意义了" << std::endl;
			break;
		case 5:
			std::cout << "游戏结束了" << std::endl;
			break;
		case 6:
			std::cout << "关灯了" << std::endl;
			break;
		}
	}
	std::cout << std::endl;
	char k{};
	while (k != 'f') {
		std::cout << "按f键查看得分" << std::endl;
		k = _getch();
	}
	score -= (step/6);		//步数需要减益
	score += (coin * 11);	//结束后有余金币加分
	std::cout << "你的最终得分是	-=| " << score << " |=-" << std::endl << std::endl;
	if (score >= 0) {
		if (score > 160) {
			std::cout << "厉害厉害，这个分数很高了" << std::endl;
		}
		else {
			switch (Random(1, 3)) {
			case 1:
				std::cout << "觉得还能更高吗？" << std::endl;
				break;
			case 2:
				std::cout << "我觉得还能更高" << std::endl;
				break;
			case 3:
				std::cout << "这分数还行,但应该还能更高" << std::endl;
				break;
			}
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "啊怎么会这样，我说是游戏出了问题了信不" << std::endl << std::endl;
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
