#include <stdio.h>
#include <string.h> 
#define N 100
int main()
{
	char* addspace(char num1[N]);
	char num[N];
	printf("please input a number to add space:\n");
	gets_s(num);
	printf("the add space string is:\n");
	puts(addspace(num));
	return 0;
}
char* addspace(char num1[N])
{
	static char num2[N];
	int len1 = strlen(num1);
	int i, j = 0;
	for (i = 0; i < (2 * len1 - 1); i++)
	{
		if (i % 2 == 0)
		{
			num2[i] = num1[j];
			j++;
		}
		else num2[i] = ' ';
		num2[2 * len1 - 1] = '\0';
	}
	return (num2);
}