#include <stdio.h>

int judge(int y, int m, int d)
{
	int i,sum=0;
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int sign = 0;//�ж��Ƿ�������ı�ʶ��
	sign = y % (y % 100 ? 4 : 400) ? 0 : 1;
	if (sign == 1)
		month[1] = 29;
	for (i = 0; i < m - 1; i++)
		sum += month[i];
	return (sum += d);
}
int main()
{
	int judge(int y, int m, int d);
	int y, m, d;//�� �� ��
	printf("��������,��,��:");
	scanf_s("%d%d%d", &y, &m, &d);
	printf("%d��,%d����%d��ĵ�%d��", m, d, y, judge(y, m, d));
	return 0;
}