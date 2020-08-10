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
	void inputMidfix();  //用户输入表达式
	void printMidfix();  //打印用户输入的表达式
	int judgeOperatorPriority(char ope);  //判断符号优先级
	bool isNumber();  //判断指针指向的字符是否是数字或者小数点
	void addBlank();  //添加数字与数字之间的空格分隔符,方便从数组中提取数字
	void convertMidfix();  //用户输入表达式转换为后缀表达式
	void printPostfix();  //打印后缀表达式
	void calculatePostfix();  //计算后缀表达式的值
	Datatype getResult();  //获取表达式的计算结果
	void printResult();  //打印表达式的计算结果
private:
	Datatype result_;
	char midfix_[kmax_length];  //存放用户输入表达式
	char postfix_[kmax_length];  //存放后缀表达式 
	char* midfix, * postfix;  //分别指向用户输入表达式和后缀表达式数组的指针
	Stack<char> operators;  //符号栈
	Stack<Datatype> numbers;  //数字栈
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
	cout << "请输入表达式:" << endl;
	cin >> midfix_;
}

template<class Datatype>
inline void Calculator<Datatype>::printMidfix()
{
	cout << "表达式为:" << endl << midfix_ << endl;
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
	bool firstrun_sign = true;  //用于解决表达式第一个数字是负数的情况
	//从头到尾扫描用户输入的表达式的midfix_数组
	while (*midfix!='\0')
	{
		if (firstrun_sign)  //检测表达式第一个数字是否为负数
		{
			if (*midfix == '-')
			{
				*postfix = *midfix;
				postfix++;
			}
		}//遇到数字和小数点直接输出到postfix_数组
		if (isNumber())
		{
			*postfix = *midfix;
			postfix++;
			if (!(*(midfix + 1) >= '0' && *(midfix + 1) <= '9') && *(midfix + 1) != '.')
			{
				addBlank();
			}
		}//除数字外其他符号
		else
		{
			//遇到左括号入栈operators符号栈作为结束标志
			if (*midfix == '(')
			{
				operators.pushStack(*midfix);
				//括号后是负数的情况
				if (*(midfix + 1) == '-')
				{
					*postfix = *(++midfix);
					postfix++;
				}
			}
			else if (*midfix == ')')//当遇到右括号
			{
				//将直到栈底左括号以上的符号弹出
				while (operators.getStackTop() != '(')
				{
					*postfix = operators.popStack();
					postfix++;
					addBlank();
				}
				operators.popStack();  //弹出'('
			}//若符号栈为空,符号直接入符号栈
			else if(operators.getTopLocation() == -1)
			{
				operators.pushStack(*midfix);
			}//若扫描到的运算符比符号栈栈顶的运算符优先级要大,则该运算符入符号栈
			else if(judgeOperatorPriority(*midfix)>judgeOperatorPriority(operators.getStackTop()))
			{
				operators.pushStack(*midfix);
				//对于幂函数的负指数特殊处理
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
	//读取完成用户输入的数组后将符号栈里剩余的符号依次出栈
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
	cout << "后缀表达式表达式为:" << endl;
	cout << postfix << endl;
}

void MainWindow::calculatePostfix()
{
	postfix = postfix_;
	const char* atof_postfix;  //指向数字段的开头,用于转换字符串中的数字
	while (*postfix != '\0')
	{
		if (isNumber(*postfix) || (*postfix == '-' && isNumber(*(postfix + 1)))) //是数字,直接入数字栈
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
			postfix++; //跳过空格
			numbers.pushStack(atof(atof_postfix));  //atof():将字符串中的数字转换为双精度浮点数
		}
		else  //是数字符
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


/* 以下为计算函数模块  */

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
		//        ui->label->setText( "错误! 分母不能为0!" );
		return -2345783;
	}
	else
	{
		return opd1 / opd2;
	}
}


double MainWindow::Pow(double opd1, double opd2)
{
	//opd1^opd2 opd1的opd2次方
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
	//根号opd1
	if (opd1 < 0)
	{
		//        ui->label->setText("错误! 被开方数不能小于0!");
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
