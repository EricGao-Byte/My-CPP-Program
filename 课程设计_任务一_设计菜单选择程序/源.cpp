#include <iostream>
#include <stdlib.h>
using namespace std;
const int MAX_LENGTH = 10;
class Menu
{
public:
	void show();  //��ʾ�˵�
	void countWords();  //ͳ�����µ�����

};

class LinearEquation
{
public:
	void calLinearEquations();  //������Է�����
	void inputRow(int);  //�������� �к���
	void inputColu(int);
	int getRow() { return m_rows; }
	int getColu() { return m_columns; }
	void inputMatrix();  //��������������
	void printMatrix();
	//--����ʽ��غ���--
	void transRow(int, int, int);  //ִ�����еĳ��ȱ任������
	double calDet();   //������ʽ�Խ������
	void swapRow(int, int);  //��������ʽ��ĳ����
	void switchColu(int);  //������ʽĳһ�б任Ϊ�������
private:
	double D[MAX_LENGTH][MAX_LENGTH] = { 0 }; //���ϵ������ʽ�Ķ�ά����
	double temp[MAX_LENGTH][MAX_LENGTH] = { 0 };  //��ת����ת����
	double B[MAX_LENGTH] = { 0 };  //���ÿ�н������������
	double result[MAX_LENGTH] = { 0 };  //������Է������ս��������
	int m_rows = 0, m_columns = 0;  //���������������
	bool m_minus_sign = false;  //����ʽǰ�Ƿ��и���
};
int main()
{
	Menu menu;
	menu.show();
	return 0;
}

void Menu::show()
{
	int flag = 0;  //�˵�ѡ�����
	do
	{
		//--���˵�����
		cout << "----------�γ����_�˵�����----------"
			<< endl
			<< endl
			<< "1) ������Է�����" << endl
			<< "2) ͳ��һƪӢ�����µĵ�����" << endl
			<< "3) �˳�����" << endl
			<< "���������ֽ���ѡ��: ";
		cin >> flag;
		system("cls");

		//--ѡ���
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
			cout << "�������������! ����������!" << endl;
		}

	} while (flag!=3);  //��ѡ��Ϊ3ʱ,����ѭ��ֹͣ����
	cout << "�������......";
}

