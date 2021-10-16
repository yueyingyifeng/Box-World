/*
最后编译成功：2021/9/27
测试版本
作者：yueyingyifeng
*/
/*
此次测试表明如下一些问题：
一：最终保存游戏数据的对象必须是唯一的，即所有系统都将整合为一个系统（对象）
二：在Box World游戏中数据仅有三种——玩家，地图，怪。
玩家是唯一的，好办
但地图与怪有很多，一张地图有多个怪，一个游戏有多个地图
层级关系必须表明
怪物由怪物表保存，地图由地图表保存
玩家是先进入地图后接触怪，因此怪与地图的关系就是一个典型的包含关系，先访问地图后读取怪
三：关于可视化操作，这就是个。。。在World.cpp中有一段简单的描述（battleUI方法里面)
其实只是一个表象，说白了就是将玩家直接输入1、2、3改成了选择1、2、3

*/
#include"formBlockEngineAction.h"
#include"World.h"
#include"Map_Resuorce.h"
#include"storyScript.h"


World* box = new World;//世界桥——玩家与游戏的(数据)交互
Player* player = new Player;

void first_test() {
	Ui::Dialog("这是一个控制台游戏，所以在部分电脑上显示会有所不同");
	Ui::Dialog("");

	story::PAU();
	Ui::Dialog("所以为了确保最好的视觉效果（尽管还是个控制台）");
	Ui::Dialog("");

	Ui::Dialog("建议:");
	Ui::Dialog("");

	Ui::Dialog("对左上角的控制台图标（窗口的最左边）右键");
	Ui::Dialog("");

	Ui::Dialog("点击属性");
	Ui::Dialog("");

	Ui::Dialog("在菜单栏选择“字体”");
	Ui::Dialog("");

	Ui::Dialog("字体类型必须是“点阵字体”,我建议大小是 8X16 (当你能看见一个可爱的小笑脸 \"  ",0,0);
	putchar(1);
	Ui::Dialog("  \"说明一切正常(如果是个正方形，说明显示有问题,你需要再看下上面的解决方法)");
	Ui::Dialog("");

	Ui::Dialog("同时我也建议不要开最大化，因为最小单位是一个字符，这样最大化会让原本很小的字看起来更小");
	Ui::Dialog("");

	story::PAU();
	Ui::Dialog("");

	Ui::Dialog("好了吗？那么下面就祝你游戏愉快，争取过关,现在按s键继续",0,0);
	char key;
	while (1) {
		key = _getch();
		if (key == 's') {
			break;
		}
	}



}


bool Menu() {
	story::CLS();
	story::beforeGame();
	story::foreword();
	Ui::Dialog("## 单击1进入游戏\t\t\t	##	--或任意键");
	Ui::Dialog("##						##");
	Ui::Dialog("## 单击q退出游戏\t\t\t	##");
	if (_getch() == 'q') {
		return false;
	}
	return true;
}

void difficultyUi() {
	Ui::Dialog("##						##");
	Ui::Dialog("## 选择一个角色\t\t\t		##");
	Ui::Dialog("##						##");
	Ui::Dialog("## 按1或a选择人类-高难度\t\t\t##");
	Ui::Dialog("##						##");
	Ui::Dialog("## 按2或d选择法师-低难度\t\t\t##");
	Ui::Dialog("##						##");
	Ui::Dialog("##	具体差异体现在攻击力与血量上		##");
}

void loadResource(Player* player, World* box) {
	const int numberOfMap{ 12 };
	Map* map = new Map[numberOfMap]{ 
		*map0(), *map1(), *map2(), *map3(),
		*map4(), *map5(), *map6(), *map7(),
		*map8(), *map9(), *map10(), *map11()
	};
	MapList mapList(map, numberOfMap);
	
	box->addMapList(&mapList);
	box->addPlayer(player);
	while (1) {
		difficultyUi();
		char c = _getch();
		if (c == '1' || c == 'a') {
			player->setPlayerPart(Part::Humen);
			player->setPlayerStyle(2);
			break;
		}
		else if (c == '2' || c == 'd') {
			player->setPlayerPart(Part::Magic);
			player->setPlayerStyle(1);
			break;
		}
	}
	
	player->addLevel(0);
	player->setPlayerHpMax();
	player->setPosition(5);
	player->setPlayerSceneAndPosition(box->getMap(5), new Coordinate(2, 3));
	
}

void Game() {
	int playerHp{};
	int bossHp{};
	
		do {
			playerHp = player->getHp();
			bossHp = box->getMap(0).getMonList()->getMonster(Coordinate(4, 3))->getHp();

			Ui::Dialog(player->getPosition());
			box->displayMap();
			box->refresh(player->input());
		} while (playerHp > 0 && bossHp > 0);

		story::CLS();
		player->countPlayerScore();
		story::PAU();
	
	

}


int main() {
	system("mode con: cols=100 lines=25");
	SetConsoleTitle("Box World Made by yueyingyifeng 祝玩的愉快. -=移动应用开发二班=-");
	first_test();
	char k;
	if (Menu()) {
		do{
			loadResource(player, box);
			Game();
			std::cout << "按r重新开始,任意键退出";
			k = _getch();
			player = new Player();
		} while (k =='r');
	}
	
	
	std::cout << "all good" << std::endl;
	return 0;
}