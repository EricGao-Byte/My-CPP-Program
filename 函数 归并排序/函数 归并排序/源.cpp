#include <stdio.h>
#include <limits.h>
#define N 15 //����Ҫ������������

//�鲢�������Demo

//�鲢������
int* Merge_Sort(int n, int nums[])
{
	//������ʱ�洢��������飬���������ڽ������ֻḴ�����
	int nums_temp[N + 1];
	int u, i, m, x, y, j;
	//���ѭ�������������������
	for (u = 1; u < n; u *= 2)
	{
		//����ʱ����������±���㣬���ص���һ��Ԫ��
		m = 0;
		//�ڲ�ѭ�������Ƹ�����бȽ�
		for (i = 0; i < n; i = i + u * 2)
		{
			x = 0;
			y = 0;
			//������й鲢������һ��Ԫ��Ϊ��ʱ�����鲢
			while (x < u && y < u && i + x < n && i + u + y < n)
			{
				//�ж�Ԫ�ش�С��С��Ԫ����ǰ��ͬʱ�ƶ���ʱ�����±�
				if (nums[i + x] > nums[i + u + y])
				{
					nums_temp[m] = nums[i + u + y];
					y++;
					m++;
				}
				else
				{
					nums_temp[m] = nums[i + x];
					x++;
					m++;
				}
			}
			//�ж���������Ԫ�أ�������Ԫ�ع鲢������Ԫ�ؼ�����֮�����һ������Ҫ�Ƚϵ�Ԫ�أ�
			if (x == u)
			{
				for (j = y; j < u; j++)
				{
					nums_temp[m] = nums[i + u + j];
					m++;
				}
			}
			else
			{
				for (j = x; j < u; j++)
				{
					nums_temp[m] = nums[i + j];
					m++;
				}
			}
		}
		//����ʱ�����Ԫ�ظ��ƻ�ԭ���飬ע�����ﲻ��ֱ�ӵ���
		for (i = 0; i < n; i++)
		{
			nums[i] = nums_temp[i];
		}
	}
	//��������õ�����
	return nums;
}

int main(int argc, char const* argv[])
{
	//Ҫ�������������
	int nums[N] = { 3,4,-9,0,4,5,4,2,9,23,22,20,45,-10 };
	int i;
	//���ù鲢������
	int* p = Merge_Sort(N, nums);
	//ѭ����������ʵ�ʸ���������������ӵ�Ԫ�ؾͱ�������
	for (i = 0; i < N; i++)
	{
		printf("%d ", p[i]);
	}
	return 0;
}