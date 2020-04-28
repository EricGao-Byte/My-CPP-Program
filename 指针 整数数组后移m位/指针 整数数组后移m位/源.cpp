#include <stdio.h>
#define	N 10
int main()
{
	void input_number(int* a);
	void print_number(int* a);
	void move_number(int* a,int m);
	int a[N];
	int m;
	input_number(a);
	printf("please input how many places you want to move:\n");
	scanf_s("%d", &m);
	move_number(a, m);
	print_number(a);
	return 0;
}
void input_number(int* a)
{
	int i;
	printf("please input %d numbers:\n", N);
	for (i = 0; i < N; i++)
		scanf_s("%d", a + i);
}
void move_number(int* a, int m)
{
	int t[N];
	int i,j;
	//存储后m位数
	j = N - m;
	for ( i = 0; i < m; i++)
	{
			t[i] = *(a + j);
			j++;
	}
	//前n位数往后移动m位数
	for ( i = N-m-1; i >=0; i--)
	{
		*(a + i + 3) = *(a + i);
	}
	//后m位数补齐
	for ( i = 0; i < m; i++)
	{
		*(a + i) = t[i];
	}
}
void print_number(int* a)
{
	int i;
	for (i = 0; i < N; i++)
		printf("%d ", *(a + i));
}
