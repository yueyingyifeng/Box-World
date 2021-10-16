#include "Ui.h"

int Ui::Random(int min /*= 0*/, int max /*= 1*/)
{
	srand((unsigned int)time(NULL));
	return (rand() % (max - min + 1)) + min;
}

void Ui::battleAnimation(Ui* ui,Part part, Type type)
{
	Block playerStyle = ui->look(Coordinate(1, 1));
	Block monsterStyle = ui->look(Coordinate(18,1));
	Ui::Dialog(playerStyle.get());
	//画笔
	Pencil p(*ui);


	//------------------------------------------//
	Coordinate p1(2, 1);
	Coordinate p2(3, 1);
	Coordinate p3(4, 1);


	switch (type)
	{
	case Type::attck1:
		p.Pixel(Coordinate(2, 1), '-');
		p.Pixel(Coordinate(3, 1), '-');
		for (int n{}; n < 13; n++) {
			cls();
			ui->show(2,33);
			ui->set(p3);
			ui->set(Coordinate(++p3.x,p3.y),((part == Part::Humen) ? '>' : '*'));
			ui->set(p2);
			ui->set(Coordinate(++p2.x, p2.y), '-');
			ui->set(p1);
			ui->set(Coordinate(++p1.x, p1.y), '-');
			Sleep(20);
		}
		ui->set(p3);
		ui->set(p2);
		ui->set(p1);
		for (int n{}; n < 13; n++) {
			cls();
			ui->show(2, 33);
			ui->set(p2);
			ui->set(Coordinate(--p2.x, p2.y), '-');
			ui->set(p1);
			ui->set(Coordinate(--p1.x, p1.y), '-');
			Sleep(20);
		}
		ui->set(p3);
		ui->set(p2);
		ui->set(p1);
		break;
	case Type::attck2:
		for (int n{}; n < 14; n++) {
			cls();
			ui->show(2, 33);
			ui->set(p2);
			ui->set(Coordinate(++p2.x, p2.y), '-');
			ui->set(p1);
			ui->set(Coordinate(++p1.x, p1.y), '-');
			Sleep(20);
		}
		ui->set(p3);
		ui->set(p2);
		ui->set(p1);
		for (int n{}; n < 13; n++) {
			cls();
			ui->show(2, 33);
			ui->set(p2);
			ui->set(Coordinate(--p2.x, p2.y), '-');
			ui->set(p1);
			ui->set(Coordinate(--p1.x, p1.y), '-');
			Sleep(20);
		}
		ui->set(p3);
		ui->set(p2);
		ui->set(p1);
		break;
	case Type::attck3:
		break;
	default:
		break;
	}
}

std::string Ui::whatIs(char c)
{
	switch (c)
	{
	case ' ':
		return std::string("空气");
	case '#':
		return std::string("墙壁");
	case '!':
		return std::string("钥匙");
	case '%':
		return std::string("门锁");
	case '+':
		return std::string("大门");
	case 'c':
		return std::string("金币");
	case '$':
		return std::string("商店");
	case '@':
		return std::string("大怪");
	case '&':
		return std::string("小怪");
	case 'B':
		return std::string("Boss!");
	default:
		return std::string();
		break;
	}
}

void Ui::showPlayerInfo(Player* player, char* block)
{
	Dialog("");
	Dialog("========================", 28, 0); Dialog("=============", 5);
	Dialog("生命值: ", 26, 0); Dialog(player->getHp(), 0, 0); Dialog("攻击力: ", 11, 0); Dialog(player->getAk1(), 0, 0); Dialog("", 4, 0); putchar(block[0]); Dialog(":", 0, 0); Dialog(whatIs(block[0]));
	Dialog("------装备等级：", 28, 0);	Dialog(player->getLevel(), 0, 0);Dialog(" ------",0,0);																Dialog("", 4, 0); putchar(block[1]); Dialog(":", 0, 0); Dialog(whatIs(block[1]),0,0); Dialog("", 2, 0); putchar(block[2]); Dialog(":",0,0); Dialog(whatIs(block[2]));
	Dialog("金币数: ", 26, 0); Dialog(player->getCoin(), 0, 0); Dialog("钥匙数: ", 11, 0); Dialog(player->getKeys(), 0, 0); Dialog("", 4, 0); putchar(block[3]); Dialog(":",0,0); Dialog(whatIs(block[3]));
	Dialog("========================", 28, 0); Dialog("=============", 5);
	if (player->isDebugMode()) {
		player->showPlayerInfo();
	}
	player->changeScreenByHp();
}

