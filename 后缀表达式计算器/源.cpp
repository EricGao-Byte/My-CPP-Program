#include <stdio.h>
#include <stdlib.h>
#define Max 100

//定义栈 
typedef struct
{
	int top;
	char data[Max];
}sqstack;
//创建栈 
sqstack* CreateSqstack()
{
	sqstack* L;
	L = (sqstack*)malloc(sizeof(*L));
	if (L == NULL)
		exit(1);
	L->top = -1;
	return L;
}
//入栈
int PushSqstack(sqstack* L, char x)
{
	//检测栈数据溢出
	if (L->top == Max - 1)
		return -1;
	L->data[++L->top] = x;
	return 0;
}
//出栈 
int PopSqstack(sqstack* L, char* x)
{
	//检测栈数据是否为空
	if (L->top == -1)
		return -1;
	*x = L->data[L->top--];
	return 0;
}
//获得栈顶值
char TopSqstack(sqstack* L)
{
	char x;
	if (L->top == -1)
		return -1;
	x = L->data[L->top];
	return x;
}
//判断栈是否为空
int isEmpty(sqstack* L)
{
	return (L->top == -1);
}
//运算符优先级大小判断
int priority(char ope)
{
	switch (ope)
	{
	case '+':
	case '-':return 1; break;
	case '*':
	case '/':return 2; break;
	case '(':return 3; break;
	}
}
void convert(char* prefix, char* suffix)
{
	sqstack* stack;
	stack = CreateSqstack();
	char* pre, * suf;
	pre = prefix;
	suf = suffix;
	while (*pre != '\0')
	{
		if (*pre >= '0' && *pre <= '9' || *pre == '.')
		{
			*suf == *pre;
			suf++;
			pre++;
		}
		if (*pre == '(' || *pre == '+' || *pre == '-' || *pre == '*' || *pre == '/')
		{
			if (priority(*pre) > priority(TopSqstack(stack)))
			{
				PushSqstack(stack, *pre);
				pre++;
			}
			else
			{
				while (priority(*pre) <= priority(TopSqstack(stack)))
				{
					PopSqstack(stack, suf);
					suf++;
					if (isEmpty)
						break;
				}
				PushSqstack(stack, *pre);
				pre++;
			}

		}
		if (*pre == ')')
		{
			while (TopSqstack(stack) != '(')
			{
				PopSqstack(stack, suf);
				suf++;
			}
			stack->top--;
			pre++;
		}
	}
	while (isEmpty(stack))
	{
		PopSqstack(stack, suf);
		suf++;
	}
	puts(suffix);
	free(stack);
}



int main()
{
	char str1[Max], str2[Max];
	gets_s(str1);
	convert(str1, str2);
	return 0;
}