#include <stdio.h>
#include <malloc.h>
#define N 10
#define M 100

int main()
{

	int stringlen(char*);
	char* stringcpy(char*, int, char*);
	char* stringcat(char*, int, char*);
	int stringcmp(char*, char*);
	char str1[N];
	char str2[M];
	printf("please input str1\n");
	gets_s(str1);
	printf("please input str2\n");
	gets_s(str2);

	//printf("str1lenth=%d\n", stringlen(str1));
	//printf("str2lenth=%d\n", stringlen(str2));

	//printf("stringcopy str2 to str1=%s\n", stringcpy(str1, N, str2));
	//printf("str2=%s\n", str2);

	printf("stringcat str2 to str1=%s\n", stringcat(str1, N, str2));
	printf("str2=%s\n", str2);

	//printf("stringcmp str1 and str2 = %d\n", stringcmp(str1, str2));
	return 0;
}

char* stringcpy(char* s1,int len_s1, char* s2)
{
	int stringlen(char*);
	char* p;
	p = s1;
	if (len_s1 < stringlen(s2))
		printf("error! array lenth too short!data might be missed.\n");
	while (*s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
	return p;
}
int stringlen(char* s)
{
	int len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return len;
}
char* stringcat(char* s1, int n1, char* s2)
{
	int stringlen(char*);
	char* stringcpy(char*, int, char*);
	char* p;
	p = s1;
	if ((n1 - stringlen(s1)) < stringlen(s2))
		printf("error! array lenth too short!data might be missed.\n");
	s1 += stringlen(s1);
	s1 = stringcpy(s1, n1, s2);
	return p;
}
int stringcmp(char* s1, char* s2)
{
	int stringlen(char*);
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 > * s2)
			return 1;
		if (*s1 < *s2)
			return -1;
		s1++;
		s2++;
	}
	if (stringlen(s1) == stringlen(s2))
		return 0;
	else if (stringlen(s1) > stringlen(s2))
		return 1;
	else
		return -1;
}
