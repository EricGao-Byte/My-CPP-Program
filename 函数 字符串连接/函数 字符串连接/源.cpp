#include <stdio.h>
#include <string.h> 
#define N 100
int main()
{
	char* connect(static char str3[N], char str4[N]);
	char str1[N], str2[N];
	printf("please input the first string:\n");
	gets_s(str1);
	printf("please input the second string:\n");
	gets_s(str2);
	printf("the connected string is:\n");
	puts(connect(str1, str2));
	return 0;
}
char* connect(static char str3[N], char str4[N])
{
	int len3, len4;
	len3 = strlen(str3);
	len4 = strlen(str4);
	int i, j=0;
	for ( i = len3; i < (len3+len4); i++)
	{
			str3[i] = str4[j];
			j++;
	}
	str3[len3 + len4] = '\0';
	return (str3);
}