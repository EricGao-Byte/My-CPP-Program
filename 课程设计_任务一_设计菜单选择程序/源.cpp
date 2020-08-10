#include <iostream>
#include <stdlib.h>
using namespace std;
const int MAX_LENGTH = 10;
class Menu
{
public:
	void show();  //显示菜单
	void countWords();  //统计文章单词数

};

class LinearEquation
{
public:
	void calLinearEquations();  //求解线性方程组
	void inputRow(int);  //输入和输出 行和列
	void inputColu(int);
	int getRow() { return m_rows; }
	int getColu() { return m_columns; }
	void inputMatrix();  //输入和输出矩阵函数
	void printMatrix();
	//--行列式相关函数--
	void transRow(int, int, int);  //执行两行的初等变换的数组
	double calDet();   //将行列式对角线相乘
	void swapRow(int, int);  //交换行列式的某两行
	void switchColu(int);  //将行列式某一列变换为结果向量
private:
	double D[MAX_LENGTH][MAX_LENGTH] = { 0 }; //存放系数行列式的二维数组
	double temp[MAX_LENGTH][MAX_LENGTH] = { 0 };  //列转换中转矩阵
	double B[MAX_LENGTH] = { 0 };  //存放每行结果向量的数组
	double result[MAX_LENGTH] = { 0 };  //存放线性方程最终结果的向量
	int m_rows = 0, m_columns = 0;  //矩阵的行数和列数
	bool m_minus_sign = false;  //行列式前是否有负号
};
int main()
{
	Menu menu;
	menu.show();
	return 0;
}

void Menu::show()
{
	int flag = 0;  //菜单选项变量
	do
	{
		//--主菜单界面
		cout << "----------课程设计_菜单程序----------"
			<< endl
			<< endl
			<< "1) 求解线性方程组" << endl
			<< "2) 统计一篇英文文章的单词数" << endl
			<< "3) 退出程序" << endl
			<< "请输入数字进行选择: ";
		cin >> flag;
		system("cls");

		//--选项处理
		if (flag == 1)
		{
			LinearEquation le;
			le.calLinearEquations();
			system("cls");
		}
		else if(flag == 2)
		{
			countWords();
			system("cls");
		}
		else if(flag == 3)
		{

		}
		else
		{
			cout << "输入的数字有误! 请重新输入!" << endl;
		}

	} while (flag!=3);  //当选项为3时,跳出循环停止程序
	cout << "程序结束......";
}

void LinearEquation::calLinearEquations()
{
	int r;
	int i, j;
	double Det;
	int n = 0;
	cout << "----------求解线性方程组----------"
		<< endl
		<< endl;
	//1.用户输入线性方程组,并将方程组的系数行列式存入二维数组D,将方程组每行结果存入一维数组B;

	cout << "进行计算的线性方程组有几行?" << endl;
	cin >> r;
	inputRow(r);  //输入行列式有几行
	cout << "请输入系数行列式,元素间空格隔开,输完一行请按回车键换行." << endl;
	inputMatrix();  //输入行列式
	//PrintMatrix();
	cout << "请输入线性方程组每行的结果,结果间空格隔开." << endl;
	for (i = 0; i < r; i++)
	{
		cin >> B[i];  //输入每行结果,存入B结果数组中
	}
	/*for (i = 0; i < r; i++)
	{
		cout << B[i]<< endl;
	}*/

	//2.根据二维数组分别计算D,D1,D2...Dn的值,从而得出计算结果
	//2.1计算二维数组D后,将D转换为D1,计算出D1;再将D1转换为D2,计算出D2;以此类推直到计算出Dn为止.
	//如何计算行列式?将一个矩阵经过初等行变换化为上三角矩阵。
	for (i = 0; i < m_rows; i++)
	{
		for (j = 0; j < m_columns; j++)
		{
			temp[i][j] = D[i][j];  //复制一份系数行列式数组,方便D转换为D1,D2...Dn
		}
	}

	do
	{
		for (i = 0; i < m_rows; i++)
		{
			for (j = i + 1; j < m_rows; j++)
			{
				//cout << "r1=" << i << "r2=" << j << "c=" << i << endl;
				transRow(i, j, i);  //对i和j进行初等变换,从而化行列式为上上交
				//printMatrix();
				//cout << endl;
			}
		}

		if (n == 0)
		{
			Det = calDet();  //计算上三角行列式的值
		}
		else
		{
			cout << "x" << n << "=" << calDet() / Det << " ";
			//cout << endl;
		}
		switchColu(n);  //通过列变换将D分别转换为D1,D2...Dn
		n++;
	} while (n <= m_columns);

	//printMatrix();
	//cout << "|D|=" << calDet() << endl;
	cout << endl;
	cout << "敲回车继续....." << endl;
	getchar();
	getchar();
}

