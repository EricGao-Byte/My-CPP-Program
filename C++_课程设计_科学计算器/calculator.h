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

void MainWindow::calculatePostfix()
{
	postfix = postfix_;
	const char* atof_postfix;  //ָ�����ֶεĿ�ͷ,����ת���ַ����е�����
	while (*postfix != '\0')
	{
		if (isNumber(*postfix) || (*postfix == '-' && isNumber(*(postfix + 1)))) //������,ֱ��������ջ
		{
			atof_postfix = postfix;
			if (*postfix == '-')
			{
				postfix++;
			}
			while (isNumber(*postfix))
			{
				postfix++;
			}
			postfix++; //�����ո�
			numbers.pushStack(atof(atof_postfix));  //atof():���ַ����е�����ת��Ϊ˫���ȸ�����
		}
		else  //�����ַ�
		{
			switch (*postfix)
			{
			case '+':
				numbers.pushStack(Add(numbers.popStack(), numbers.popStack())); break;
			case '-':
				numbers.pushStack(Sub(numbers.popStack(), numbers.popStack())); break;
			case '*':
				numbers.pushStack(Mul(numbers.popStack(), numbers.popStack())); break;
			case '/':
				numbers.pushStack(Div(numbers.popStack(), numbers.popStack())); break;
			case '^':
				numbers.pushStack(Pow(numbers.popStack(), numbers.popStack())); break;
			case 'S':
				numbers.pushStack(Sqrt(numbers.popStack())); break;
			default:
				break;
			}
			postfix++;
		}
	}
	result_ = numbers.popStack();
}


/* ����Ϊ���㺯��ģ��  */

double MainWindow::Add(double opd1, double opd2)
{
	return opd1 + opd2;
}


double MainWindow::Sub(double opd1, double opd2)
{
	return opd1 - opd2;
}


double MainWindow::Mul(double opd1, double opd2)
{
	return opd1 * opd2;
}


double MainWindow::Div(double opd1, double opd2)
{
	if (opd2 == 0)
	{
		//        ui->label->setText( "����! ��ĸ����Ϊ0!" );
		return -2345783;
	}
	else
	{
		return opd1 / opd2;
	}
}


double MainWindow::Pow(double opd1, double opd2)
{
	//opd1^opd2 opd1��opd2�η�
	double opd = 1;
	int i;
	if (opd2 < 0)
	{
		opd2 = -opd2;
		for (i = 0; i < opd2; i++)
		{
			opd *= opd1;
		}
		opd = 1.0 / opd;
		return opd;
	}
	else
	{
		for (i = 0; i < opd2; i++)
		{
			opd *= opd1;
		}
		return opd;
	}
}


double MainWindow::Sqrt(double opd1)
{
	//����opd1
	if (opd1 < 0)
	{
		//        ui->label->setText("����! ������������С��0!");
		return -1927348;
	}
	else if (opd1 == 0)
	{
		return opd1;
	}
	else
	{
		int i;
		double opd = opd1 / 2;
		for (i = 0; i < 100; i++)
		{
			opd = 0.5 * (opd + opd1 / opd);
		}
		return opd;
	}
}