int Ui::PlayerBattle(Player* player, Monster* mon)
{
	Ui* ui = new Ui(20, 3);
	//-----------------显示玩家与怪-----------------//
	Pencil p(*ui);
	//p.Box(Coordinate(0, 0), Coordinate(19, 2), '#');
	p.Pixel(Coordinate(1, 1), player->getStyle());
	p.Pixel(Coordinate(18, 1), mon->getStyle());


	//----------------显示选项与选择----------------//

	Ui::Dialog("请选择攻击方式:", 30);
	int chose{};
	Ui option(30, 1);

	p = Pencil(option);
	p.Pixel(Coordinate(4, 0), '^');
	while (player->getHp() > 0 && mon->getHp() > 0) {//要么玩家死,要么怪死，或者。。。逃跑
		player->changeScreenByHp();
		if (mon->getHp() <= 0) {
			return 0;
		}
		cls();
		ui->show(2, 33);
		if (player->getPart() == Part::Humen) {
			Ui::Dialog("步枪射击 手枪射击 小刀 逃跑", 32, 0); Ui::Dialog("--tips e或w确定");
		}
		else if (player->getPart() == Part::Magic) {
			Ui::Dialog("高能魔法 投掷魔法 棍击 逃跑", 32, 0); Ui::Dialog("--tips e或w确定");
		}
		option.show(0, 32);
		//决定对怪的伤害（攻击1以下时启用)
		int ak{};
		switch (ui->input())
		{
		case key::w:
		case key::e:
			switch (chose)
			{
			case 0:
				battleAnimation(ui,player->getPart(),Type::attck1);
				mon->decreaseHp(player->getAk1());
				player->decreaseHp(mon->getAk1());
				Ui::Dialog("你遭受了", 30, 0); Ui::Dialog(mon->getAk1(), 0, 0); Ui::Dialog("伤害");
				Ui::Dialog("你的生命值：", 30, 0); Ui::Dialog(player->getHp());
				pas();
				break;
			case 1://攻击1以下的伤害都有概率，遭到怪物全力攻击的概率是50%，否则很弱
				battleAnimation(ui, player->getPart(), Type::attck2);
				mon->decreaseHp(player->getAk2());
				ak = Random(0, 1) == 1 ? mon->getAk1() : mon->getAk2();//概率,2选1，50的概率
				player->decreaseHp(ak);
				Ui::Dialog("你遭受了", 30, 0); Ui::Dialog(ak, 0, 0); Ui::Dialog("伤害");
				Ui::Dialog("你的生命值：", 30, 0); Ui::Dialog(player->getHp());
				pas();
				break;
			case 2://攻击1以下的伤害都有概率，遭到怪物全力攻击的概率是25%，否则更弱
				battleAnimation(ui, player->getPart(), Type::attck3);
				mon->decreaseHp(player->getAk3());
				ak = Random(0, 2) != 1 ? mon->getAk1() : mon->getAk3();//概率,4选1，25的概率 ...
				player->decreaseHp(ak);
				Ui::Dialog("你遭受了",30,0); Ui::Dialog(ak,0,0); Ui::Dialog("伤害");
				Ui::Dialog("你的生命值：", 30, 0); Ui::Dialog(player->getHp());
				pas();
				break;
			case 3:
				if (Random(0, 2)) {
					Ui::Dialog("你因为逃跑而受到1点伤害");
					player->decreaseHp(1);
					pas();
				}
				return 0;
			}
			break;

		case key::a:
			chose > 0 ? chose-- : chose = 3;
			break;
		case key::d:
			chose < 3 ? chose++ : chose = 0;
			break;
		default:
			break;
		}
		switch (chose)
		{
		case 0:
			option.replace('^');
			p.Pixel(Coordinate(4, 0), '^');
			break;
		case 1:
			option.replace('^');
			p.Pixel(Coordinate(13, 0), '^');
			break;
		case 2:
			option.replace('^');
			p.Pixel(Coordinate(20, 0), '^');
			break;
		case 3:
			option.replace('^');
			p.Pixel(Coordinate(24, 0), '^');
			break;
		default:
			break;
		}
		player->changeScreenByHp();
	}

	if (mon->getHp() <= 0) {
		if (mon->getStyle() == '&') {
			player->addScore(6);
		}
		else if (mon->getStyle() == '@') {
			player->addScore(10);
		}
		else if (mon->getStyle() == 'B') {
			player->addScore(50);	
		}
	}
}

