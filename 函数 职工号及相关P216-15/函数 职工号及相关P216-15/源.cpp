#include <stdio.h>
#include <string.h>
#define N 10
int i, j;
char name[N][N];
int number[N];
void bubble_stb(int a[])
{
	char temp[N];
	int t;
	for (i = N - 1; i >= 1; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				strcpy_s(temp, name[i]);
				strcpy_s(name[i], name[i+1]);
				strcpy_s(name[i], temp);
			}
		}
	}
	for (j = 0; j < N; j++)
	{
		printf("%s ", name[j]);
		printf("%d    ", a[j]);
	}
}
int main()
{
	void bubble_stb(int a[]);
	for ( i = 0; i < N; i++)
	{
		printf("请输入第%d位职工的姓名:", i + 1);
		scanf_s("%s", &name[i], 10);
		printf("请输入第%d位职工的职工号:", i + 1);
		scanf_s("%d", &number[i]);
		getchar();
	}
	bubble_stb(number);
	return 0;
}