#include <stdio.h>
#include <string.h> 
#define N 100
int ch = 0, num = 0, spa = 0, oth = 0;
int main()
{
	void count(char str1[N]);
	char str[N];
	printf("please input a string:\n");
	gets_s(str);
	count(str);
	printf("the amount of\n");
	printf("character is\n %d\n",ch);
	printf("number is\n %d\n",num);
	printf("space is\n %d\n",spa);
	printf("other character is\n %d\n",oth);
	return 0;
}
void count(char str1[N])
{
	int i;
	for (i = 0; i < strlen(str1); i++)
	{
		if ((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z'))
			ch++;
		else if (str1[i] >= '0' && str1[i] <= '9')
			num++;
		else if (str1[i] == ' ')
			spa++;
		else oth++;
	}
}