void LinearEquation::calLinearEquations()
{
	int r;
	int i, j;
	double Det;
	int n = 0;
	cout << "----------������Է�����----------"
		<< endl
		<< endl;
	//1.�û��������Է�����,�����������ϵ������ʽ�����ά����D,��������ÿ�н������һά����B;

	cout << "���м�������Է������м���?" << endl;
	cin >> r;
	inputRow(r);  //��������ʽ�м���
	cout << "������ϵ������ʽ,Ԫ�ؼ�ո����,����һ���밴�س�������." << endl;
	inputMatrix();  //��������ʽ
	//PrintMatrix();
	cout << "���������Է�����ÿ�еĽ��,�����ո����." << endl;
	for (i = 0; i < r; i++)
	{
		cin >> B[i];  //����ÿ�н��,����B���������
	}
	/*for (i = 0; i < r; i++)
	{
		cout << B[i]<< endl;
	}*/

	//2.���ݶ�ά����ֱ����D,D1,D2...Dn��ֵ,�Ӷ��ó�������
	//2.1�����ά����D��,��Dת��ΪD1,�����D1;�ٽ�D1ת��ΪD2,�����D2;�Դ�����ֱ�������DnΪֹ.
	//��μ�������ʽ?��һ�����󾭹������б任��Ϊ�����Ǿ���
	for (i = 0; i < m_rows; i++)
	{
		for (j = 0; j < m_columns; j++)
		{
			temp[i][j] = D[i][j];  //����һ��ϵ������ʽ����,����Dת��ΪD1,D2...Dn
		}
	}

	do
	{
		for (i = 0; i < m_rows; i++)
		{
			for (j = i + 1; j < m_rows; j++)
			{
				//cout << "r1=" << i << "r2=" << j << "c=" << i << endl;
				transRow(i, j, i);  //��i��j���г��ȱ任,�Ӷ�������ʽΪ���Ͻ�
				//printMatrix();
				//cout << endl;
			}
		}

		if (n == 0)
		{
			Det = calDet();  //��������������ʽ��ֵ
		}
		else
		{
			cout << "x" << n << "=" << calDet() / Det << " ";
			//cout << endl;
		}
		switchColu(n);  //ͨ���б任��D�ֱ�ת��ΪD1,D2...Dn
		n++;
	} while (n <= m_columns);

	//printMatrix();
	//cout << "|D|=" << calDet() << endl;
	cout << endl;
	cout << "�ûس�����....." << endl;
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
	//cout << "���������,Ԫ�ؼ�ո����,����һ���밴�س�������" << endl;
	do
	{
		for (i = 0; i < MAX_LENGTH; i++)
		{
			for (j = 0; j < MAX_LENGTH; j++)
			{
				cin >> D[i][j];
				if ((c = getchar()) == '\n')//��⻻�з�
				{
					m_columns = j + 1;//���������������ָ�����֪һ���м���Ԫ��
					break;
				}
			}
			isDet = true;
			if (m_columns != m_rows)  //����ʽ�Ϸ��Լ��(����ķ����Ҫ��ϵ���������Ϊn*n)
			{
				m_columns = 0;
				cout << "����ʽ���Ϸ�! ϵ������Ӧ��Ϊn*n,���������Ԫ���Ƿ�����." << endl;
				cout << "����������" << endl;
				isDet = false;
				break;
			}
			if (i == m_rows - 1)
				break;
		}
	} while (!isDet);

	cout << "����ʽ�������." << endl;
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
		swapRow(r1, r2);  // ����һ��ͷ��Ϊ0,�򽻻�����
	}
	if (D[r2][c] != 0)  //����һ��ͷ��Ϊ0,�򲻽��г��ȱ任
	{
		double multiple = 0;  //����֮��ı���

		multiple = -(D[r2][c] / D[r1][c]);

		for (i = 0; i < m_columns; i++)
		{
			D[r2][i] += D[r1][i] * multiple;  //����һ�м�����һ�еı���
		}
	}

}

double LinearEquation::calDet()
{
	int i;
	double Det = 1;
	for (i = 0; i < m_rows; i++)
	{
		Det *= D[i][i];  //������ʽ�Խ������
	}
	if (m_minus_sign == true)
	{
		Det = -Det;
	}
	m_minus_sign = false;  //����󸺺�Ҫ��ԭ
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
	//����ʽ���н���,Ҫ���
	m_minus_sign = !m_minus_sign;  //������ʽǰ����ŷ���
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
	cout << "----------ͳ��Ӣ�����µ�����----------" 
		<< endl
		<<endl
		<< "����������������(������ɺ���>�����س�����������):" << endl;
	getchar();
	for (;;)
	{
		c = getchar();  //���ַ�����˳���ȡ�ַ�
		/*if (c == '\n')
		{
			int flag;
			cout << "1 ����   2 ��ֹ" << endl;
			cin >> flag;
			if (flag == 2)
			{
				break;
			}
		}
		else */
		if (c == '>')  //>��Ϊ������־,ͨ��break����ѭ��
		{
			break;
		}
		else if ((c >= 'A' && c <= 'Z'))  //��д
		{
			capital++;
		}
		else if ((c >= 'a' && c <= 'z'))  //Сд
			lowercase++;
		else if (c >= '0' && c <= '9')  //����
			number++;
		else if (c == ' ')  //�ո�
			space++;
		else others++;
	}
	getchar();
	cout << "��ƪ���µĵ�������: " << capital + lowercase << endl;
	cout << "��������һ���ַ��鿴ͳ�Ƶ���ϸ��Ϣ ���� �ûس�����ͳ��...." << endl;
	c = getchar();
	if (c != '\n')
	{
		cout << "��д��ĸ: " << capital << endl
			<< "Сд��ĸ: " << lowercase << endl
			<< "����: " << number << endl
			<< "�ո�: " << space << endl
			<< "�����ַ�: " << others-1 << endl;
		cout << "�ûس�����...." << endl;
		getchar();  //������һ��getchar�Ļس�
		getchar();
	}
}
