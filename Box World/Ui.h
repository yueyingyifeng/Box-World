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
	//随机值
	int Random(int min = 0, int max = 1);
	//战斗动画 ui，玩家的角色，攻击的类型
	void battleAnimation(Ui* ui, Part part, Type type);
	//根据字符类型判断是声明，返回字符串
	std::string whatIs(char c);
public:
	Ui()
	{};
	Ui(int x_max, int y_max)
		: Scene(x_max, y_max)
	{}
	//显示玩家相关信息
	void showPlayerInfo(Player* player, char* block);
	//玩家战斗Ui显示 玩家，与玩家对战的怪
	int PlayerBattle(Player* player,Monster* mon);
	//商店UI
	int shop(Player* player);
	//接收输入
	key input();

	//输出一段提示信息,左边距,是否换行
	static void Dialog(std::string msg,int margin_left = 0, bool line = true);
	static void Dialog(int msg, int margin_left = 0, bool line = true);
};

