#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "stack.h"
#include <iostream>
using namespace std;

template <class Datatype>
class Calculator
{
public:
	Calculator();
	void inputMidfix();  //�û�������ʽ
	void printMidfix();  //��ӡ�û�����ı��ʽ
	int judgeOperatorPriority(char ope);  //�жϷ������ȼ�
	bool isNumber();  //�ж�ָ��ָ����ַ��Ƿ������ֻ���С����
	void addBlank();  //�������������֮��Ŀո�ָ���,�������������ȡ����
	void convertMidfix();  //�û�������ʽת��Ϊ��׺���ʽ
	void printPostfix();  //��ӡ��׺���ʽ
	void calculatePostfix();  //�����׺���ʽ��ֵ
	Datatype getResult();  //��ȡ���ʽ�ļ�����
	void printResult();  //��ӡ���ʽ�ļ�����
private:
	Datatype result_;
	char midfix_[kmax_length];  //����û�������ʽ
	char postfix_[kmax_length];  //��ź�׺���ʽ 
	char* midfix, * postfix;  //�ֱ�ָ���û�������ʽ�ͺ�׺���ʽ�����ָ��
	Stack<char> operators;  //����ջ
	Stack<Datatype> numbers;  //����ջ
};

#endif // !CALCULATOR_H

template<class Datatype>
inline Calculator<Datatype>::Calculator()
{
	result_ = 0;
	midfix = midfix_;
	postfix = postfix_;

}

template<class Datatype>
inline void Calculator<Datatype>::inputMidfix()
{
	cout << "��������ʽ:" << endl;
	cin >> midfix_;
}

template<class Datatype>
inline void Calculator<Datatype>::printMidfix()
{
	cout << "���ʽΪ:" << endl << midfix_ << endl;
}

template<class Datatype>
inline int Calculator<Datatype>::judgeOperatorPriority(char ope)
{
	switch (ope)
	{
	case '(':return 0;
	case ')':return 0;
	case 'S':return 1;
	case '+':return 2;
	case '-':return 2;
	case '*':return 3;
	case '/':return 3;
	case '^':return 4;
	default:return -1;
	}
}

template<class Datatype>
inline bool Calculator<Datatype>::isNumber()
{
	if (*midfix >= '0' && *midfix <= '9' || *midfix == '.')
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class Datatype>
inline void Calculator<Datatype>::addBlank()
{
		*postfix = ' ';
		postfix++;
}

template<class Datatype>
inline void Calculator<Datatype>::convertMidfix()
{
	bool firstrun_sign = true;  //���ڽ�����ʽ��һ�������Ǹ��������
	//��ͷ��βɨ���û�����ı��ʽ��midfix_����
	while (*midfix!='\0')
	{
		if (firstrun_sign)  //�����ʽ��һ�������Ƿ�Ϊ����
		{
			if (*midfix == '-')
			{
				*postfix = *midfix;
				postfix++;
			}
		}//�������ֺ�С����ֱ�������postfix_����
		if (isNumber())
		{
			*postfix = *midfix;
			postfix++;
			if (!(*(midfix + 1) >= '0' && *(midfix + 1) <= '9') && *(midfix + 1) != '.')
			{
				addBlank();
			}
		}//����������������
		else
		{
			//������������ջoperators����ջ��Ϊ������־
			if (*midfix == '(')
			{
				operators.pushStack(*midfix);
				//���ź��Ǹ��������
				if (*(midfix + 1) == '-')
				{
					*postfix = *(++midfix);
					postfix++;
				}
			}
			else if (*midfix == ')')//������������
			{
				//��ֱ��ջ�����������ϵķ��ŵ���
				while (operators.getStackTop() != '(')
				{
					*postfix = operators.popStack();
					postfix++;
					addBlank();
				}
				operators.popStack();  //����'('
			}//������ջΪ��,����ֱ�������ջ
			else if(operators.getTopLocation() == -1)
			{
				operators.pushStack(*midfix);
			}//��ɨ�赽��������ȷ���ջջ������������ȼ�Ҫ��,�������������ջ
			else if(judgeOperatorPriority(*midfix)>judgeOperatorPriority(operators.getStackTop()))
			{
				operators.pushStack(*midfix);
				//�����ݺ����ĸ�ָ�����⴦��
				if (*midfix == '^' && *(midfix + 1) == '-')
				{
					*postfix = *(++midfix);
					postfix++;
				}
			}
			else
			{
				while (judgeOperatorPriority(*midfix) <= judgeOperatorPriority(operators.getStackTop()))
				{
					*postfix = operators.getStackTop();
					postfix++;
					addBlank();
					operators.popStack();
					if (operators.isEmpty())
					{
						break;
					}
				}
				operators.pushStack(*midfix);
			}
		}
		firstrun_sign = false;
		midfix++;
	}
	//��ȡ����û����������󽫷���ջ��ʣ��ķ������γ�ջ
	while (!operators.isEmpty())
	{
		*postfix = operators.popStack();
		postfix++;
		addBlank();
	}
	*postfix = '\0';
	postfix = postfix_;
	midfix = midfix_;
}

template<class Datatype>
inline void Calculator<Datatype>::printPostfix()
{
	cout << "��׺���ʽ���ʽΪ:" << endl;
	cout << postfix << endl;
}
