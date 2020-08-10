#pragma once
#ifndef MENU_H
#define MENU_H
#include "Staff.h"


class Menu:public Staff  //菜单类
{
public:
	void main();  //主菜单
	void add();  //增菜单
	void del();  //删菜单
	void modi();  //改菜单
	void search();  //查菜单
	void statistic();  //统计菜单
	void init();  //初始化菜单
	void save();  //保存菜单

	//重载
	friend ostream& operator<<(ostream&, Menu*);
	friend istream& operator>>(istream&, Menu*);


};


#endif
