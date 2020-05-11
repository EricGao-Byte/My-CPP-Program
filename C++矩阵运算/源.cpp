#include <iostream>
#include <stdlib.h>
using namespace std;

const int MaxLength = 20;//����C++const����,����Ч�ʸ���

class Matrix//������
{
public:
	//�������� �к���
	void InputRow(int);
	void InputColu(int);
	int GetRow() { return rows; }
	int GetColu() { return columns; }
	//��������������
	void InputMatrix();
	void PrintMatrix();
	//��Ԫ���㺯��,����ֱ�ӷ�������
	friend void MatPlus(Matrix*, Matrix*, Matrix*);
	friend void MatSubs(Matrix*, Matrix*, Matrix*);
	friend void MatMutl(Matrix*, Matrix*, Matrix*);
	friend void MatCalcu();

private:
	double Max[MaxLength][MaxLength];//��ž���Ķ�ά����
	int rows, columns;//���������������
	bool flag;//�����Ƿ���Լ���ı�־
};


int main()
{
	cout << "---����181 �ߴ��� 3180811020--" << endl;
	cout << "----------���������----------" << endl;
	void MatCalcu();
	MatCalcu();
	return 0;
}

void Matrix::InputRow(int r)
{
	rows = r;
}

void Matrix::InputColu(int c)
{
	columns = c;
}



void Matrix::InputMatrix()
{
	int i, j;
	char c;
	columns = 0;
	cout << "���������,Ԫ�ؼ�ո����,����һ���밴�س�������" << endl;
	for (i = 0; i < MaxLength; i++)
	{
		for (j = 0; j < MaxLength; j++)
		{
			cin >> Max[i][j];
			if ((c = getchar()) == '\n')//��⻻�з�
			{
				if (columns == 0)
				{
					columns = j + 1;//���������������ָ�����֪һ���м���Ԫ��
				}
				break;
			}
		}
		if (i == rows - 1)
			break;
	}
	cout << "�����������." << endl;
}

void Matrix::PrintMatrix()
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			cout << Max[i][j]
				<< " ";
		}
		cout << endl;
	}
}


//==============���㲿��=================
void MatPlus(Matrix* A, Matrix* B, Matrix* C)
{
	int r = A->GetRow(), c = A->GetColu();
	int i, j;

	//��������Ƿ���Խ�������
	if (A->GetRow() == B->GetRow() && A->GetColu() == B->GetColu())
	{
		C->flag = true;
		//���������������
		for (i = 0; i < r; ++i)
			for (j = 0; j < c; ++j)
			{
				C->Max[i][j] = A->Max[i][j] + B->Max[i][j];
			}
	}
	else
	{
		C->flag = false;
		cout << "�޷����мӷ�����!" << endl;
	}
}

void MatSubs(Matrix* A, Matrix* B, Matrix* C)
{

	int r = A->GetRow(), c = A->GetColu();
	int i, j;

	if (A->GetRow() == B->GetRow() && A->GetColu() == B->GetColu())
	{
		C->flag = true;
		for (i = 0; i < r; ++i)
			for (j = 0; j < c; ++j)
			{
				C->Max[i][j] = A->Max[i][j] - B->Max[i][j];
			}
	}
	else
	{
		C->flag = false;
		cout << "�޷����м�������!" << endl;
	}
}

void MatMutl(Matrix* A, Matrix* B, Matrix* C)
{
	if (A->GetRow() == B->GetColu() && A->GetColu() == B->GetRow())
	{
		C->flag = true;
		int i, j, k;
		double ret;
		for (i = 0; i < A->rows; i++)
		{
			for (j = 0; j < B->columns; j++)
			{
				ret = 0;
				for (k = 0; k < A->columns; k++)
				{
					ret += A->Max[i][k] * B->Max[k][j];   //���վ���ĳ˷������������
				}
				C->Max[i][j] = ret;
			}
		}
	}
	else
	{
		C->flag = false;
		cout << "�޷����г˷�����" << endl;
	}


}

void MatCalcu()
{
	Matrix C1;
	Matrix* C = &C1;
	int sign;
	char ope;
	cout << "----------���㿪ʼ----------" << endl;
	do
	{
		int r;
		Matrix A1;
		cout << "��һ�������м���? :" << endl;
		cin >> r;
		A1.InputRow(r);
		A1.InputMatrix();
		Matrix* A = &A1;
		Matrix B1;
		cout << "�ڶ��������м���? :" << endl;
		cin >> r;
		B1.InputRow(r);
		B1.InputMatrix();
		Matrix* B = &B1;
		system("cls");
		do
		{
			cout << "���� + �ӷ�   - ����   * �˷�"
				<< endl
				<< " ������Ž���ѡ��: ";
			cin >> ope;
			system("cls");
			if (ope == '+')
			{
				C->InputRow(A->GetRow());
				C->InputColu(A->GetColu());
				MatPlus(A, B, C);
			}
			else if (ope == '-')
			{
				C->InputRow(A->GetRow());
				C->InputColu(A->GetColu());
				MatSubs(A, B, C);
			}
			else if (ope == '*')
			{
				C->InputRow(A->GetRow());
				C->InputColu(B->GetColu());
				MatMutl(A, B, C);
			}
			//��ӡ���
			if (C->flag)//����Ƿ���Լ���
			{
				A->PrintMatrix();
				cout << ope << endl;
				B->PrintMatrix();
				cout << "=" << endl;
				C->PrintMatrix();
			}
			cout << " 1 ��������   2 �������������   3 ��������" << endl;
			cin >> sign;
			system("cls");
		} while (sign == 1);
	} while (sign == 2);
	cout << "----------�������----------" << endl;
}