#pragma once
#ifndef MENU_H
#define MENU_H
#include "Staff.h"


class Menu:public Staff  //�˵���
{
public:
	void main();  //���˵�
	void add();  //���˵�
	void del();  //ɾ�˵�
	void modi();  //�Ĳ˵�
	void search();  //��˵�
	void statistic();  //ͳ�Ʋ˵�
	void init();  //��ʼ���˵�
	void save();  //����˵�

	//����
	friend ostream& operator<<(ostream&, Menu*);
	friend istream& operator>>(istream&, Menu*);


};


#endif
