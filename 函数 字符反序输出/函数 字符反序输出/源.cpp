#include <stdio.h>
#include <string.h> 
#define N 100
int main()
{
	char* reverse(static char str1[N]);
	char str[N];
	printf("please input a string:\n");
	gets_s(str);
	printf("\n");
	printf("the reverse string is:\n");
	puts(reverse(str));
	printf("\n");
	return 0;
}
char* reverse(static char str1[N])
{
	char t;
	int i, len = strlen(str1);
	for ( i = 0; i < (len+1)/2; i++)
	{
		t = str1[i];
		str1[i] = str1[len - 1 - i];
		str1[len - 1 - i] = t;
	}
	return (str1);
}