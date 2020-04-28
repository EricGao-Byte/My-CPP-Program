#include <stdio.h>
#include <malloc.h>
#define N 10
#define Len sizeof(student)

struct student
{
	int num;
	char name[10];
	student* next;
};

int main()
{
	/*void selectsort(int* a, int n);
	void bubblesort(int* a, int n);
	void inputarray(int* a, int n);
	void printarray(int* a, int n);
	double power(double x, int n);
	int fac(int n);
	int a[N];*/
	//bubble sort
	/*inputarray(a, N); 
	bubblesort(a, N);
	printarray(a, N);*/
	


	//select sort 
	//inputarray(a, N);
	//selectsort(a, N);
	//printarray(a, N);

	//list
	//student* creatlist();
	//student* creatnode();
	//void rearinsert(student*, student*);
	//void printlist(student*);
	//void headinsert(student*, student*);

	//student* head;
	//head = creatlist();
	//student* node1, * node2, * node3, * node4;
	//node1 = creatnode();
	//headinsert(head, node1);
	////rearinsert(head,node1);
	//node2 = creatnode();
	//headinsert(head, node2);
	////rearinsert(head,node2);
	//node3 = creatnode();
	//headinsert(head, node3);
	////rearinsert(head,node3);
	//node4 = creatnode();
	//headinsert(head, node4);
	////rearinsert(head,node4);
	//printlist(head);

	//折半查找
	//void half_find(int*, int);
	//void inputarray(int*, int);
	//void bubblesort(int*, int);
	//void selectsort(int*, int);
	//void printarray(int* g, int length);

	//int a[15];
	//inputarray(a, 15);
	////selectsort(a, 15);
	//bubblesort(a, 15);
	//printarray(a, 15);
	//half_find(a, 15);

	//杨辉三角
	void YangTri();
	
	YangTri();
	return 0;
}

void YangTri()
{
	void addspace(int);
	int fac(int);
	int h, l, n, C;
	printf("enter n:");
	scanf_s("%d", &n);
	for ( h = 1; h <= n; h++)
	{
		addspace(n - h);
		for ( l = 1; l <= h; l++)
		{
			if (l == 1 || l == h)
				printf("1 ");
			else
			{
				C = fac(h - 1) / (fac(h - l) * fac(l - 1));
				printf("%d ", C);
			}
		}
		printf("\n");
	}
}
int fac(int n)
{
	if (n == 1 || n == 0)
		return 1;
	return n * fac(n - 1);
}
void addspace(int length)
{
	int i;
	for (i = 0; i < length; i++)
		printf(" ");
}




void inputarray(int* d, int length)
{
	int i;
	for (i = 0; i < length; i++)
		scanf_s("%d", &d[i]);
}
void printarray(int* g, int length)
{
	int i;
	for ( i = 0; i < length; i++)
		printf("%d ", g[i]);
}
void half_find(int* b, int length)
{
	int num;
	printf("input a number you want to find:\n");
	scanf_s("%d", &num);
	int flag, top, boo,mid;
	top = length - 1;
	boo = 0;
	flag = 1;
	while (top>boo&&flag==1)
	{
		mid = (top + boo) / 2;
		if (num == b[mid])
		{
			printf("find it!  %d  ", mid + 1);
			flag = 0;
			break;
		}
		else if(num<b[mid])
		{
			top = mid - 1;
		}
		else
		{
			boo = mid + 1;
		}
	}
	if (flag == 1)
		printf("no result!");

}
void selectsort(int* c, int length)
{
	int i, j, t;
	int sign;
	for ( i = 0; i < length; i++)
	{
		sign = 0;
		for (j = 0; j <= length-i-1; j++)
		{
			if (c[j]<c[sign])
				sign = j;
			
		}
		if (sign != length - i - 1)
		{
			t = c[sign];
			c[sign] = c[length - i - 1];
			c[length - i - 1] = t;
		}
	}

}
void bubblesort(int* c,int length)
{
	int i, j, t;
	for ( i = 0; i < length; i++)
	{
		for (j = 0; j <= length - i - 2; j++)
		{
			if (c[j] >= c[j + 1])
			{
				t = c[j];
				c[j] = c[j + 1];
				c[j + 1] = t;
			}
		}
	}
}



//student* creatlist()
//{
//	student* head;
//	head = (student*)malloc(Len);
//	if (head == NULL)
//		return NULL;
//	head->num = 0;
//	head->name[0] = '\0';
//	head->next = NULL;
//	return head;
//}
//student* creatnode()
//{
//	student* p;
//	p = (student*)malloc(Len);
//	if (p == NULL)
//		return NULL;
//	printf("input student's number:\n");
//	scanf_s("%d", &p->num);
//	getchar();
//	printf("input student's name:\n");
//	gets_s(p->name, 10);
//	p->next = NULL;
//	return p;
//}
//int listnum(student* head)
//{
//	int n = 0;
//	student* p;
//	p = head;
//	while (p->next != NULL)
//	{
//		n++;
//		p = p->next;
//	}
//	return n;
//}
//void deletenode(student* head, int m)
//{
//	student* p, * q;
//	p = head;
//	q = head->next;
//	int i;
//	for ( i = 1; i < m; i++)
//	{
//		p = p->next;
//		q = q->next;
//	}
//	p->next = q->next;
//	free(q);
//}
//void headinsert(student* head, student* node)
//{
//	node->next = head->next;
//	head->next = node;
//}
//void rearinsert(student* head,student* node)
//{
//	student* q;
//	q = head;
//	while (q->next!=NULL)
//		q = q->next;
//	q->next = node;
//}
//void printlist(student* head)
//{
//	student* p;
//	p = head->next;
//	if (head->next == NULL)
//		printf("there is no list!\n");
//	printf("NO.\tNAME\n");
//	while (p != NULL)
//	{
//		printf("%d\t%s\n", p->num, p->name);
//		p = p->next;
//	}
//}






//int fac(int n)
//{
//	if (n == 1 || n == 0)
//		return 1;
//	return n * fac(n - 1);
//}
//double power(double x, int n)
//{
//	int i;
//	double x0 = 1;
//	for ( i = 1; i <= n; i++)
//	{
//		x0 *= x;
//	}
//	return x0;
//}
//void selectsort(int* a, int n)
//{
//	int i, j, t;
//	int k;//记录下标
//	for ( i = 0; i < n; i++)
//	{
//		k = 0;
//		for ( j = 0; j < n-i; j++)
//		{
//			if (a[j]<a[k])
//				k = j;
//			if (k != n - i)
//			{
//				t = a[k];
//				a[k] = a[n - i];
//				a[n - i] = t;
//			}
//		}
//	}
//
//}
//void inputarray(int* a,int n)
//{
//	int i;
//	printf("please input %d numbers\n", n);
//	for ( i = 0; i < n; i++)
//		scanf_s("%d", a+i);
//}
//void printarray(int* a, int n)
//{
//	int i;
//	for ( i = 0; i < n; i++)
//	{
//		printf("%d ", *(a + i));
//	}
//	printf("\n");
//}
//void bubblesort(int* a, int n)
//{
//	int i, j, t;
//	for ( i = 0; i < n; i++)
//	{
//		for ( j = 0; j < n-i-1; j++)
//		{
//			if (a[j]<a[j+1])
//			{
//				t = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = t;
//			}
//		}
//	}
//}