#include <stdio.h>
#include <stdlib.h>
#define MaxLength 100

int Add(int m, int n);
int Sub(int m, int n);
int Mul(int m, int n);
int Div(int m, int n);
double Pow(double m, int length);
double Sqrt(double m);

//定义栈 
typedef struct
{
	int top;
	int data[MaxLength];
}stack;
//创建栈 
stack* CreateSqstack()
{
	stack* L;
	L = (stack*)malloc(sizeof(*L));
	if (L == NULL)
		exit(1);
	L->top = -1;
	return L;
}
//入栈
int PushSqstack(stack* L, int x)
{
	//检测栈数据溢出
	if (L->top == MaxLength - 1)
		return -1;
	L->data[++L->top] = x;
	return 0;
}
//出栈 
int PopSqstack(stack* L, int* x)
{
	//检测栈数据是否为空
	if (L->top == -1)
		return -1;
	*x = L->data[L->top--];
	return 0;
}
//获得栈顶值
int TopSqstack(stack* L, int* x)
{
	if (L->top == -1)
		return -1;
	*x = L->data[L->top];
	return 0;
}
//判断栈是否为空
int isEmptySqstack(stack* L)
{
	return (L->top == -1);
}
//打印栈中元素
void PrintSqstack(stack* L)
{
	int i;
	if (L->top == -1)
		return;
	for (i = 0; i <= L->top; i++)
		printf("%d ", L->data[i]);
	printf("\n");
}
//优先级大小判断
int Priority(int ope)
{
	switch (ope)
	{
	case '(':return 0; break;
	case '-':
	case '+':return 1; break;
	case '*':
	case '/':return 2; break;
		//	case '^':return 3;break;
	default:return -1;
	}
}
//取出数据栈栈顶俩个数进行计算
void Calculate(stack* numstack, int ope)
{
	int n = 0, n1, n2;
	PopSqstack(numstack, &n1);
	PopSqstack(numstack, &n2);
	switch (ope)
	{
	case '+':n = Add(n1, n2); break;
	case '-':n = Sub(n1, n2); break;
	case '*':n = Mul(n1, n2); break;
	case '/':n = Div(n1, n2); break;
		//	case '+':n = n1+n2; break;
		//	case '-':n = n2-n1; break;
		//	case '*':n = n1*n2; break;
		//	case '/':n = n2/n1; break;
	}
	PushSqstack(numstack, n);
}
//处理符号优先级
void dealope(stack* numstack, stack* charcstack, int ope)
{
	int oldope;
	if (isEmptySqstack(charcstack) || ope == '(')
	{
		PushSqstack(charcstack, ope);
		return;
	}
	TopSqstack(charcstack, &oldope);
	if (Priority(ope) > Priority(oldope))
	{
		PushSqstack(charcstack, ope);
		return;
	}
	while (Priority(ope) <= Priority(oldope))
	{
		PopSqstack(charcstack, &oldope);
		Calculate(numstack, oldope);
		if (isEmptySqstack(charcstack))
			break;
		TopSqstack(charcstack, &oldope);
	}
	PushSqstack(charcstack, ope);
}
//处理碰到右括号情况
void dealbracket(stack* numstack, stack* charcstack)
{
	int oldope;
	TopSqstack(charcstack, &oldope);
	//循环计算直到碰到左括号停止
	while (oldope != '(')
	{
		PopSqstack(charcstack, &oldope);
		Calculate(numstack, oldope);
		TopSqstack(charcstack, &oldope);
	}
	PopSqstack(charcstack, &oldope);
}



int main()
{
	printf("*******************程序开始**********************\n");
	printf("******************简单计算器*********************\n");
	printf("****************2019年12月25日*******************\n");
	printf("*******************ver 4.0***********************\n");
	printf("*********copyright EricDeamn(高传金)*************\n");
	printf("* 暂时只能算正整数表达式和单步实数四则方幂开方运算 *\n");
	char str[MaxLength];
	int sign = 1;
	int i;
	int number;
	int flag;
	int oldope;
	while (sign == 1)
	{
		i = 0;
		number = 0;
		flag = 0;
		//两个指向数字栈和符号栈的指针
		stack* numstack, * charcstack;
		numstack = CreateSqstack();
		charcstack = CreateSqstack();
		printf("请输入你要计算的表达式:\n");
		gets_s(str);
		for (i = 0; str[i] != '\0'; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				number = number * 10 + str[i] - '0';
				flag = 1;
			}
			else
			{
				if (flag)//若为1则数字读取完毕，将其存入数字栈中
				{
					PushSqstack(numstack, number);
					flag = 0;
					number = 0;
				}
				if (str[i] == ')')
				{
					dealbracket(numstack, charcstack);
				}
				else
				{
					dealope(numstack, charcstack, str[i]);
				}
			}
		}
		if (flag)
			PushSqstack(numstack, number);
		while (!isEmptySqstack(charcstack))
		{
			PopSqstack(charcstack, &oldope);
			Calculate(numstack, oldope);
		}
		PopSqstack(numstack, &number);
		printf("%s = %d\n", str, number);
		free(numstack);
		free(charcstack);
		printf("继续计算输入 Y     结束计算输入 N\n");
		if (getchar() == 'N')
			sign = 0;
		getchar();

	}
	printf("*******************程序结束**********************");
	return 0;
}
int Add(int m, int n)
{
	return m + n;
}
int Sub(int m, int n)
{
	return m - n;
}
int Mul(int m, int n)
{
	return m * n;
}
int Div(int m, int n)
{
	if (n == 0)
		printf("错误！ 分母不能为0！\n");
	return m / n;
}
double Pow(double m, int length)
{
	double x = 1;
	int i;
	if (length < 0)
	{
		length = -length;
		for (i = 0; i < length; i++)
			x *= m;
		x = 1 / x;
	}
	else
	{
		for (i = 0; i < length; i++)
			x *= m;
	}
	return x;
}
double Sqrt(double m)
{
	int i;
	double x = m / 2;
	if (m < 0)
	{
		printf("错误！ 被开方数不能为负数！\n");
		return -1;

	}
	else if (m == 0)
		return 0;
	else
	{
		for (i = 0; i < 100; i++)
			x = 0.5 * (x + m / x);
	}
	return x;
}
