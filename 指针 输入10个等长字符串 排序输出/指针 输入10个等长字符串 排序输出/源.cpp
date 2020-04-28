#include <stdio.h>
#include <string.h>
#define	N 10
#define	Max 100

int main()
{
	void string_sort(char* str[], int n);
	char* str[N];
	char str1[N][Max];
	int i;
	printf("请输入10个字符串：\n");
	for ( i = 0; i < N; i++)
	{
		printf("第%d个字符串为：\n",i+1);
		gets_s(str1[i],Max);
		str[i] = str1[i];
	}
	string_sort(str,N);
	printf("排序后的10个字符串为：\n");
	for ( i = 0; i < N; i++)
	{
		puts(str[i]);
		printf("\n");
	}
	return 0;
}
void string_sort(char* str[],int n)
{
	int i, j;
	char* t;
	int k;//记录下标
	for ( i = 0; i<n-1;i++)
	{
		k = i;
		for ( j = i+1; j < n; j++)
		{
			if (strcmp(str[k],str[j])>0)
				k = j;
			if (k != i)
			{
				t = str[i];
				str[i] = str[k];
				str[k] = t;
			}
		}
	}
}