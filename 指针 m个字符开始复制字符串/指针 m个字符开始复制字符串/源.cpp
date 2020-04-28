#include <stdio.h>
#define	N 100
int main()
{
	void chose_copystring(char* s, int n);
	int str_len(char* s);
	char str[N];
	int m;
	printf("please input a string:\n");
	gets_s(str,N);
	printf("from which character you want to begin to copy:\n");
	scanf_s("%d", &m);
	if (m > str_len(str))
		printf("error!\nthe number you input is bigger than the lenth of the string.\n");
	else
	{
		printf("the string that you whant to copy is:\n");
		chose_copystring(str, m);
	}
	
	return 0;
}
void chose_copystring(char* s,int n)
{
	char str1[N];
	int i,j=0;
	for ( i = n-1; *(s+i)!='\0' ; i++)
	{
		str1[j] = *(s + i);
		j++;
	}
	str1[j] = '\0';
	puts(str1);
}
int str_len(char* s)
{
	int i;
	for (i = 0; ; i++)
	{
		if (*(s + i) == '\0')
			break;
	}
	return i;
}