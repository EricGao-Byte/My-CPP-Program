#include <stdio.h>
#define N 5
struct grades
{
	int num;
	char name[20];
	float score[3];
};
int main()
{
	void print(struct grades stu[5]);
	void input(struct grades* stu1);
	struct grades stu[N];
	input(stu);
	print(stu);
	return 0;
}
void input(struct grades* stu1)
{
	int i,j;
	for (i = 0; i < N; i++)
	{
		printf("please input the NO.%d student's number,name and three grades\n", i+1);
		scanf_s("%d", &(stu1+i)->num);
		scanf_s("%s", (stu1+i)->name, 20);
		for ( j = 0; j < 3; j++)
		{
			scanf_s("%f", &(stu1 + i)->score[j]);
		}
	}
	return stu1;
}
void print(struct grades stu[5])
{
	int i,j;
	printf("NO.\tname\tscore1\tscore2\tscore3\n");
	for (i = 0; i < N; i++)
	{
		printf("%d\t%s\t", stu[i].num, stu[i].name);
		for ( j = 0; j < 3; j++)
		{
			printf("%.1f\t", stu[i].score[j]);
		}
		printf("\n");
	}
}