#include <stdio.h>
#define	N 100
int main()
{
	void init_array(int* a, int n);
	int count(int* a, int n);
	int n;
	int a[N];
	printf("please input the amount of people:\n");
	scanf_s("%d", &n);
	init_array(a, n);
	printf("the last people's number is NO.%d\n", count(a, n));
	return 0;
}
void init_array(int* a, int n)
{
	//��ʼ����������λΪ1
	int i;
	for ( i = 0; i < n; i++)
	{
		*(a + i) = 1;
	}
}
int count(int* a,int n)
{
	int count, flag, sign , i;
	count = 0;
	flag = n;
	for (i = -1;;)
	{
		i++;
		if(*(a + i) == 1)
			count++;
		if (count % 3 == 0 && *(a + i) == 1)
		{
			*(a + i) = 0;
			flag--;
		}
		if (flag == 1)
			break;
		if (i == n - 1)
			i = -1;
		
	}
	//����������һλ1�Ǽ���
	for ( i = 0; i < n; i++)
	{
		if (*(a + i) == 1)
		{
			sign = i;
			break;
		}
	}
	return (i + 1);

}

