#include "World.h"


int World::Random(int min /*= 0*/, int max /*= 1*/)
{
	return (rand() % (max - min + 1)) + min;
}



void World::paintPlayer()
{
	Pencil p(getMapByPlayerPosition(),player->getStyle());
	getMapByPlayerPosition().replace(player->getStyle());//清除原来玩家的位置
	p.Pixel(player->getCodnt());

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
	}
}

Block World::PlayerTryToMoveBlock(Dir dir)
{
	switch (dir)
	{
	case Dir::none:
		break;
	case Dir::up:
		return Block(getMapByPlayerPosition()	//获取玩家所在地图
			.look(
				Coordinate(player->getX(), player->getY() - 1)
			));						//获取玩家准备移动的地方是什么类型的Block
		break;
	case Dir::down:
		return Block(getMapByPlayerPosition()	//获取玩家所在地图
			.look(
				Coordinate(player->getX(), player->getY() + 1)
			));
		break;
	case Dir::left:
		return Block(getMapByPlayerPosition()	//获取玩家所在地图
			.look(
				Coordinate(player->getX() - 1, player->getY())
			));
		break;
	case Dir::right:
		return Block(getMapByPlayerPosition()	//获取玩家所在地图
			.look(
				Coordinate(player->getX() + 1, player->getY())
			));
		break;
	default:
		break;
	}
}

TouchType World::opterater(Block block)
{
	switch (block.get())
	{
	case cEmpty:
		return TouchType::nothing;
	case cWall:
		return TouchType::wall;
	case cDoor:
		return TouchType::door;
	case cPortal:
		return TouchType::portal;
	case cStore:
		return TouchType::store; 
	case cCoin:
		return TouchType::coin;
	case cKey:
		return TouchType::key;
	case cMon_b:
		return TouchType::mon_b;
	case cMon_s:
		return TouchType::mon_s;
	case cBoss:
		return TouchType::boss;
		break;
	default:
		break;
	}
}

void World::Next(TouchType type, Dir dir)
{
	switch (type)
	{
	case TouchType::nothing:
		playerMove(dir);
		break;
	case TouchType::wall:
		//do nothing... DO NOT Write code in here!
		break;
	case TouchType::key:
		player->addKey();
		player->addScore(5);			//捡到金币加分
		playerMove(dir);
		break;
	case TouchType::coin:
		player->addCoin();
		playerMove(dir);
		break;
	case TouchType::door:
		openTheDoor(dir);
		break;
	case TouchType::store:
		store();
		break;
	case TouchType::mon_s:
		battle(dir);
		break;
	case TouchType::mon_b:
		if (player->getLevel() < 2) {
			Ui::Dialog("你目前装备等级低于2，可能会打不过。确定继续吗？ ---tips按e继续", 22);
			char c = _getch();
			if(c == 'e') {
				battle(dir);
			}
		}
		else {
			battle(dir);
		}
		break;
	case TouchType::boss:
		battle(dir);
		break;
	case TouchType::portal:
		portal();
		break;
	default:
		break;
	}
}

void World::playerMove(Dir dir)
{
	switch (dir)
	{
	case Dir::none:
		break;
	case Dir::up:
		player->setPlayerSceneAndPosition(
											getMapByPlayerPosition(),
											new Coordinate(	player->getX(),
															player->getY() - 1
															)
		);
		break;
	case Dir::down:
		player->setPlayerSceneAndPosition(
											getMapByPlayerPosition(),
											new Coordinate(	player->getX(),
															player->getY() + 1
															)
		);
		break;
	case Dir::left:
		player->setPlayerSceneAndPosition(
											getMapByPlayerPosition(),
											new Coordinate(	player->getX() - 1,
															player->getY()
															)
		);
		break;
	case Dir::right:
		player->setPlayerSceneAndPosition(
											getMapByPlayerPosition(),
											new Coordinate(	player->getX() + 1,
															player->getY()
															)
		);
		break;
	default:
		break;
	}
	paintPlayer();
}

void World::battle(Dir prepare)
{
	Monster* mon = new Monster();
	mon = getMapByPlayerPosition()
		.getMonList()->getMonster(PlayerTryToMove(prepare));
	
	Ui ui;
	ui.PlayerBattle(player,mon);

	if (mon->getHp() <= 0) {
		mon->die();
	}
}

