#include <stdio.h>
#include <string.h> 
#define N 100
int main()
{
	char* copy(char str1[N]);
	char str[N];
	printf("please input a string:\n");
	gets_s(str);
	printf("the string's vowel is:\n");
	puts(copy(str));
	return 0;
}
char* copy(char str1[N])
{
	static char str2[N];
	int i, j = 0;
	for (i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] == 'A' || str1[i] == 'E' || str1[i] == 'I' || str1[i] == 'O' || str1[i] == 'U')
		{
			str2[j] = str1[i];
			j++;
		}
		if (str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u')
		{
			str2[j] = str1[i];
			j++;
		}
		str2[j] = '\0';
	}
	return (str2);
}