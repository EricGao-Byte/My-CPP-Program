#include <stdio.h>
#define	N 3
int main()
{
	void input_array(int *,int );
	void output_array(int *,int );
	void bubble_sort(int *,int );
	int a[N];
	printf("please input %d numbers to sort:\n", N);
	input_array(a,N);
	bubble_sort(a,N);
	printf("the sorted number is:\n");
	output_array(a, N);
	return 0;
}
void input_array(int *p1,int n)
{
	int i;
	for (i = 0; i < n; i++)
		scanf_s("%d", p1 + i);
}
void output_array(int *p1, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", *(p1 + i));
}
void bubble_sort(int *p1,int n)
{
	int i, j, t;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (*(p1 + j) > * (p1 + j + 1))
			{
				t = *(p1 + j);
				*(p1 + j) = *(p1 + j + 1);
				*(p1 + j + 1) = t;
			}
		}
	}
}