#include <stdio.h>
#include <malloc.h>
#define NULL 0
#define LEN sizeof(struct student)

typedef struct student
{
	int score;
	struct student* next;
}LinkList;
int n;
int main()
{

	return 0;
}
LinkList* creat(int n)//n ����ڵ���
{
	LinkList* head, * node, * end;
	head = (LinkList*)malloc(LEN);
	end = head;//������ͷβ��ͬ
	end->next = NULL;
	int i;
	for ( i = 0; i < n; i++)
	{
		node = (LinkList*)malloc(LEN);
		scanf_s("%d", &node->score);
		head->next = node;
		end = node;
	}
}