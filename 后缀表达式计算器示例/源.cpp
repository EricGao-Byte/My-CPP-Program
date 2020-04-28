#include <stdio.h>  
#include <stdlib.h> 

#define MAX_LEN 80  
void convert(char* prefix, char* suffix);
double cal(char* prefix);
//��׶���ʽת��׺���ʽ ͨ���ӿո�ķ�ʽ���������ַ��������ݵĶ�ȡ
//���忪����Ϊ���ȼ��������  ����Ϊ�������
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
		//����ֱ�����
		if (*pre >= '0' && *pre <= '9')
		{
			*suf = *pre;
			suf++;
			//����ָ��ո�  
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
		//������ֱ����ջ��Ϊ�����Ž�����־����������
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
				//����ָ��ո�  
				*suf = ' ';
				suf++;
			}
			//����'('  
			top--;
		}
		if (*pre == '*' || *pre == '/')
		{
			//ջ�����ȼ����ڵ��ڳ˺źͳ��ŵĵ���
			if (stack[top] == '*' || stack[top] == '/'||stack[top]=='^')
			{
				*suf = stack[top--];
				suf++;
				//����ָ��ո�  
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
				//����ָ��ո�  
				*suf = ' ';
				suf++;
			}
			stack[++top] = *pre;
		}
		//�������ȼ���ߣ�ֱ����ջ����ʱ�����Ƕ�����ݵ��ӵ����
		if (*pre == '^')
		{
			stack[++top] = *pre;
		}
		pre++;
	}
	//ɨ����ɺ�ȡ��ջ�������������д���׺���ʽ���顣
	while (top != -1)
	{
		*suf = stack[top--];
		suf++;
		*suf = ' ';
		suf++;
	}
	*suf = '\0';
}
//�����׺���ʽ 
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
			//���ַ����е�������\0�������ַ�����������atof������ȡ�ַ����������������
			pre = p;
			while ((*p >= '0' && *p <= '9') || *p == '.')
			{
				p++;
			}
			*p = '\0';
			stack[++top] = atof(pre);//atof�����ܰ��ַ�������ת��Ϊ˫���ȸ�����
		}
		if (*p == 'S')
		{
			stack[top] = Sqrt(stack[top]);
		}
		if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '^')
		{
			//ȡ��ջ�����������������㣬ע����ȡ�������Ǻ������
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
		printf("���󣡷�ĸ����Ϊ�㣡\n");
		exit(1);
	}
	return m / n;

}
double Sqrt(double x)
{
	if(x<0)
	{
		printf("���� ������������С��0��");
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
	printf("\t\t*                 *�򵥼�����ver5.0*               *\n");
	printf("\t\t*      *�ɼ��㺬�мӼ��˳������ͷ��ݵı��ʽ*      *\n");
	printf("\t\t*           *copyright EricDeamn(�ߴ���)*          *\n");
	printf("\t\t****************************************************\n");
	printf("\t��ʾ��\n");
	printf("\t\t1.��Ҫ���������������дS������S2*3��Ĭ�Ͽ����������ȼ���ͣ�\n");
	printf("\t\t  �ȼ�����S����ʽ��ֵ����ټ��㿪����\n");
	printf("\t\t2.���ݼ������ȼ���ߣ���֧�ַ��ݵ������㡣\n\n");
	char str1[MAX_LEN], str2[MAX_LEN];
	//������ʽ 
	int flag = 1;
	while (flag == 1)
	{
		printf("��������ʽ��\n");
		gets_s(str1);
		convert(str1, str2);
		printf("result = %.5lf\n", cal(str2));
		printf("\t\t������������ 1\t\t������������ 0\n");
		scanf_s("%d", &flag);
		getchar();
	}
	printf("***********************�������***********************\n");
	return 0;
}