void LinearEquation::inputRow(int r)
{
	m_rows = r;
}

void LinearEquation::inputColu(int c)
{
	m_columns = c;
}

void LinearEquation::inputMatrix()
{
	int i, j;
	char c;
	m_columns = 0;
	bool isDet = true;
	//cout << "请输入矩阵,元素间空格隔开,输完一行请按回车键换行" << endl;
	do
	{
		for (i = 0; i < MAX_LENGTH; i++)
		{
			for (j = 0; j < MAX_LENGTH; j++)
			{
				cin >> D[i][j];
				if ((c = getchar()) == '\n')//检测换行符
				{
					m_columns = j + 1;//由输入后遍历的数字个数得知一行有几个元素
					break;
				}
			}
			isDet = true;
			if (m_columns != m_rows)  //行列式合法性检测(克莱姆法则要求系数矩阵必须为n*n)
			{
				m_columns = 0;
				cout << "行列式不合法! 系数矩阵应该为n*n,请检查输入的元素是否有误." << endl;
				cout << "请重新输入" << endl;
				isDet = false;
				break;
			}
			if (i == m_rows - 1)
				break;
		}
	} while (!isDet);

	cout << "行列式完成输入." << endl;
}

void LinearEquation::printMatrix()
{
	int i, j;
	for (i = 0; i < m_rows; i++)
	{
		for (j = 0; j < m_columns; j++)
		{
			cout << D[i][j]
				<< " ";
		}
		cout << endl;
	}
}

void LinearEquation::transRow(int r1, int r2, int c)
{
	int i;
	if (D[r1][c] == 0)
	{
		swapRow(r1, r2);  // 若第一行头部为0,则交换两行
	}
	if (D[r2][c] != 0)  //若下一行头部为0,则不进行初等变换
	{
		double multiple = 0;  //两行之间的倍数

		multiple = -(D[r2][c] / D[r1][c]);

		for (i = 0; i < m_columns; i++)
		{
			D[r2][i] += D[r1][i] * multiple;  //将下一行加上上一行的倍数
		}
	}

}

double LinearEquation::calDet()
{
	int i;
	double Det = 1;
	for (i = 0; i < m_rows; i++)
	{
		Det *= D[i][i];  //将行列式对角线相乘
	}
	if (m_minus_sign == true)
	{
		Det = -Det;
	}
	m_minus_sign = false;  //用完后负号要还原
	return Det;
}

void LinearEquation::swapRow(int r1, int r2)
{
	double temp[MAX_LENGTH];
	int i;
	for (i = 0; i < m_columns; i++)
	{
		temp[i] = D[r1][i];
		D[r1][i] = D[r2][i];
		D[r2][i] = temp[i];
	}
	//行列式两行交换,要变号
	m_minus_sign = !m_minus_sign;  //将行列式前面符号反号
}

void LinearEquation::switchColu(int c)
{
	int i, j;
	for (i = 0; i < m_rows; i++)
	{
		for (j = 0; j < m_columns; j++)
		{
			D[i][j] = temp[i][j];
		}
	}
	for (i = 0; i < m_rows; i++)
	{
		D[i][c] = B[i];
	}
}

void Menu::countWords()
{
	int a = 0; 
	char c;
	int capital = 0, lowercase = 0, number = 0, space = 0, others = 0;
	cout << "----------统计英文文章单词数----------" 
		<< endl
		<<endl
		<< "请输入或者黏贴文章(输入完成后敲>键并回车来结束输入):" << endl;
	getchar();
	for (;;)
	{
		c = getchar();  //从字符流从顺序读取字符
		/*if (c == '\n')
		{
			int flag;
			cout << "1 继续   2 终止" << endl;
			cin >> flag;
			if (flag == 2)
			{
				break;
			}
		}
		else */
		if (c == '>')  //>作为结束标志,通过break结束循环
		{
			break;
		}
		else if ((c >= 'A' && c <= 'Z'))  //大写
		{
			capital++;
		}
		else if ((c >= 'a' && c <= 'z'))  //小写
			lowercase++;
		else if (c >= '0' && c <= '9')  //数字
			number++;
		else if (c == ' ')  //空格
			space++;
		else others++;
	}
	getchar();
	cout << "这篇文章的单词数有: " << capital + lowercase << endl;
	cout << "输入任意一个字符查看统计的详细信息 或者 敲回车结束统计...." << endl;
	c = getchar();
	if (c != '\n')
	{
		cout << "大写字母: " << capital << endl
			<< "小写字母: " << lowercase << endl
			<< "数字: " << number << endl
			<< "空格: " << space << endl
			<< "其他字符: " << others-1 << endl;
		cout << "敲回车继续...." << endl;
		getchar();  //吸收上一个getchar的回车
		getchar();
	}
}
