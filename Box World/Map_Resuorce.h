#pragma once
#include"MapList.h"
//小怪的数据
const int Mon_hp{ 10 }, Mon_ak1{ 2 }, Mon_ak2{1}, Mon_ak3{0};
//大怪的数据
const int BigMon_hp{16}, BigMon_ak1{7}, BigMon_ak2{5}, BigMon_ak3{3};
//boss的数据
const int Boss_hp{ 20 }, Boss_ak1{6}, Boss_ak2{5}, Boss_ak3{2};

Map* map0() {//传送点 7,3
	const int countOfMon{ 1 };//地图中怪的数量
	Map* map = new Map(9, 7);//这个不用管，是地图的大小，不要动
	//--------此处敲地图的非怪物-------//
	Pencil p(*map);//画笔
	p.Box(Coordinate(0, 0), Coordinate(8, 6), cWall);//画地图边界
	p.Pixel(Coordinate(1, 2), cWall);
	p.Pixel(Coordinate(1, 3), cWall);
	p.Pixel(Coordinate(1, 4), cWall);
	p.Pixel(Coordinate(2, 2), cWall);
	p.Pixel(Coordinate(2, 4), cWall);
	p.Pixel(Coordinate(4, 1), cWall);
	p.Pixel(Coordinate(4, 5), cWall);
	p.Pixel(Coordinate(3, 1), cWall);
	p.Pixel(Coordinate(3, 5), cWall);
	p.Pixel(Coordinate(6, 2), cWall);
	p.Pixel(Coordinate(7, 2), cWall);
	p.Pixel(Coordinate(6, 4), cWall);
	p.Pixel(Coordinate(7, 4), cWall);
	p.Pixel(Coordinate(6, 3), cDoor);
	p.Pixel(Coordinate(8, 3),'+');//传送点
	



	//-----------此处生成怪物-----------//
	Monster* mon = new Monster[countOfMon]{//countOfMon是代表怪物的数量,见函数的第一行代码
		Monster(new Coordinate(4,3),cBoss ,*map, Boss_hp, Boss_ak1,Boss_ak2,Boss_ak3),//此处生成一个怪物，第一个参数是坐标，第二个参数是样子（样子是固定的）															//此处还可以再生成，不过需要你自己写了
	};
	MonsterList* monList = new MonsterList(mon, countOfMon);//将生成的多个怪物放进一个表里面

	map->addMonList(monList);//把上述的表放进地图里面准备使用
	return map;
}

Map* map1() {
	const int countOfMon{ 5 };
	Map* map = new Map(9, 7);

	Pencil p(*map);
	p.Line(Coordinate(1, 2), Coordinate(7, 2), cWall);
	p.Line(Coordinate(1, 4), Coordinate(7, 4), cWall);
	p.Box(Coordinate(0, 0), Coordinate(8, 6), cWall);
	p.Pixel(Coordinate(2, 1), cCoin);
	p.Pixel(Coordinate(6, 1), cCoin);
	p.Pixel(Coordinate(1, 5), cCoin);
	p.Pixel(Coordinate(7, 5), cCoin);
	p.Pixel(Coordinate(4, 1), cKey);
	p.Pixel(Coordinate(4, 5), cKey);
	p.Pixel(Coordinate(4, 3), cDoor);

	p.Pixel(Coordinate(4, 6), cPortal);
	p.Pixel(Coordinate(0, 3), cPortal);
	//-----------此处生成怪物-----------//
	Monster* mon = new Monster[countOfMon]{
		Monster(new Coordinate(4,2),cMon_b ,*map, BigMon_hp, BigMon_ak1,BigMon_ak2,BigMon_ak3),
		Monster(new Coordinate(4,4),cMon_b ,*map, BigMon_hp, BigMon_ak1,BigMon_ak2,BigMon_ak3),
	};
	MonsterList* monList = new MonsterList(mon, countOfMon);

	map->addMonList(monList);
	return map;
}

