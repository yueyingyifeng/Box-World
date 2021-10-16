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
	//����
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
		return std::string("����");
	case '#':
		return std::string("ǽ��");
	case '!':
		return std::string("Կ��");
	case '%':
		return std::string("����");
	case '+':
		return std::string("����");
	case 'c':
		return std::string("���");
	case '$':
		return std::string("�̵�");
	case '@':
		return std::string("���");
	case '&':
		return std::string("С��");
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
	Dialog("����ֵ: ", 26, 0); Dialog(player->getHp(), 0, 0); Dialog("������: ", 11, 0); Dialog(player->getAk1(), 0, 0); Dialog("", 4, 0); putchar(block[0]); Dialog(":", 0, 0); Dialog(whatIs(block[0]));
	Dialog("------װ���ȼ���", 28, 0);	Dialog(player->getLevel(), 0, 0);Dialog(" ------",0,0);																Dialog("", 4, 0); putchar(block[1]); Dialog(":", 0, 0); Dialog(whatIs(block[1]),0,0); Dialog("", 2, 0); putchar(block[2]); Dialog(":",0,0); Dialog(whatIs(block[2]));
	Dialog("�����: ", 26, 0); Dialog(player->getCoin(), 0, 0); Dialog("Կ����: ", 11, 0); Dialog(player->getKeys(), 0, 0); Dialog("", 4, 0); putchar(block[3]); Dialog(":",0,0); Dialog(whatIs(block[3]));
	Dialog("========================", 28, 0); Dialog("=============", 5);
	if (player->isDebugMode()) {
		player->showPlayerInfo();
	}
	player->changeScreenByHp();
}

