#include "World.h"
#define CLS system("cls")
#define PAU system("pause")
void World::Dialog(std::string msg, bool line /*= true*/)
{
	if (line){
		std::cout << msg << std::endl;
	} 
	else{
		std::cout << msg;
	}
	
}
void World::Dialog(int msg, bool line /*= true*/)
{
	if (line) {
		std::cout << msg << std::endl;
	}
	else {
		std::cout << msg;
	}
}

int World::Random(int min /*= 0*/, int max /*= 1*/)
{
	return (rand() % (max - min + 1)) + min;
}

Coordinate World::PlayerTryToMove(Dir dir)
{
	switch (dir)
	{
	case Dir::up:
		return Coordinate(player->getX(), player->getY() - 1);
	case Dir::down:
		return Coordinate(player->getX(), player->getY() + 1);
	case Dir::left:
		return Coordinate(player->getX() - 1, player->getY());
	case Dir::right:
		return Coordinate(player->getX() + 1, player->getY());
	default:
		break;
	}
}

void World::paintPlayer()
{
	Pencil play(getMap(player->getPosition()),player->getStyle());
	//--------------清除上一步------------------//
	switch (player->getDir())
	{
	case Dir::up:
		play.Pixel(Coordinate(player->getX(), player->getY() + 1), ' ');
		break;
	case Dir::down:
		play.Pixel(Coordinate(player->getX(), player->getY() - 1), ' ');
		break;
	case Dir::left:
		play.Pixel(Coordinate(player->getX() + 1, player->getY()), ' ');
		break;
	case Dir::right:
		play.Pixel(Coordinate(player->getX() - 1, player->getY()), ' ');

		break;
	default:
		break;
	}

	play.Pixel(Coordinate(player->getX(), player->getY()),player->getStyle());

}

void World::opterater(Block block)
{
	switch (block.get())
	{
	case MON_STYLE:
		
		break;
	default:
		break;
	}
}

Map& World::getMap(int playerPosition)
{
	return mapList->getMap(playerPosition);
}


void World::displayMap()
{
	getMap(player->getPosition()).show();
}

void World::refresh()
{
	paintPlayer();
	
	if (player->getPlayerIsMove()) {
		MakePlayerStopPoint   = player->getTryDir();//保存玩家准备移动的方向
		cdntOfPlayerStopPoint = PlayerTryToMove(MakePlayerStopPoint) ;//算出阻碍玩家移动的坐标
		Block target(getMap(player->getPosition()).look(cdntOfPlayerStopPoint));//获取阻碍的Block
		std::cout << "WhatIs:" << target.get() << std::endl;
		opterater(target);//根据Block得出针对操作
	}
	//jump(player->getCodnt());

	
	std::cout << "World.cpp 110:"  << " playerIsMove:" << player->getPlayerIsMove() << std::endl;
}