Map* map2() {
	const int countOfMon{ 5 };
	Map* map = new Map(9, 7);

	Pencil p(*map);
	p.Box(Coordinate(0, 0), Coordinate(8, 6), cWall);
	p.Box(Coordinate(1, 1), Coordinate(3, 3), cWall);
	p.Box(Coordinate(3, 5), Coordinate(7, 5), cWall);
	p.Box(Coordinate(5, 2), Coordinate(7, 2), cWall);
	p.Pixel(Coordinate(2, 2), cWall);
	p.Pixel(Coordinate(7, 3), cKey);
	p.Pixel(Coordinate(5, 4), cWall);
	p.Pixel(Coordinate(2, 4), cCoin);
	p.Pixel(Coordinate(2, 5), cCoin);
	p.Pixel(Coordinate(1, 4), cCoin);//金币
	p.Pixel(Coordinate(1, 5), cKey);
	p.Pixel(Coordinate(8, 1), '+');//传送点

	Monster* mon = new Monster[countOfMon]{
		Monster(new Coordinate(3,4),cMon_b ,*map, BigMon_hp, BigMon_ak1,BigMon_ak2,BigMon_ak3),
		Monster(new Coordinate(5,3),cMon_s ,*map, Mon_hp, Mon_ak1, Mon_ak2, Mon_ak3),
	};
	MonsterList* monList = new MonsterList(mon, countOfMon);

	map->addMonList(monList);
	return map;
}

Map* map3() {
	const int countOfMon{ 5 };
	Map* map = new Map(9, 7);

	Pencil p(*map);
	p.Box(Coordinate(0, 0), Coordinate(8, 6), cWall);
	p.Box(Coordinate(5, 4), Coordinate(7, 5), cWall);
	p.Line(Coordinate(3, 2), Coordinate(6, 2), cWall);
	p.Line(Coordinate(3, 1), Coordinate(4, 1), cWall);
	p.Line(Coordinate(1, 2), Coordinate(1, 4), cWall);
	p.Line(Coordinate(3, 4), Coordinate(3, 5), cWall);
	p.Pixel(Coordinate(1, 5), cCoin);//金币
	p.Pixel(Coordinate(2, 3), cCoin);//金币
	p.Pixel(Coordinate(3, 3), cCoin);//金币
	p.Pixel(Coordinate(5, 1), cCoin);//金币
	p.Pixel(Coordinate(6, 1), cCoin);//金币
	p.Pixel(Coordinate(0, 1), '+');//传送点
	p.Pixel(Coordinate(4, 6), '+');//传送点

	Monster* mon = new Monster[countOfMon]{
		Monster(new Coordinate(7,2),cMon_b ,*map, BigMon_hp, BigMon_ak1,BigMon_ak2,BigMon_ak3),
		Monster(new Coordinate(2,4),cMon_s ,*map, Mon_hp, Mon_ak1, Mon_ak2, Mon_ak3),
	};
	MonsterList* monList = new MonsterList(mon, countOfMon);

	map->addMonList(monList);
	return map;
}

Map* map4() {
	const int countOfMon{ 5 };
	Map* map = new Map(9, 7);

	Pencil p(*map);
	p.Box(Coordinate(0, 0), Coordinate(8, 6), cWall);
	p.Box(Coordinate(5, 2), Coordinate(6, 4), cWall);
	p.Line(Coordinate(1, 5), Coordinate(5, 5), cWall);
	p.Line(Coordinate(1, 3), Coordinate(3, 3), cWall);
	p.Pixel(Coordinate(4, 5));
	p.Pixel(Coordinate(3, 3), cWall);//墙
	p.Pixel(Coordinate(2, 2), cStore);//商店
	p.Pixel(Coordinate(1, 2), cKey);//钥匙
	p.Pixel(Coordinate(5, 1), cCoin);//金币
	p.Pixel(Coordinate(6, 1), cCoin);//金币
	p.Pixel(Coordinate(7, 4), cCoin);//金币
	p.Pixel(Coordinate(6, 5), cCoin);//金币
	p.Pixel(Coordinate(1, 4), cCoin);//金币
	p.Pixel(Coordinate(4, 4), cCoin);//金币

	p.Pixel(Coordinate(8, 3), cPortal);
	p.Pixel(Coordinate(4, 6), '+');//传送点

	Monster* mon = new Monster[countOfMon]{
		Monster(new Coordinate(3,1),cMon_b ,*map, BigMon_hp, BigMon_ak1,BigMon_ak2,BigMon_ak3),
		Monster(new Coordinate(7,3),cMon_s ,*map, Mon_hp, Mon_ak1, Mon_ak2, Mon_ak3),
	};
	MonsterList* monList = new MonsterList(mon, countOfMon);

	map->addMonList(monList);
	return map;
}

