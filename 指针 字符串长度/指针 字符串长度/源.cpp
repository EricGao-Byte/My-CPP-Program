#include <stdio.h>
#define	N 100
int main()
{
	int str_len(char*);
	char str[N];
	printf("please input a string:\n");
	gets_s(str);
	printf("the string's lenth is %d\n", str_len(str));
	return 0;
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