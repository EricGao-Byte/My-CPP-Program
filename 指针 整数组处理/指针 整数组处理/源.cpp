#include <stdio.h>
#define	N 10
int main()
{
	void input_number(int* a);
	void manage(int* a);
	void print_number(int* a);
	int a[N];
	printf("������10���������д�����С�������һ�����Ի��������������һ�����Ի�����\n");
	input_number(a);
	manage(a);
	printf("�������10������Ϊ:\n");
	print_number(a);
	return 0;
}
void input_number(int* a)
{
	int i;
	for ( i = 0; i < N; i++)
		scanf_s("%d", a + i);
}
void manage(int* a)
{
	int max, min, i;
	int t;
	max = min = 0;
	for (i = 0; i < N; i++)
	{
		if (*(a + i) > * (a + max))
			max = i;
		if (*(a + i) < *(a + min))
			min = i;
	}
	t = *a;
	* a = *(a + min);
	*(a + min) = t;
	t = *(a + N - 1);
	*(a + N - 1) = *(a + max);
	*(a + max) = t;
}
void print_number(int* a)
{
	int i;
	for (i = 0; i < N; i++)
		printf("%d ", *(a + i));
}