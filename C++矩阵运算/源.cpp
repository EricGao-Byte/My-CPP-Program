#include <iostream>
#include <stdlib.h>
using namespace std;

const int MaxLength = 20;//采用C++const常量,运行效率更高

class Matrix//矩阵类
{
public:
	//输入和输出 行和列
	void InputRow(int);
	void InputColu(int);
	int GetRow() { return rows; }
	int GetColu() { return columns; }
	//输入和输出矩阵函数
	void InputMatrix();
	void PrintMatrix();
	//友元运算函数,方便直接访问数组
	friend void MatPlus(Matrix*, Matrix*, Matrix*);
	friend void MatSubs(Matrix*, Matrix*, Matrix*);
	friend void MatMutl(Matrix*, Matrix*, Matrix*);
	friend void MatCalcu();

private:
	double Max[MaxLength][MaxLength];//存放矩阵的二维数组
	int rows, columns;//矩阵的行数和列数
	bool flag;//矩阵是否可以计算的标志
};


int main()
{
	cout << "---计算181 高传金 3180811020--" << endl;
	cout << "----------矩阵计算器----------" << endl;
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
	cout << "请输入矩阵,元素间空格隔开,输完一行请按回车键换行" << endl;
	for (i = 0; i < MaxLength; i++)
	{
		for (j = 0; j < MaxLength; j++)
		{
			cin >> Max[i][j];
			if ((c = getchar()) == '\n')//检测换行符
			{
				if (columns == 0)
				{
					columns = j + 1;//由输入后遍历的数字个数得知一行有几个元素
				}
				break;
			}
		}
		if (i == rows - 1)
			break;
	}
	cout << "矩阵完成输入." << endl;
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


//==============运算部分=================
void MatPlus(Matrix* A, Matrix* B, Matrix* C)
{
	int r = A->GetRow(), c = A->GetColu();
	int i, j;

	//检验矩阵是否可以进行运算
	if (A->GetRow() == B->GetRow() && A->GetColu() == B->GetColu())
	{
		C->flag = true;
		//遍历数组进行运算
		for (i = 0; i < r; ++i)
			for (j = 0; j < c; ++j)
			{
				C->Max[i][j] = A->Max[i][j] + B->Max[i][j];
			}
	}
	else
	{
		C->flag = false;
		cout << "无法进行加法运算!" << endl;
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
		cout << "无法进行减法运算!" << endl;
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
					ret += A->Max[i][k] * B->Max[k][j];   //按照矩阵的乘法规则进行运算
				}
				C->Max[i][j] = ret;
			}
		}
	}
	else
	{
		C->flag = false;
		cout << "无法进行乘法运算" << endl;
	}


}

void MatCalcu()
{
	Matrix C1;
	Matrix* C = &C1;
	int sign;
	char ope;
	cout << "----------计算开始----------" << endl;
	do
	{
		int r;
		Matrix A1;
		cout << "第一个矩阵有几行? :" << endl;
		cin >> r;
		A1.InputRow(r);
		A1.InputMatrix();
		Matrix* A = &A1;
		Matrix B1;
		cout << "第二个矩阵有几行? :" << endl;
		cin >> r;
		B1.InputRow(r);
		B1.InputMatrix();
		Matrix* B = &B1;
		system("cls");
		do
		{
			cout << "输入 + 加法   - 减法   * 乘法"
				<< endl
				<< " 输入符号进行选择: ";
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
			//打印结果
			if (C->flag)//检测是否可以计算
			{
				A->PrintMatrix();
				cout << ope << endl;
				B->PrintMatrix();
				cout << "=" << endl;
				C->PrintMatrix();
			}
			cout << " 1 继续计算   2 换两个矩阵计算   3 结束计算" << endl;
			cin >> sign;
			system("cls");
		} while (sign == 1);
	} while (sign == 2);
	cout << "----------计算结束----------" << endl;
}