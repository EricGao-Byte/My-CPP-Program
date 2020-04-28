#include <stdio.h>
#define	N 3
int main()
{
	void input_array(int(*a)[N], int n);
	void printf_array(int(*a)[N], int n);
	void convers_arrar(int(*a)[N], int n);
	int a[N][N];
	input_array(a, N);
	convers_arrar(a, N);
	printf_array(a, N);
	return 0;
}
void input_array(int(*a)[N], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf_s("%d", *((a + i)) + j);
		}
	}
}
void convers_arrar(int(*a)[N], int n)
{
	int i, j, t, star = 1;
	for ( i = 0; i < n; i++)
	{
		for (j = star; j < n; j++)
		{
			t = *(*(a + i) + j);
			*(*(a + i) + j) = *(*(a + j) + i);
			*(*(a + j) + i) = t;
		}
		star++;
	}
}
void printf_array(int(*a)[N], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d\t", *(*(a + i) + j));
		}
		printf("\n");
	}
}