#include <stdio.h>
#include <string.h>
#define	N 3
#define	MAX 100
int main()
{
	void input_strings(char(*)[MAX], int, int);
	void string_sort(char(*)[MAX], int);
	void print_strings(char(*)[MAX], int);
	char str[N][MAX];
	printf("please input three strings to sort:\n");
	input_strings(str, N, MAX);
	string_sort(str, N);
	printf("the sorted three strings is:\n");
	print_strings(str, N);
	return 0;
}
void input_strings(char(*p1)[MAX], int n, int max)
{
	int i;
	for ( i = 0; i < N; i++)
		gets_s(*(p1 + i), MAX);
	
}
void string_sort(char(*p1)[MAX], int n)
{
	int i;
	char t[MAX];
	for (i = 0; i < n; i++)
	{
		if (strcmp(*(p1 + i), *(p1 + i + 1)) > 0)
		{
			strcpy_s(t, *(p1 + i));
			strcpy_s(*(p1 + i), *(p1 + i + 1));
			strcpy_s(*(p1 + i + 1), t);
		}
	}
}
void print_strings(char(*p1)[MAX], int)
{
	int i;
	for ( i = 0; i < N; i++)
		puts(*(p1 + i));
}