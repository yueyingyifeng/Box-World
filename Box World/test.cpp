/*
������ɹ���2021/9/27
���԰汾
���ߣ�yueyingyifeng
*/
/*
�˴β��Ա�������һЩ���⣺
һ�����ձ�����Ϸ���ݵĶ��������Ψһ�ģ�������ϵͳ��������Ϊһ��ϵͳ������
������Box World��Ϸ�����ݽ������֡�����ң���ͼ���֡�
�����Ψһ�ģ��ð�
����ͼ����кܶ࣬һ�ŵ�ͼ�ж���֣�һ����Ϸ�ж����ͼ
�㼶��ϵ�������
�����ɹ�����棬��ͼ�ɵ�ͼ����
������Ƚ����ͼ��Ӵ��֣���˹����ͼ�Ĺ�ϵ����һ�����͵İ�����ϵ���ȷ��ʵ�ͼ���ȡ��
�������ڿ��ӻ�����������Ǹ���������World.cpp����һ�μ򵥵�������battleUI��������)
��ʵֻ��һ������˵���˾��ǽ����ֱ������1��2��3�ĳ���ѡ��1��2��3

*/
#include"formBlockEngineAction.h"
#include"World.h"
#include"Map_Resuorce.h"
#include"storyScript.h"


World* box = new World;//�����š����������Ϸ��(����)����
Player* player = new Player;

void first_test() {
	Ui::Dialog("����һ������̨��Ϸ�������ڲ��ֵ�������ʾ��������ͬ");
	Ui::Dialog("");

	story::PAU();
	Ui::Dialog("����Ϊ��ȷ����õ��Ӿ�Ч�������ܻ��Ǹ�����̨��");
	Ui::Dialog("");

	Ui::Dialog("����:");
	Ui::Dialog("");

	Ui::Dialog("�����ϽǵĿ���̨ͼ�꣨���ڵ�����ߣ��Ҽ�");
	Ui::Dialog("");

	Ui::Dialog("�������");
	Ui::Dialog("");

	Ui::Dialog("�ڲ˵���ѡ�����塱");
	Ui::Dialog("");

	Ui::Dialog("�������ͱ����ǡ��������塱,�ҽ����С�� 8X16 (�����ܿ���һ���ɰ���СЦ�� \"  ",0,0);
	putchar(1);
	Ui::Dialog("  \"˵��һ������(����Ǹ������Σ�˵����ʾ������,����Ҫ�ٿ�������Ľ������)");
	Ui::Dialog("");

	Ui::Dialog("ͬʱ��Ҳ���鲻Ҫ����󻯣���Ϊ��С��λ��һ���ַ���������󻯻���ԭ����С���ֿ�������С");
	Ui::Dialog("");

	story::PAU();
	Ui::Dialog("");

	Ui::Dialog("��������ô�����ף����Ϸ��죬��ȡ����,���ڰ�s������",0,0);
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
	Ui::Dialog("## ����1������Ϸ\t\t\t	##	--�������");
	Ui::Dialog("##						##");
	Ui::Dialog("## ����q�˳���Ϸ\t\t\t	##");
	if (_getch() == 'q') {
		return false;
	}
	return true;
}

void difficultyUi() {
	Ui::Dialog("##						##");
	Ui::Dialog("## ѡ��һ����ɫ\t\t\t		##");
	Ui::Dialog("##						##");
	Ui::Dialog("## ��1��aѡ������-���Ѷ�\t\t\t##");
	Ui::Dialog("##						##");
	Ui::Dialog("## ��2��dѡ��ʦ-���Ѷ�\t\t\t##");
	Ui::Dialog("##						##");
	Ui::Dialog("##	������������ڹ�������Ѫ����		##");
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
	SetConsoleTitle("Box World Made by yueyingyifeng ף������. -=�ƶ�Ӧ�ÿ�������=-");
	first_test();
	char k;
	if (Menu()) {
		do{
			loadResource(player, box);
			Game();
			std::cout << "��r���¿�ʼ,������˳�";
			k = _getch();
			player = new Player();
		} while (k =='r');
	}
	
	
	std::cout << "all good" << std::endl;
	return 0;
}