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
		cout << "#|#--= ����֧�֣������� =--#!|		---tips:�Ѵ�GitHub��Դ,��ӭ�������²�" << endl << endl;
		Sleep(400);
		PAU();
		CLS();
		cout << "���ߣ�yueyingyifeng,ף��Ŀ����OVO" << endl << endl;
		PAU();
		CLS();
	}
	//-----------------
	void resuorceLoeding_Map(int number) {
		cout << "��ͼ" << number << "������,�벻Ҫ������" << endl;
		Sleep(300);
	}
	void resuorceLoeded_Map(int number) {
		cout << "��ͼ" << number << "�������" << endl;
		Sleep(100);
	}
	//-----------------
	void resuorceLoeding_Mons(int number) {
		cout << "��ͼ" << number << "�Ĺ�������������,�벻Ҫ������" << endl;
		Sleep(300);
	}
	void resuorceLoeded_Mons(int number) {
		cout << "��ͼ" << number << "�Ĺ����������" << endl;
		Sleep(100);
	}
	//-----------------��----------------//
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
