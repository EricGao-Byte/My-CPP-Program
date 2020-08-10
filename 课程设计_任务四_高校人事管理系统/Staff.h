#pragma once
#ifndef STAFF_H
#define STAFF_H
#include <string>
using namespace std;
const int MAX = 100;

class Staff
{
public:
	string getName(int);  //(����λ��)
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

	void setName(int, string);  //(����λ��,��������)
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

	bool isEmpty(int);  //�ж���Ա��Ϣ�Ƿ�Ϊ��
	void addStaff();   //�����Ա��Ϣ
	void delStaff(int);  //ɾ����Ա��Ϣ
	void modiStaff(int);  //�޸���Ա��Ϣ
	void modiStaffInfo(int);
	void searchStaff(int);  //��ѯ��Ա��Ϣ
	void statisticStaff(int);  //ͳ�Ʋ�ѯ������Ա���, ���浽����
	void initStaff();  //��ʼ����Ա��Ϣ
	void printHead();  //��ӡ��ͷ
	void printStaff(int);  //��ӡ��Ա��Ϣ

	void writeStaffInfo();  //д��Ա��Ϣ������
	void readStaffInfo();  //����Ա��Ϣ���ڴ�




private:
	string m_name[MAX] = { "0" },  //���� 0��ʾ��
		m_worktime[MAX] = { "1900-00-00" },  //��ְʱ�� ��ʽ:YYYY-MM-DD
		m_schooltime[MAX] = { "1900-00-00" };  //��Уʱ�� ��ʽ:YYYY-MM-DD
	int m_num[MAX] = { 0 },  //��� 0��ʾ�� ��1��ʼ����
		m_sex[MAX],  //�Ա� 0���� 1Ů��
		m_age[MAX],  //����
		m_job[MAX],  //ְ�� 0��ְ�� 1��ʦ 2�̵����� 3ϵ���� 4ѧԺԺ�� 5У������6 ��У�� 7��� 8У��
		m_title[MAX],  //ְ�� 0��ְ�� 1���� 2��ʦ 3������ 4����
		m_politics[MAX],  //������ò 0Ⱥ�� 1�й���Ա
		m_edu[MAX],  //���ѧ�� 0�������� 1���� 2˶ʿ 3��ʿ
		m_type[MAX];  //��Ա���� 0������Ա 1��ʦ 2˫���� 3���� 4��Ƹ 5��ʱ��

	int m_max_num = 1;  //��ǰ��Ա����� ������Ա��Ϣ����Ӵ�1����

	int m_searchList[MAX] = { 0 };  //����searchStaff()��������������Ա�ı��
	int m_searchNum = 0;  //searchStaff()��������������Ա������
};


#endif // !STAFF_H

