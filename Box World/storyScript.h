#pragma once
#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<Windows.h>

using namespace std;

namespace story {
	void CLS() {
		system("cls");
	}
	void PAU() {
		system("pause");
	}

	void beforeGame() {
		cout << "#|#--= 技术支持：方格框架 =--#!|		---tips:已传GitHub开源,欢迎讨论与吐槽" << endl << endl;
		Sleep(400);
		PAU();
		CLS();
		cout << "作者：yueyingyifeng,祝玩的开心喔OVO" << endl << endl;
		PAU();
		CLS();
	}
	//-----------------
	void resuorceLoeding_Map(int number) {
		cout << "地图" << number << "加载中,请不要动键盘" << endl;
		Sleep(300);
	}
	void resuorceLoeded_Map(int number) {
		cout << "地图" << number << "加载完毕" << endl;
		Sleep(100);
	}
	//-----------------
	void resuorceLoeding_Mons(int number) {
		cout << "地图" << number << "的怪物正在生成中,请不要动键盘" << endl;
		Sleep(300);
	}
	void resuorceLoeded_Mons(int number) {
		cout << "地图" << number << "的怪物生成完毕" << endl;
		Sleep(100);
	}
	//-----------------序----------------//
	void foreword() {
		cout 
			<< " ____                                  _     _ " << endl
			<< "|  _ \\                                | |   | |" << endl
			<< "| |_) | _____  __ __      _____  _ __ | | __| |" << endl
			<< "|  _ < / _ \\ \\/ / \\ \\ /\\ / / _ \\| '__|| |/ _` |" << endl
			<< "| |_) | (_) >  <   \\ V  V / (_) | |   | | (_| |" << endl
			<< "|____/ \\___/_/\\_\\   \\_/\\_/ \\___/|_|   |_|\\__,_|" << endl
			<< endl;
	}

}