void World::portal()
{
	int nowPlayerPosition = player->getPosition();
	//下面的if-else if是每张地图的传送点
	if (nowPlayerPosition == 0){
		if (player->getCodnt() == Coordinate(7, 3)) {
			player->setPosition(1);
			player->setPlayerCoordinate(new Coordinate(1, 3));
		}
	}

	if (nowPlayerPosition == 1) {
		if (player->getCodnt() == Coordinate(1, 3)) {
			player->setPosition(0);
			player->setPlayerCoordinate(new Coordinate(7, 3));
		}
		else if (player->getCodnt() == Coordinate(4, 5)) {
			player->setPosition(5);
			player->setPlayerCoordinate(new Coordinate(4, 1));
		}
	}

	if (nowPlayerPosition == 2) {
		if (player->getCodnt() == Coordinate(7, 1)) {
			player->setPosition(3);
			player->setPlayerCoordinate(new Coordinate(1, 1));
		}
	}

	if (nowPlayerPosition == 3) {
		if (player->getCodnt() == Coordinate(1, 1)) {
			player->setPosition(2);
			player->setPlayerCoordinate(new Coordinate(7, 1));
		}
		else if (player->getCodnt() == Coordinate(4, 5)) {
			player->setPosition(7);
			player->setPlayerCoordinate(new Coordinate(4, 1));
		}
	}

	if (nowPlayerPosition == 4) {
		if (player->getCodnt() == Coordinate(7, 3)) {
			player->setPosition(5);
			player->setPlayerCoordinate(new Coordinate(1, 3));
		}
		else if (player->getCodnt() == Coordinate(4, 5)) {
			player->setPosition(8);
			player->setPlayerCoordinate(new Coordinate(4, 1));
		}
	}

	if (nowPlayerPosition == 5) {
		if (player->getCodnt() == Coordinate(4, 1)) {
			player->setPosition(1);
			player->setPlayerCoordinate(new Coordinate(4, 5));
		}
		else if (player->getCodnt() == Coordinate(7, 3)) {
			player->setPosition(6);
			player->setPlayerCoordinate(new Coordinate(1, 3));
		}
	}

	if (nowPlayerPosition == 6) {
		if (player->getCodnt() == Coordinate(1, 3)) {
			player->setPosition(5);
			player->setPlayerCoordinate(new Coordinate(7, 3));
		}
		else if (player->getCodnt() == Coordinate(7, 1)) {
			player->setPosition(7);
			player->setPlayerCoordinate(new Coordinate(1, 1));
		}
	}
	if (nowPlayerPosition == 7) {
		if (player->getCodnt() == Coordinate(1, 1)) {
			player->setPosition(6);
			player->setPlayerCoordinate(new Coordinate(7, 1));
		}
		else if (player->getCodnt() == Coordinate(4, 1)) {
			player->setPosition(3);
			player->setPlayerCoordinate(new Coordinate(4, 5));
		}
		else if (player->getCodnt() == Coordinate(2, 5)) {
			player->setPosition(11);
			player->setPlayerCoordinate(new Coordinate(2, 1));
		}
	}

	if (nowPlayerPosition == 8) {
		if (player->getCodnt() == Coordinate(4, 1)) {
			player->setPosition(4);
			player->setPlayerCoordinate(new Coordinate(4, 5));
		}
		else if (player->getCodnt() == Coordinate(7, 3)) {
			player->setPosition(9);
			player->setPlayerCoordinate(new Coordinate(1, 3));
		}
	}

	if (nowPlayerPosition == 9) {
		if (player->getCodnt() == Coordinate(1, 3)) {
			player->setPosition(8);
			player->setPlayerCoordinate(new Coordinate(7, 3));
		}
		else if (player->getCodnt() == Coordinate(4, 1)) {
			player->setPosition(5);
			player->setPlayerCoordinate(new Coordinate(4, 5));
		}
		else if (player->getCodnt() == Coordinate(7, 3)) {
			player->setPosition(10);
			player->setPlayerCoordinate(new Coordinate(1, 3));
		}
	}

	if (nowPlayerPosition == 10) {
		if (player->getCodnt() == Coordinate(1, 3)) {
			player->setPosition(9);
			player->setPlayerCoordinate(new Coordinate(7, 3));
		}
		else if (player->getCodnt() == Coordinate(7, 3)) {//为什么？
			player->setPosition(11);
			player->setPlayerCoordinate(new Coordinate(1, 3));
		}
	}

	if (nowPlayerPosition == 11) {
		if (player->getCodnt() == Coordinate(1, 3)) {
			player->setPosition(10);
			player->setPlayerCoordinate(new Coordinate(7, 3));
		}
		else if (player->getCodnt() == Coordinate(2, 1)) {
			player->setPosition(7);
			player->setPlayerCoordinate(new Coordinate(4, 5));
		}
	}
	paintPlayer();
}

void World::openTheDoor(Dir dir)
{
	if (player->getKeys() >= 2) {
		player->addKey(-2);
		playerMove(dir);
	}
	else {
		Ui::Dialog("这个门有两把锁，所以...",32);
		pas();
	}
}

void World::store()
{
	Ui ui;
	ui.shop(player);
}

Map& World::getMap(int playerPosition)
{
	return mapList->getMap(playerPosition);
}


void World::displayMap()
{
	cls();
	/*if (player->isDebugMode()) {
		Ui::Dialog("玩家已开启调试模式");
	}*/
	switch (player->getPosition())
	{
	case 0:
		getMap(0).show(0, 20);
		break;
	case 1:
		getMap(1).show(0, 29);
		break;
	case 2:
		getMap(2).show(0, 38);
		break;
	case 3:
		getMap(3).show(0, 47);
		break;
	case 4:
		getMap(4).show(6, 20);
		break;
	case 5:
		getMap(5).show(6, 29);
		break;
	case 6:
		getMap(6).show(6, 38);
		break;
	case 7:
		getMap(7).show(6, 47);
		break;
	case 8:
		getMap(8).show(12, 20);
		break;
	case 9:
		getMap(9).show(12, 29);
		break;
	case 10:
		getMap(10).show(12, 38);
		break;
	case 11:
		getMap(11).show(12, 47);
		break;
	default:
		break;
	}
	Ui ui;
	char block[4] = {
		PlayerTryToMoveBlock(Dir::up).get(),
		PlayerTryToMoveBlock(Dir::left).get(),
		PlayerTryToMoveBlock(Dir::right).get(),
		PlayerTryToMoveBlock(Dir::down).get()
	};
	ui.showPlayerInfo(player, block);
	
}

void World::refresh(Dir playerMove)
{
	Block whatIs = PlayerTryToMoveBlock(playerMove);//判断玩家准备前进碰到的是什么？
	TouchType whatHellItis = opterater(whatIs);		//根据碰到的进行判断是什么类型
	Next(whatHellItis, playerMove);					//根据类型进行操作
}