Map* map5() {//完成
	const int countOfMon{ 1 };
	Map* map = new Map(9, 7);

	Pencil p(*map);
	p.Box(Coordinate(0, 0), Coordinate(8, 6), cWall);

	p.Pixel(Coordinate(2, 1), cWall);
	p.Pixel(Coordinate(2, 5), cWall);

	p.Line(Coordinate(6, 2), Coordinate(7, 2), cWall);
	p.Line(Coordinate(6, 4), Coordinate(7, 4), cWall);


	p.Pixel(Coordinate(5, 4), cStore);//debug用

	p.Pixel(Coordinate(7, 3), cKey);

	p.Pixel(Coordinate(1, 1), cCoin);
	p.Pixel(Coordinate(1, 5), cCoin);
	p.Pixel(Coordinate(7, 1), cCoin);

	p.Pixel(Coordinate(8, 3), cPortal);
	p.Pixel(Coordinate(4, 0), cPortal);
	Monster* mon = new Monster[countOfMon]{
		Monster(new Coordinate(6,3),cMon_s ,*map, Mon_hp, Mon_ak1, Mon_ak2, Mon_ak3),
	};
	MonsterList* monList = new MonsterList(mon, countOfMon);

	map->addMonList(monList);
	return map;
}

Map* map6() {//完成
	const int countOfMon{ 3 };
	Map* map = new Map(9, 7);

	Pencil p(*map);
	p.Box(Coordinate(0, 0), Coordinate(8, 6), cWall);

	p.Line(Coordinate(1, 2), Coordinate(4, 2), cWall);
	p.Box(Coordinate(1, 4), Coordinate(3, 5), cWall);
	p.Line(Coordinate(4, 1), Coordinate(4, 2), cWall);
	p.Line(Coordinate(4, 4), Coordinate(6, 4), cWall);
	p.Line(Coordinate(6, 2), Coordinate(7, 2), cWall);
	p.Pixel(Coordinate(5, 1), cCoin);//金币

	p.Line(Coordinate(1, 1), Coordinate(3, 1), cCoin);
	p.Line(Coordinate(3, 3), Coordinate(4, 3), cCoin);
	p.Pixel(Coordinate(6, 1), cKey);
	p.Pixel(Coordinate(4, 5), cKey);
	p.Pixel(Coordinate(5, 5), cCoin);
	p.Pixel(Coordinate(2, 2), cDoor);

	p.Pixel(Coordinate(0, 3), cPortal);
	p.Pixel(Coordinate(8, 1), cPortal);

	Monster* mon = new Monster[countOfMon]{
		Monster(new Coordinate(2,1),cMon_s ,*map,Mon_hp, Mon_ak1, Mon_ak2, Mon_ak3),
		Monster(new Coordinate(5,2),cMon_s ,*map,Mon_hp, Mon_ak1, Mon_ak2, Mon_ak3),
		Monster(new Coordinate(7,4),cMon_s ,*map,Mon_hp, Mon_ak1, Mon_ak2, Mon_ak3),
	};
	MonsterList* monList = new MonsterList(mon, countOfMon);

	map->addMonList(monList);
	return map;
}

