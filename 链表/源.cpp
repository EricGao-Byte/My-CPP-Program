#include <stdio.h>
#include <malloc.h>
#define N 5
#define NULL 0
#define LEN sizeof(struct student)
int main()
{
	struct student* creat();
	void print(struct student* );
	void deletall(struct student* );
	struct student* head;
	head = creat();
	print(head);
	deletall(head);
	return 0;
}
struct student
{
	int num;
	float score;
	struct student* next;
};
struct student* creat()
{
	struct student* head;
	struct student* p[N];
	int i;
	for ( i = 0; i < N; i++)
		p[i] = (struct student*)malloc(LEN);
	head = p[0];
	for ( i = 0; i < N-1; i++)
	{
		p[i]->next = p[i + 1];
		p[i + 1]->next = NULL;
		scanf_s("%d%f", &p[i]->num, &p[i]->score);
	}
	return head;
}
void print(struct student* head)
{
	struct student* p;
	p = head;
	while (p != NULL)
	{
		printf("%d %f\n", p->num, p->score);
		p = p->next;
	}
}
void deletall(struct student* head)
{
	struct student* p;
	p = head;
	while (p != NULL)
	{
		free (p);
		p = p->next;
	}
}