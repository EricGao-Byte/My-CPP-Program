#include <stdio.h>
#include <malloc.h>
int main()
{
	printf("please input the data amount of the array:\n");
	int n;
	int* a;
	scanf_s("%d", &n);
	a = (int*)malloc(n * sizeof(int));
	int i;
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	free(a);
	return 0;
}