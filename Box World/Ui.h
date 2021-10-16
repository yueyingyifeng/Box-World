#pragma once
#include"formBlockEngineAction.h"
#include"Player.h"
#include"Monster.h"
#include<Windows.h>
#include"Animation.h"
enum class key {
	w, a, s, d, e
};

enum class Type {
	attck1, attck2, attck3
};

class Ui :
	public Scene
{
	void cls() {
		system("cls");
	}
	void pas() {
		system("pause");
	}
	//���ֵ
	int Random(int min = 0, int max = 1);
	//ս������ ui����ҵĽ�ɫ������������
	void battleAnimation(Ui* ui, Part part, Type type);
	//�����ַ������ж��������������ַ���
	std::string whatIs(char c);
public:
	Ui()
	{};
	Ui(int x_max, int y_max)
		: Scene(x_max, y_max)
	{}
	//��ʾ��������Ϣ
	void showPlayerInfo(Player* player, char* block);
	//���ս��Ui��ʾ ��ң�����Ҷ�ս�Ĺ�
	int PlayerBattle(Player* player,Monster* mon);
	//�̵�UI
	int shop(Player* player);
	//��������
	key input();

	//���һ����ʾ��Ϣ,��߾�,�Ƿ���
	static void Dialog(std::string msg,int margin_left = 0, bool line = true);
	static void Dialog(int msg, int margin_left = 0, bool line = true);
};