Map* map7() {//完成
	//const int countOfMon{ 0 };
	Map* map = new Map(9, 7);

	Pencil p(*map);
	p.Box(Coordinate(0, 0), Coordinate(8, 6), cWall);

	p.Line(Coordinate(1, 2), Coordinate(1, 4), cWall);
	p.Line(Coordinate(1, 4), Coordinate(7, 4), cWall);
	p.Line(Coordinate(3, 1), Coordinate(3, 2), cWall);
	p.Line(Coordinate(3, 2), Coordinate(7, 2), cWall);
	p.Box(Coordinate(6, 4), Coordinate(7, 5), cWall);

	p.Pixel(Coordinate(1, 5), cKey);
	p.Line(Coordinate(3, 3), Coordinate(4, 3), cCoin);
	p.Line(Coordinate(3, 5), Coordinate(4, 5), cCoin);
	p.Pixel(Coordinate(7, 3), cStore);

	p.Pixel(Coordinate(6, 2), cDoor);
	p.Pixel(Coordinate(5, 4), cDoor);

	p.Pixel(Coordinate(0, 1), cPortal);
	p.Pixel(Coordinate(2, 6), cPortal);
	p.Pixel(Coordinate(4, 0), cPortal);

	//Monster* mon = new Monster[countOfMon]{
	//};
	//MonsterList* monList = new MonsterList(mon, countOfMon);

	//map->addMonList(monList);
	return map;
}

Map* map8() {//完成
	const int countOfMon{ 3 };
	Map* map = new Map(9, 7);

	Pencil p(*map);
	p.Box(Coordinate(0, 0), Coordinate(8, 6), cWall);

	p.Line(Coordinate(1, 1), Coordinate(1, 5), cWall);
	p.Pixel(Coordinate(2, 5), cWall);
	p.Line(Coordinate(3, 2), Coordinate(3, 5), cWall);
	p.Line(Coordinate(4, 2), Coordinate(5, 2), cWall);
	p.Pixel(Coordinate(4, 5), cWall);
	p.Line(Coordinate(5, 4), Coordinate(5, 5), cWall);
	p.Line(Coordinate(7, 1), Coordinate(7, 5), cWall);
	p.Pixel(Coordinate(7, 3));

	p.Pixel(Coordinate(1, 4), cKey);
	p.Pixel(Coordinate(2, 2), cCoin);
	p.Pixel(Coordinate(4, 3), cCoin);
	p.Line(Coordinate(5, 1), Coordinate(6, 1), cCoin);
	p.Pixel(Coordinate(6, 5), cCoin);

	p.Pixel(Coordinate(8, 3), cPortal);
	p.Pixel(Coordinate(4, 0), cPortal);

	p.Pixel(Coordinate(4, 0), '+');//传送点

	Monster* mon = new Monster[countOfMon]{
		Monster(new Coordinate(3,1),cMon_s ,*map, Mon_hp, Mon_ak1, Mon_ak2, Mon_ak3),
		Monster(new Coordinate(5,3),cMon_b ,*map, BigMon_hp, BigMon_ak1, BigMon_ak2, BigMon_ak3),

	};
	MonsterList* monList = new MonsterList(mon, countOfMon);

	map->addMonList(monList);
	return map;
}

Map* map9() {//完成
	const int countOfMon{ 2 };
	Map* map = new Map(9, 7);

	Pencil p(*map);
	p.Box(Coordinate(0, 0), Coordinate(8, 6), cWall);

	p.Line(Coordinate(1, 1), Coordinate(3, 1), cWall);
	p.Line(Coordinate(3, 1), Coordinate(3, 5), cWall);

	p.Line(Coordinate(4, 4), Coordinate(4, 5), cWall);
	p.Box(Coordinate(5, 1), Coordinate(7, 2), cWall);
	p.Line(Coordinate(6, 3), Coordinate(6, 4), cWall);


	p.Line(Coordinate(1, 2), Coordinate(1, 4), cCoin);
	p.Pixel(Coordinate(2, 3), cCoin);
	p.Pixel(Coordinate(3, 3), cDoor);

	p.Pixel(Coordinate(5, 3), cCoin);
	p.Pixel(Coordinate(5, 5), cCoin);
	p.Pixel(Coordinate(0, 3), cPortal);
	p.Pixel(Coordinate(4, 0), cPortal);
	p.Pixel(Coordinate(8, 3), cPortal);

	Monster* mon = new Monster[countOfMon]{
		Monster(new Coordinate(1,3),cMon_s ,*map, Mon_hp, Mon_ak1, Mon_ak2, Mon_ak3),
		Monster(new Coordinate(2,4),cMon_s ,*map, Mon_hp, Mon_ak1, Mon_ak2, Mon_ak3)
	};
	MonsterList* monList = new MonsterList(mon, countOfMon);

	map->addMonList(monList);
	return map;
}

