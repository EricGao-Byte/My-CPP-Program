#pragma once
#ifndef STAFF_H
#define STAFF_H
#include <string>
using namespace std;
const int MAX = 100;

class Staff
{
public:
	string getName(int);  //(数组位置)
	string getWorkTime(int);
	string getSchoolTime(int);
	int getNum(string);
	string getSex(int);
	int getAge(int);
	string getJob(int);
	string getTitle(int);
	string getPolitics(int);
	string getEdu(int);
	string getType(int);
	int getTypeNum(int);

	void setName(int, string);  //(数组位置,输入内容)
	void setWorkTime(int, string);
	void setSchoolTime(int, string);
	void setNum(int,int);
	void setSex(int, int);
	void setAge(int, int);
	void setJob(int,int);
	void setTitle(int,int);
	void setPolitics(int,int);
	void setEdu(int,int);
	void setType(int,int);

	bool isEmpty(int);  //判断人员信息是否为空
	void addStaff();   //添加人员信息
	void delStaff(int);  //删除人员信息
	void modiStaff(int);  //修改人员信息
	void modiStaffInfo(int);
	void searchStaff(int);  //查询人员信息
	void statisticStaff(int);  //统计查询到的人员编号, 储存到数组
	void initStaff();  //初始化人员信息
	void printHead();  //打印表头
	void printStaff(int);  //打印人员信息

	void writeStaffInfo();  //写人员信息到本地
	void readStaffInfo();  //读人员信息到内存




private:
	string m_name[MAX] = { "0" },  //姓名 0表示无
		m_worktime[MAX] = { "1900-00-00" },  //任职时间 格式:YYYY-MM-DD
		m_schooltime[MAX] = { "1900-00-00" };  //来校时间 格式:YYYY-MM-DD
	int m_num[MAX] = { 0 },  //编号 0表示空 从1开始递增
		m_sex[MAX],  //性别 0男性 1女性
		m_age[MAX],  //年龄
		m_job[MAX],  //职务 0无职务 1教师 2教导主任 3系主任 4学院院长 5校长助理6 副校长 7书记 8校长
		m_title[MAX],  //职称 0无职称 1助教 2讲师 3副教授 4教授
		m_politics[MAX],  //政治面貌 0群众 1中共党员
		m_edu[MAX],  //最高学历 0本科以下 1本科 2硕士 3博士
		m_type[MAX];  //人员类型 0行政人员 1教师 2双肩挑 3退休 4返聘 5临时工

	int m_max_num = 1;  //当前人员最大编号 随着人员信息的添加从1递增

	int m_searchList[MAX] = { 0 };  //储存searchStaff()函数搜索到的人员的编号
	int m_searchNum = 0;  //searchStaff()函数搜索到的人员的数量
};


#endif // !STAFF_H

