#include <stdio.h>  
#include <stdlib.h> 

#define MAX_LEN 80  
void convert(char* prefix, char* suffix);
double cal(char* prefix);
//中锥表达式转后缀表达式 通过加空格的方式方便后面对字符串中数据的读取
//定义开根号为优先级最低运算  方幂为最高运算
void convert(char* prefix, char* suffix)
{
	char* pre, * suf;
	char stack[MAX_LEN];
	int top;

	top = -1;
	pre = prefix;
	suf = suffix;
	while (*pre != '\0')
	{
		if (*pre == 'S')
		{
			stack[++top] = *pre;
		}
		//数字直接输出
		if (*pre >= '0' && *pre <= '9')
		{
			*suf = *pre;
			suf++;
			//加入分隔空格  
			if (!(*(pre + 1) >= '0' && *(pre + 1) <= '9') && *(pre + 1) != '.')
			{
				*suf = ' ';
				suf++;
			}
		}
		if (*pre == '.')
		{
			*suf = *pre;
			suf++;
		}
		//左括号直接入栈作为右括号结束标志，但最后不输出
		if (*pre == '(')
		{
			stack[++top] = *pre;
		}
		if (*pre == ')')
		{
			while (stack[top] != '(')
			{
				*suf = stack[top--];
				suf++;
				//加入分隔空格  
				*suf = ' ';
				suf++;
			}
			//弹出'('  
			top--;
		}
		if (*pre == '*' || *pre == '/')
		{
			//栈顶优先级大于等于乘号和除号的弹出
			if (stack[top] == '*' || stack[top] == '/'||stack[top]=='^')
			{
				*suf = stack[top--];
				suf++;
				//加入分隔空格  
				*suf = ' ';
				suf++;
			}
			stack[++top] = *pre;
		}
		if (*pre == '+' || *pre == '-')
		{
			while (stack[top] == '*'|| stack[top] == '/'|| stack[top] == '+'|| stack[top] == '-'||stack[top]=='^')
			{
				*suf = stack[top--];
				suf++;
				//加入分隔空格  
				*suf = ' ';
				suf++;
			}
			stack[++top] = *pre;
		}
		//方幂优先级最高，直接入栈，暂时不考虑多个方幂叠加的情况
		if (*pre == '^')
		{
			stack[++top] = *pre;
		}
		pre++;
	}
	//扫描完成后，取出栈中所有运算符，写入后缀表达式数组。
	while (top != -1)
	{
		*suf = stack[top--];
		suf++;
		*suf = ' ';
		suf++;
	}
	*suf = '\0';
}
//计算后缀表达式 
double cal(char* prefix)
{
	double Div(double , double );
	double Pow(double , int );
	double Sqrt(double );
	double stack[MAX_LEN];
	double opd1, opd2;
	int top;
	char* p, * pre;
	top = -1;

	p = prefix;
	while (*p != '\0')
	{
		if (*p >= '0' && *p <= '9')
		{
			//将字符串中的数字用\0与其他字符隔开，再用atof函数提取字符串隔离出来的数字
			pre = p;
			while ((*p >= '0' && *p <= '9') || *p == '.')
			{
				p++;
			}
			*p = '\0';
			stack[++top] = atof(pre);//atof函数能把字符串数字转化为双精度浮点数
		}
		if (*p == 'S')
		{
			stack[top] = Sqrt(stack[top]);
		}
		if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '^')
		{
			//取出栈顶的两个数进行运算，注意先取出来的是后面的数
			opd2 = stack[top--];
			opd1 = stack[top];
			switch (*p) 
			{
			case '+':
				stack[top] = opd1 + opd2;
				break;
			case '-':
				stack[top] = opd1 - opd2;
				break;
			case '*':
				stack[top] = opd1 * opd2;
				break;
			case '/':
				stack[top] = Div(opd1,opd2);
				break;
			case '^':
				stack[top] = Pow(opd1, opd2);
				break;
			}
		}
		p++;
	}
	return stack[top];
}
double Div(double m, double n)
{
	if(n==0)
	{
		printf("错误！分母不能为零！\n");
		exit(1);
	}
	return m / n;

}
double Sqrt(double x)
{
	if(x<0)
	{
		printf("错误！ 被开方数不能小于0！");
		exit(-1);
	}
	if (x == 0)
		return x;
	int i;
	double x0 = x / 2;
	for ( i = 0; i < 100; i++)
	{
		x0 = 0.5*(x0 + x / x0);
	}
	return x0;

}
double Pow(double x, int n)
{
	double x0 = 1;
	int i;
	if (n < 0)
	{
		n = -n;
		for (i = 0; i < n; i++)
			x0 *= x;
		x0 = 1.0 / x0;
	}
	else
	{
		for (i = 0; i < n; i++)
			x0 *= x;
	}
	return x0;
}
int main()
{
	printf("\t\t****************************************************\n");
	printf("\t\t*                 *简单计算器ver5.0*               *\n");
	printf("\t\t*      *可计算含有加减乘除开方和方幂的表达式*      *\n");
	printf("\t\t*           *copyright EricDeamn(高传金)*          *\n");
	printf("\t\t****************************************************\n");
	printf("\t提示：\n");
	printf("\t\t1.若要开方计算请输入大写S，例如S2*3，默认开方计算优先级最低，\n");
	printf("\t\t  先计算完S后表达式的值最后再计算开方。\n");
	printf("\t\t2.方幂计算优先级最高，不支持方幂叠加运算。\n\n");
	char str1[MAX_LEN], str2[MAX_LEN];
	//读入表达式 
	int flag = 1;
	while (flag == 1)
	{
		printf("请输入表达式：\n");
		gets_s(str1);
		convert(str1, str2);
		printf("result = %.5lf\n", cal(str2));
		printf("\t\t继续计算输入 1\t\t结束计算输入 0\n");
		scanf_s("%d", &flag);
		getchar();
	}
	printf("***********************程序结束***********************\n");
	return 0;
}