Map* map10() {//完成
	const int countOfMon{ 3 };
	Map* map = new Map(9, 7);

	Pencil p(*map);
	p.Box(Coordinate(0, 0), Coordinate(8, 6), cWall);

	p.Pixel(Coordinate(1, 2), cWall);
	p.Line(Coordinate(1, 4), Coordinate(1, 5), cWall);
	p.Line(Coordinate(3, 1), Coordinate(3, 4), cWall);

	p.Line(Coordinate(5, 2), Coordinate(7, 2), cWall);
	p.Line(Coordinate(5, 4), Coordinate(5, 5), cWall);
	p.Line(Coordinate(7, 4), Coordinate(7, 5), cWall);

	p.Pixel(Coordinate(1, 1), cKey);
	p.Line(Coordinate(2, 4), Coordinate(2, 5), cCoin);
	p.Line(Coordinate(5, 1), Coordinate(6, 1), cCoin);
	p.Pixel(Coordinate(7, 1), cKey);

	p.Pixel(Coordinate(6, 5), cCoin);

	p.Pixel(Coordinate(8, 3), cPortal);
	p.Pixel(Coordinate(0, 3), cPortal);

	Monster* mon = new Monster[countOfMon]{
		Monster(new Coordinate(4,2),cMon_b ,*map, BigMon_hp, BigMon_ak1,BigMon_ak2,BigMon_ak3),
		Monster(new Coordinate(6,4),cMon_s ,*map, Mon_hp, Mon_ak1, Mon_ak2, Mon_ak3),
		Monster(new Coordinate(2,2),cMon_s ,*map, Mon_hp, Mon_ak1, Mon_ak2, Mon_ak3),
	};
	MonsterList* monList = new MonsterList(mon, countOfMon);

	map->addMonList(monList);
	return map;
}

Map* map11() {
	const int countOfMon{ 2 };
	Map* map = new Map(9, 7);

	Pencil p(*map);
	p.Box(Coordinate(0, 0), Coordinate(8, 6), cWall);

	p.Line(Coordinate(1, 0), Coordinate(1, 5), cWall);
	p.Line(Coordinate(2, 0), Coordinate(2, 5), cWall);

	

	p.Box(Coordinate(4, 1), Coordinate(7, 2), cWall);
	p.Box(Coordinate(6, 3), Coordinate(7, 4), cCoin);
	p.Line(Coordinate(5, 1), Coordinate(7, 1), cWall);

	p.Box(Coordinate(4, 4), Coordinate(5, 5), cWall);

	p.Pixel(Coordinate(1, 3));
	p.Pixel(Coordinate(1, 5), cCoin);
	p.Line(Coordinate(1, 3), Coordinate(3, 3));

	p.Line(Coordinate(2, 1), Coordinate(3, 1));
	p.Pixel(Coordinate(2, 3), cDoor);
	p.Pixel(Coordinate(0, 3), cPortal);
	p.Pixel(Coordinate(2, 0), cPortal);

	Monster* mon = new Monster[countOfMon]{
		Monster(new Coordinate(4,3),cMon_s ,*map, Mon_hp, Mon_ak1, Mon_ak2, Mon_ak3),
		Monster(new Coordinate(2,5),cMon_s ,*map, Mon_hp, Mon_ak1, Mon_ak2, Mon_ak3),
	};
	MonsterList* monList = new MonsterList(mon, countOfMon);

	map->addMonList(monList);
	return map;
}