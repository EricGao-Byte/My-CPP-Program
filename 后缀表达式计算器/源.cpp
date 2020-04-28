#include <stdio.h>
#include <stdlib.h>
#define Max 100

//����ջ 
typedef struct
{
	int top;
	char data[Max];
}sqstack;
//����ջ 
sqstack* CreateSqstack()
{
	sqstack* L;
	L = (sqstack*)malloc(sizeof(*L));
	if (L == NULL)
		exit(1);
	L->top = -1;
	return L;
}
//��ջ
int PushSqstack(sqstack* L, char x)
{
	//���ջ�������
	if (L->top == Max - 1)
		return -1;
	L->data[++L->top] = x;
	return 0;
}
//��ջ 
int PopSqstack(sqstack* L, char* x)
{
	//���ջ�����Ƿ�Ϊ��
	if (L->top == -1)
		return -1;
	*x = L->data[L->top--];
	return 0;
}
//���ջ��ֵ
char TopSqstack(sqstack* L)
{
	char x;
	if (L->top == -1)
		return -1;
	x = L->data[L->top];
	return x;
}
//�ж�ջ�Ƿ�Ϊ��
int isEmpty(sqstack* L)
{
	return (L->top == -1);
}
//��������ȼ���С�ж�
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