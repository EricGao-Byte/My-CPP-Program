#include <stdio.h>
#define	N 100
int main()
{
	void statis_string(char* str1, int* capi, int* low, int* spa, int* num, int* oth);
	int capital, lowercase, space, number, others;
	int* capi, * low, * spa, * num, * oth;
	capi = &capital, low = &lowercase, spa = &space, num = &number, oth = &others;
	char str[N];
	printf("��������Ҫͳ�Ƶ�Ӣ�Ķ���:\n");
	gets_s(str, N);
	statis_string(str, capi, low, spa, num, oth);
	printf("���Ӣ�Ķ����ͳ����ϢΪ:\n");
	printf("��д��ĸ:%d\nСд��ĸ:%d\n�ո�:%d\n����:%d\n�����ַ�:%d\n", capital, lowercase, space, number, others);
	return 0;
}
void statis_string(char* str1, int* capi, int* low, int* spa, int* num, int* oth)
{
	int i;
	int capital, lowercase, space, number, others;
	capital = lowercase = space = number = others = 0;
	for ( i = 0; *(str1+i)!='\0' ; i++)
	{
		if ((*(str1 + i) >= 'A' && *(str1 + i) <= 'Z'))
			capital++;
		else if ((*(str1 + i) >= 'a' && *(str1 + i) <= 'z'))
			lowercase++;
		else if (*(str1+i) >= '0' && *(str1+i) <= '9')
			number++;
		else if (*(str1+i) == ' ')
			space++;
		else others++;
	}
	*capi = capital, * low = lowercase, * spa = space, * num = number, * oth = others;
}