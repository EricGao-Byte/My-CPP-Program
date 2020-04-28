#include <stdio.h>
#include <malloc.h>
#define M 100
#define N 10
#define len sizeof(list)
struct complex
{
	double real;
	double image;
};
struct list
{
	int num;
	list* next;
};
int main()
{
	//改写switch case
	//int c, s;
	//double p, w, d, f;
	//scanf_s("%f,%f,%d", &p, &w, &s);
	//if (s >= 3000)c = 12;
	//else c = s / 250;
	//if (c == 0)d = 0;
	//else if (c == 1)d = 2;
	//else if (c == 2 || c == 3)d = 5;
	//else if (c == 4 || c == 5 || c == 6 || c == 7)d = 8;
	//else if (c == 8 || c == 9 || c == 10 || c == 11)d = 10;
	//else d = 15;
	//f = p * w * s * (1 - d / 100);
	//printf("%10.2f", f);

	//逻辑运算符
	//int a, b, c, n;
	//int x, y;
	//scanf_s("%d%d%d", &a, &b, &c);
	//n = a || b + c && b - c;
	//n = !(a > b) && !c || 1;
	//n = !(x = a) && (y = b) && 0;
	//n = !(a + b) + c - 1 && b + c / 2;
	//printf("%d", n);


	//二维数组引用
	//int* p;
	//int(*ptr)[4];
	//int* b;
	//int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	//p = a[0];
	//ptr = a;
	//b = &a[0][0];
	//printf("%d ", a[1][2]);
	//printf("%d ", *(p + 6));
	//printf("%d ", *(*(ptr + 1) + 2));
	//printf("%d ", *(b + 6));

	//复数结构体
	/*void creat_complex(complex* x);
	void print_complex(complex* x);
	double mod_complex(complex * x);
	complex sum_complex(complex x1,complex x2);
	complex a, b, c;
	complex* p;
	p = &a;
	creat_complex(p);
	print_complex(p);
	printf("mod(%.2f+%.2fi)=%.2f\n", p->real, p->image, mod_complex(p));
	p = &b;
	creat_complex(p);
	print_complex(p);
	c = sum_complex(a, b);
	printf("%.2f+%.2fi + %.2f+%.2fi = %.2f+%.2fi", a.real, a.image, b.real, b.image, c.real, c.image)*/;


	//字符串操作
	/*void inputstring(char* s);
	void printstring(char* s);
	char* stringcpy(char* s1, char* s2);
	int stringlen(char* s);
	int stringcmp(char*, char*);
	char str1[M], str2[M];
	inputstring(str1);
	inputstring(str2);
	printstring(str1);
	printf("\n");
	printstring(str2);
	printf("\n");
	printf("str1lenth = %d,str2lenth = %d\n", stringlen(str1), stringlen(str2));
	printstring(stringcpy(str1, str2));
	printf("\n");
	printf("%d", stringcmp(str1, str2));*/

	//输出图形
	/*int n, i, j;
	printf("n=");
	scanf_s("%d", &n);
	while (n%2==0)
	{
		printf("n must be a odd number.\n");
		printf("n=");
		scanf_s("%d", &n);
	}*/
	/*for ( i = 1; i <= n;i++)
	{
		if (i > (n + 1) / 2)
		{
			for (j = 1; j <= ((n + 1) - i); j++)
				printf("*");
		}
		else
		{
			for (j = 1; j <= i; j++)
				printf("*");
		}
		printf("\n");
	}*/
	/*int m;
	m = (n + 1) / 2;
	for ( i = 1; i <= n; i++)
	{
		if (i > m)
		{
			for (j = 1; j <= (i - m + 1); j++)
				printf("*");
		}
		else
		{
			for (j = 1; j <= (m - i + 1); j++)
				printf("*");
		}
		printf("\n");
	}*/


	//冒泡排序
	/*void bubble_sort(int b[], int n);
	void select_sort(int b[], int n);
	int a[N];
	int i;
	for (i = 0; i < N; i++)
		scanf_s("%d", &a[i]);
	bubble_sort(a, N);
	select_sort(a, N);
	for (i = 0; i < N; i++)
		printf("%d ", a[i]);*/


	//链表相关操作
	list* create_list();
	list* creat_node();
	void rearinsert(list* head, list* n);
	void printlist(list* head);
	int listnum(list* head);
	void deletenode(list* head, int m);
	void insertlist(list* head, list* n, int m);
	void deletlist(list* head);
	void headinsert(list* head, list* n);
	list* head;
	list* node1, * node2, * node3, * node4;
	head = create_list();
	node1 = creat_node();
	headinsert(head, node1);
	//rearinsert(head, node1);
	node2 = creat_node();
	headinsert(head, node2);
	//rearinsert(head, node2);
	node3 = creat_node();
	headinsert(head, node3);
	//rearinsert(head, node3);
	node4 = creat_node();
	headinsert(head, node4);
	//rearinsert(head, node4);
	/*list* node5;
	node5 = creat_node();
	insertlist(head, node5, 2);*/
	deletenode(head, 3);
	printlist(head);
	deletlist(head);


	return 0;
}
void deletlist(list* head)
{
	list* p, * q;
	p = q = head;
	while (q!=NULL)
	{
		q = q->next;
		free(p);
		p = q;
	}
}
list* create_list()
{
	list* p;
	p = (list*)malloc(len);
	if (p == NULL)
		return NULL;
	p->num = 0;
	p->next = NULL;
	return p;
}
list* creat_node()
{
	list* n;
	n = (list*)malloc(len);
	if (n == NULL)
		return NULL;
	printf("enter a number:\n");
	scanf_s("%d", &n->num);
	n->next = NULL;
	return n;
}
void rearinsert(list* head, list* n)
{
	list* p;
	p = head;
	while (p->next != NULL)
		p = p->next;
	p->next = n;
}
void headinsert(list* head,list* n)
{
	n->next = head->next;
	head->next = n;
}
void printlist(list* head)
{
	list* p;
	p = head;
	printf("the list is:\n");
	while (p->next != NULL)
	{
		p = p->next;
		printf("%d ", p->num);
	}
}
int listnum(list* head)
{
	list* p;
	int i=0;
	p = head;
	while (p->next!=NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
void deletenode(list* head, int m)
{
	int listnum(list * head);
	list* p, * q;
	p = head;
	q = head->next;
	int i;
	if (listnum(head) == 0)
		printf("there is no list!");
	else
	{
		for (i = 1; i < m; i++)
		{
			p = p->next;
			q = q->next;
		}
		p->next = q->next;
		free(q);
	}
}
void insertlist(list* head, list* n, int m)
{
	int i;
	list* p, * q;
	p = head;
	q = head->next;
	for ( i = 1; i < m; i++)
	{
		p = p->next;
		q = q->next;
	}
	n->next = q;
	p->next = n;

}





//void select_sort(int b[], int n)
//{
//	int d;//记录下标
//	int i, j, t;
//	for ( i = 0; i < n; i++)
//	{
//		d = i;
//		for (j = 0; j < n - i; j++)
//		{
//			if (b[j] < b[d])//找出最小元素的坐标，并记录
//				d = j;
//		}
//		if (d != n-i-1)
//		{
//			t = b[d];
//			b[d] = b[n-i-1];
//			b[n-i-1] = t;
//		}
//	}
//}
//
//void bubble_sort(int b[],int n)
//{
//	int i, j, t;
//	for ( i = 0; i < n; i++)
//	{
//		for (j = 0; j < n-i-1; j++)
//		{
//			if (b[j] < b[j + 1])
//			{
//				t = b[j];
//				b[j] = b[j+1];
//				b[j + 1] = t;
//			}
//		}
//	}
//}
//
//
//
//void inputstring(char* s)
//{
//	printf("please input a string:\n");
//	while ((*s=getchar())!='\n')
//		s++;
//	*s = '\0';
//}
//void printstring(char* s)
//{
//	while (*s != '\0')
//	{
//		printf("%c", *s);
//		s++;
//	}
//		
//}
//char* stringcpy(char* s1, char* s2)
//{
//	char* p;
//	p = s1;
//	while (*s2 != '\0')
//	{
//		*s1 = *s2;
//		s1++;
//		s2++;
//	}
//	*s1 = '\0';
//	return p;
//}
//int stringlen(char* s)
//{
//	int l=0;
//	while (*s != '\0')
//	{
//		l++;
//		s++;
//	}
//	return l;
//}
//char* stringcat(char* s1, char* s2)
//{
//	int stringlen(char*);
//	char* p;
//	p = s1;
//	s1 += stringlen(s1);
//	while (*s2!='\0')
//	{
//		*s1 = *s2;
//		s1++;
//		s2++;
//	}
//	return p;
//}
//int stringcmp(char* s1, char* s2)
//{
//	int stringlen(char*);
//	while (*s1!='\0'&&*s2!='\0')
//	{
//		if (*s1 > * s2)
//			return 1;
//		if (*s1 < *s2)
//			return -1;
//		s1++;
//		s2++;
//	}
//	if (stringlen(s1) == stringlen(s2))
//		return 0;
//	if (stringlen(s1) > stringlen(s2))
//		return 1;
//	else return -1;
//}
//
//
//void creat_complex(complex* x)
//{
//	printf("inter the real part:\n");
//	scanf_s("%lf", &x->real);
//	printf("inter the image part:\n");
//	scanf_s("%lf", &x->image);
//}
//void print_complex(complex* x)
//{
//	printf("%.2lf+%.2lfi\n", x->real, x->image);
//}
//double mod_complex(complex* x)
//{
//	double power(double a, int n);
//	double sqrt(double a);
//	double m;
//	m = sqrt(power(x->real, 2) + power(x->image, 2));
//	return m;
//}
//complex sum_complex(complex x1,complex x2)
//{
//	complex sum;
//	sum.real = x1.real + x2.real;
//	sum.image = x1.image + x2.image;
//	return sum;
//}
//double power(double a, int n)
//{
//	int i;
//	double a0;
//	a0 = 1;
//	for ( i = 1; i <=n; i++)
//	{
//		a0 *= a;
//	}
//	return a0;
//}
//double sqrt(double a)
//{
//	int i;
//	double x;
//	x = a / 2;
//	for ( i = 0; i < 100; i++)
//		x = 0.5 * (x + a / x);
//	return x;
//}