int Ui::PlayerBattle(Player* player, Monster* mon)
{
	Ui* ui = new Ui(20, 3);
	//-----------------��ʾ������-----------------//
	Pencil p(*ui);
	//p.Box(Coordinate(0, 0), Coordinate(19, 2), '#');
	p.Pixel(Coordinate(1, 1), player->getStyle());
	p.Pixel(Coordinate(18, 1), mon->getStyle());


	//----------------��ʾѡ����ѡ��----------------//

	Ui::Dialog("��ѡ�񹥻���ʽ:", 30);
	int chose{};
	Ui option(30, 1);

	p = Pencil(option);
	p.Pixel(Coordinate(4, 0), '^');
	while (player->getHp() > 0 && mon->getHp() > 0) {//Ҫô�����,Ҫô���������ߡ���������
		player->changeScreenByHp();
		if (mon->getHp() <= 0) {
			return 0;
		}
		cls();
		ui->show(2, 33);
		if (player->getPart() == Part::Humen) {
			Ui::Dialog("��ǹ��� ��ǹ��� С�� ����", 32, 0); Ui::Dialog("--tips e��wȷ��");
		}
		else if (player->getPart() == Part::Magic) {
			Ui::Dialog("����ħ�� Ͷ��ħ�� ���� ����", 32, 0); Ui::Dialog("--tips e��wȷ��");
		}
		option.show(0, 32);
		//�����Թֵ��˺�������1����ʱ����)
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
				Ui::Dialog("��������", 30, 0); Ui::Dialog(mon->getAk1(), 0, 0); Ui::Dialog("�˺�");
				Ui::Dialog("�������ֵ��", 30, 0); Ui::Dialog(player->getHp());
				pas();
				break;
			case 1://����1���µ��˺����и��ʣ��⵽����ȫ�������ĸ�����50%���������
				battleAnimation(ui, player->getPart(), Type::attck2);
				mon->decreaseHp(player->getAk2());
				ak = Random(0, 1) == 1 ? mon->getAk1() : mon->getAk2();//����,2ѡ1��50�ĸ���
				player->decreaseHp(ak);
				Ui::Dialog("��������", 30, 0); Ui::Dialog(ak, 0, 0); Ui::Dialog("�˺�");
				Ui::Dialog("�������ֵ��", 30, 0); Ui::Dialog(player->getHp());
				pas();
				break;
			case 2://����1���µ��˺����и��ʣ��⵽����ȫ�������ĸ�����25%���������
				battleAnimation(ui, player->getPart(), Type::attck3);
				mon->decreaseHp(player->getAk3());
				ak = Random(0, 2) != 1 ? mon->getAk1() : mon->getAk3();//����,4ѡ1��25�ĸ��� ...
				player->decreaseHp(ak);
				Ui::Dialog("��������",30,0); Ui::Dialog(ak,0,0); Ui::Dialog("�˺�");
				Ui::Dialog("�������ֵ��", 30, 0); Ui::Dialog(player->getHp());
				pas();
				break;
			case 3:
				if (Random(0, 2)) {
					Ui::Dialog("����Ϊ���ܶ��ܵ�1���˺�");
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
	//�Ƿ���
	bool isBuy = false;
	//Կ������Ҫ�Ľ��
	const int requireCoinForKey{ 3 };
	//ҩˮ����Ҫ�Ľ��
	const int requireCoinForPotion{ 2 };
	//��ҩˮ����Ҫ�Ľ��
	const int requireCoinForBig_Potion{ 5 };
	//�������װ������Ҫ�Ľ��
	const int requireCoinForLevel{ 10 };

	//ҩˮ���Ӷ���Ѫ��
	const int addHpOfPotion{ 2 };
	//��ҩˮ���Ӷ���Ѫ��
	const int addHpOfBig_Potion{ 5 };

	while (!isBuy) {
		cls();
		Ui::Dialog("## һ�����Ų��Ѻõ��˶���˵	##");
		Ui::Dialog("## ��ӭ����Ҫ��ɶ��ֱ��˵��	##	--tips:��q�뿪,��123456��ѡ�� ");
		Ui::Dialog("## 1.Կ�� ", 0, 0); Ui::Dialog(requireCoinForKey, 0, 0); Ui::Dialog("���1��		##");
		Ui::Dialog("## 2.ҩˮ �ָ�", 0, 0); Ui::Dialog(addHpOfPotion, 0, 0); Ui::Dialog("Ѫ�� Ҫ ", 0, 0); Ui::Dialog(requireCoinForPotion, 0, 0); Ui::Dialog("���	##");
		Ui::Dialog("## 3.ҩˮ �ָ�", 0, 0); Ui::Dialog(addHpOfBig_Potion, 0, 0); Ui::Dialog("Ѫ�� Ҫ ", 0, 0); Ui::Dialog(requireCoinForBig_Potion, 0, 0); Ui::Dialog("���	##");
		Ui::Dialog("## 4.�������װ��-", 0, 0); Ui::Dialog(requireCoinForLevel, 0, 0); Ui::Dialog("���	##");
		Ui::Dialog("## �㻹ʣ ", 0, 0); Ui::Dialog(player->getCoin(), 0, 0); 
		Ui::Dialog(" ��� �㻹ʣ	",0,0); Ui::Dialog(player->getHp(), 0, 0); Ui::Dialog("Ѫ��	##");

		char key = _getch();
		switch (key)
		{
		case '1':
			if (player->getCoin() >= requireCoinForKey) {
				player->addCoin(-requireCoinForKey);
				player->addKey();
				Ui::Dialog("��ȥ���Ű�");
				pas();
				isBuy = true;
			}
			else {
				Ui::Dialog("�Ҳ��������Ƶģ������õ�", 0, false); Ui::Dialog(requireCoinForKey, 0, 0); Ui::Dialog("���");
				pas();
			}
			break;

		case '2':
			if (player->getCoin() >= requireCoinForPotion ) {
				player->addCoin(-requireCoinForPotion);
				for (int n{}; n < addHpOfPotion; n++) {
					player->addHp(1);
				}
				//������Ѫ���˻���
				if (player->getHp() >= player->getMaxHp()) {
					Ui::Dialog("��ȵ㲻����");
				}
				else {
					Ui::Dialog("��ָ���", 0, 0); Ui::Dialog(addHpOfPotion, 0, 0); Ui::Dialog("Ѫ��");
				}
				pas();
				isBuy = true;
			}
			else {
				Ui::Dialog("��������������õ�", 0, false); Ui::Dialog(requireCoinForPotion, 0, 0); Ui::Dialog("���");
				pas();
			}
			break;

		case '3':
			if (player->getCoin() >= requireCoinForBig_Potion) {
				player->addCoin(-requireCoinForBig_Potion);
				for (int n{}; n < addHpOfBig_Potion; n++) {
					player->addHp(1);
				}
				//������Ѫ���˻���
				if (player->getHp() >= player->getMaxHp()) {
					Ui::Dialog("������ư�");
				}
				else {
					Ui::Dialog("��ָ���", 0, 0); Ui::Dialog(addHpOfBig_Potion, 0, 0); Ui::Dialog("Ѫ��");
				}
				pas();
				isBuy = true;
			}
			else {
				Ui::Dialog("����˵�´�һ��?�����õ�", 0, false); Ui::Dialog(requireCoinForBig_Potion, 0, 0); Ui::Dialog("���");
				pas();
			}
			break;

		case '4':
			if (player->getLevel() >= 3) {
				Ui::Dialog("��Ҫ�и��õ�װ������������Boss��,�����������ܹ�����");
				pas();
				break;
			}
			if (player->getCoin() >= requireCoinForLevel) {
				player->addCoin(-requireCoinForLevel);
				player->addLevel();
				Ui::Dialog("�Ͻ�ȥ�ݺݵش�����");
				if (player->getHp() <= player->getMaxHp()) {
					player->decreaseHp(-2);
				}
				pas();
				isBuy = true;
			}
			else {
				Ui::Dialog("�������õ�", 0, false); Ui::Dialog(requireCoinForLevel, 0, 0); Ui::Dialog("���");
				pas();
			}
			break;
		case 'q':
			isBuy = true;
			break;
		case '5':
			Ui::Dialog("ɶ��");
			pas();
			isBuy = true;
			break;
		case '6':
			Ui:: Dialog("��û����Ҫ��Ķ���");
			pas();
			isBuy = true;
			break;
		case '7':
			Ui::Dialog("�����䰴��ôԶ�ļ������绨����˼��ô����");
			pas();
			isBuy = true;
			break;
		case '0':
			Ui::Dialog("???��Ҫô�����è�ȼ�������Ҫô���ǡ�����̫������");
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
		Ui::Dialog("������wasdѡ��e��ȷ��");
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