int Ui::shop(Player* player)
{	
	//是否购买
	bool isBuy = false;
	//钥匙所需要的金币
	const int requireCoinForKey{ 3 };
	//药水所需要的金币
	const int requireCoinForPotion{ 2 };
	//大药水所需要的金币
	const int requireCoinForBig_Potion{ 5 };
	//升级你的装备所需要的金币
	const int requireCoinForLevel{ 10 };

	//药水增加多少血量
	const int addHpOfPotion{ 2 };
	//大药水增加多少血量
	const int addHpOfBig_Potion{ 5 };

	while (!isBuy) {
		cls();
		Ui::Dialog("## 一个看着不友好的人对你说	##");
		Ui::Dialog("## 欢迎，你要点啥？直接说把	##	--tips:按q离开,按123456来选择 ");
		Ui::Dialog("## 1.钥匙 ", 0, 0); Ui::Dialog(requireCoinForKey, 0, 0); Ui::Dialog("金币1把		##");
		Ui::Dialog("## 2.药水 恢复", 0, 0); Ui::Dialog(addHpOfPotion, 0, 0); Ui::Dialog("血量 要 ", 0, 0); Ui::Dialog(requireCoinForPotion, 0, 0); Ui::Dialog("金币	##");
		Ui::Dialog("## 3.药水 恢复", 0, 0); Ui::Dialog(addHpOfBig_Potion, 0, 0); Ui::Dialog("血量 要 ", 0, 0); Ui::Dialog(requireCoinForBig_Potion, 0, 0); Ui::Dialog("金币	##");
		Ui::Dialog("## 4.升级你的装备-", 0, 0); Ui::Dialog(requireCoinForLevel, 0, 0); Ui::Dialog("金币	##");
		Ui::Dialog("## 你还剩 ", 0, 0); Ui::Dialog(player->getCoin(), 0, 0); 
		Ui::Dialog(" 金币 你还剩	",0,0); Ui::Dialog(player->getHp(), 0, 0); Ui::Dialog("血量	##");

		char key = _getch();
		switch (key)
		{
		case '1':
			if (player->getCoin() >= requireCoinForKey) {
				player->addCoin(-requireCoinForKey);
				player->addKey();
				Ui::Dialog("拿去开门把");
				pas();
				isBuy = true;
			}
			else {
				Ui::Dialog("我不是做慈善的！至少拿点", 0, false); Ui::Dialog(requireCoinForKey, 0, 0); Ui::Dialog("金币");
				pas();
			}
			break;

		case '2':
			if (player->getCoin() >= requireCoinForPotion ) {
				player->addCoin(-requireCoinForPotion);
				for (int n{}; n < addHpOfPotion; n++) {
					player->addHp(1);
				}
				//如果玩家血满了还买
				if (player->getHp() >= player->getMaxHp()) {
					Ui::Dialog("多喝点不急哈");
				}
				else {
					Ui::Dialog("你恢复了", 0, 0); Ui::Dialog(addHpOfPotion, 0, 0); Ui::Dialog("血量");
				}
				pas();
				isBuy = true;
			}
			else {
				Ui::Dialog("你想白嫖吗？至少拿点", 0, false); Ui::Dialog(requireCoinForPotion, 0, 0); Ui::Dialog("金币");
				pas();
			}
			break;

		case '3':
			if (player->getCoin() >= requireCoinForBig_Potion) {
				player->addCoin(-requireCoinForBig_Potion);
				for (int n{}; n < addHpOfBig_Potion; n++) {
					player->addHp(1);
				}
				//如果玩家血满了还买
				if (player->getHp() >= player->getMaxHp()) {
					Ui::Dialog("多喝益善啊");
				}
				else {
					Ui::Dialog("你恢复了", 0, 0); Ui::Dialog(addHpOfBig_Potion, 0, 0); Ui::Dialog("血量");
				}
				pas();
				isBuy = true;
			}
			else {
				Ui::Dialog("你想说下次一定?至少拿点", 0, false); Ui::Dialog(requireCoinForBig_Potion, 0, 0); Ui::Dialog("金币");
				pas();
			}
			break;

		case '4':
			if (player->getLevel() >= 3) {
				Ui::Dialog("我要有更好的装备我早灭了那Boss了,还用了着你跑过来？");
				pas();
				break;
			}
			if (player->getCoin() >= requireCoinForLevel) {
				player->addCoin(-requireCoinForLevel);
				player->addLevel();
				Ui::Dialog("赶紧去狠狠地打爆他们");
				if (player->getHp() <= player->getMaxHp()) {
					player->decreaseHp(-2);
				}
				pas();
				isBuy = true;
			}
			else {
				Ui::Dialog("！至少拿点", 0, false); Ui::Dialog(requireCoinForLevel, 0, 0); Ui::Dialog("金币");
				pas();
			}
			break;
		case 'q':
			isBuy = true;
			break;
		case '5':
			Ui::Dialog("啥？");
			pas();
			isBuy = true;
			break;
		case '6':
			Ui:: Dialog("我没有你要求的东西");
			pas();
			isBuy = true;
			break;
		case '7':
			Ui::Dialog("你与其按这么远的键，不如花点心思怎么过关");
			pas();
			isBuy = true;
			break;
		case '0':
			Ui::Dialog("???你要么是你家猫踩键盘上了要么就是——你太无聊了");
			pas();
			isBuy = true;
			break;
		default:
			isBuy = true;
			break;
		}
		player->changeScreenByHp();
	}
	return 0;
}

key Ui::input()
{
	char Key = _getch();
	switch (Key)
	{
	case 'w':
	case 'W':
		return key::w;
	case 'a':
	case 'A':
		return key::a;
	case 's':
	case 'S':
		return key::s;
	case 'd':
	case 'D':
		return key::d;
	case 'e':
	case 'E':
		return key::e;
		break;
	default:
		Ui::Dialog("请输入wasd选择，e来确认");
		break;
	}
}

void Ui::Dialog(std::string msg, int margin_left /*= 0*/, bool line /*= true*/)
{
	for (int n{}; n < margin_left; n++) {
		std::cout << ' ';
	}
	if (line) {
		std::cout << msg << std::endl;
	}
	else {
		std::cout << msg;
	}

}
void Ui::Dialog(int msg, int margin_left /*= 0*/, bool line /*= true*/)
{
	for (int n{}; n < margin_left; n++) {
		std::cout << ' ';
	}
	if (line) {
		std::cout << msg << std::endl;
	}
	else {
		std::cout << msg;
	}
}