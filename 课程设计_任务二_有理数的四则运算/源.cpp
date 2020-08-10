#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Ration
{	
public:
	Ration(long nu = 0, long de = 1)
	{
		m_numerator = nu, m_denominator = de;
		appr();  //��ʼ�������һ��Լ��
	}
	void appr();  //Լ��
	long getNu() { return m_numerator; }
	long getDe() { return m_denominator; }
	void setNu(long nu) { m_numerator = nu; }
	void setDe(long de) { m_denominator = de; }


private:
	long m_numerator, m_denominator;  //���Ӻͷ�ĸ
};

class Rational: public Ration
{
public:
	Rational(long nu=0, long de=1):Ration(nu,de)  //����������
	{
		toDec();
	}
	Rational(double rational, int looplength =0)  //С��������
	{
		m_looplength = looplength;
		m_dec = rational;
		toFrac();
	}
	Rational operator + (Rational r2);  //�ӷ�
	Rational operator - (Rational r2);  //����
	Rational operator * (Rational r2);  //�˷�
	Rational operator / (Rational r2);  //����

	friend ostream& operator << (ostream& output, Rational &r);  //���
	friend istream& operator >> (istream& input, Rational &r);  //����

	void toDec();  //����תС��
	void setDec(double dec) { m_dec = dec; }
	void setLoopLength(int lpl) { m_looplength = lpl; }
	double getDec() { return m_dec; }
	void toFrac();  //С��ת����

private:
	double m_dec;   //������С����ʽ
	int m_looplength;  //ѭ��С��ѭ���ڵĳ���, 0��ʾ����ѭ��С��
};


int main()
{
	int choice;
	do
	{
		cout
			<< "--����������������--" << endl
			<< "1.������������Լ�����Լ�ֹ��ܲ���" << endl
			<< "2.С�������ת�����ܲ���" << endl
			<< "3.������������ܲ���" << endl
			<< "4.�˳�����" << endl
			<< "������������ѡ��: ";
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			Rational r;
			cout
				<< "--��������������ܲ���--" << endl
				<< "���������(����:4/6),�����ϵͳ���Զ��������Լ��:" << endl;
			cin >> r;
			cout
				<< "������ķ�����������Ϊ:" << endl
				<< r << endl;
		}
		else if (choice == 2)
		{
			int looplength=0;
			cout
				<< "--С�������ת�����ܲ���--" << endl;
			cout
				<< "������һ��С��" << endl
				<< "����:����С��1.6 ���� ѭ��С��1.333333,1(1����ѭ���ڳ���Ϊ1):" << endl;
			Rational r;
			cin >> r;
			cout << r;
		}
		else if (choice == 3)
		{
			Rational r1, r2, r3;
			cout
				<< "--������������ܲ���--" << endl
				<< "������r1: ";
			cin >> r1;
			cout
				<< "������r2: ";
			cin >> r2;

			r3 = r1 + r2;
			cout << "r1 + r2 = " << r3 << endl;
			r3 = r1 - r2;
			cout << "r1 - r2 = " << r3 << endl;
			r3 = r1 * r2;
			cout << "r1 * r2 = " << r3 << endl;
			r3 = r1 / r2;
			cout << "r1 / r2 = " << r3 << endl;
		}
		else if (choice == 4)
		{
			cout << "���Խ���" << endl;
		}
		else
		{
			cout << "����ĺ������! ����������!" << endl;
		}
		cout << "��enter������...." << endl;
		getchar();
		getchar();
		system("cls");
	} while (choice != 4);
	

	

	return 0;
}

void Ration::appr()  //����շת����������Լ��,���Է�������Լ��
{
	long nu = getNu(), de = getDe();
	long t, orignal_nu = nu, orignal_de = de;
	while (de!=0)
	{
		t = nu % de;
		nu = de;
		de = t;
	}
	setNu(orignal_nu / nu), setDe(orignal_de / nu);  //�����ӷ�ĸͬʱ�������Լ��
}

Rational Rational::operator+(Rational r2)  //����+��
{
	Rational r3;
	r3.setDe(getDe() * r2.getDe());
	r3.setNu(getNu() * r2.getDe() + r2.getNu() * getDe());
	r3.appr();  //��������Լ��
	return r3;
}

Rational Rational::operator-(Rational r2)  //����-��
{
	Rational r3;
	r3.setDe(getDe() * r2.getDe());
	r3.setNu(getNu() * r2.getDe() - r2.getNu() * getDe());
	r3.appr();  //��������Լ��
	return r3;
}

Rational Rational::operator*(Rational r2)  //����*��
{
	Rational r3;
	r3.setDe(getDe() * r2.getDe());
	r3.setNu(getNu() * r2.getNu());
	r3.appr();  //��������Լ��
	return r3;
}

Rational Rational::operator/(Rational r2)  //����/��
{
	Rational r3;
	r3.setDe(getDe() * r2.getNu());
	r3.setNu(getNu() * r2.getDe());
	r3.appr();  //��������Լ��
	return r3;
}

void Rational::toDec()
{
	double d_nu = (double)getNu();
	m_dec = d_nu / getDe();
}

void Rational::toFrac()  //˼·:��С���������ӻ�Ϊ����, ��ĸ����10^n
{
	double nu, de;

	de = 1.0;
	nu = m_dec;
	double nu_10 = nu;
	if (m_looplength != 0)  //ѭ���ڳ��Ȳ�Ϊ0, Ϊѭ��С��
	{
		//ѭ���ڳ���Ϊlooplength��ԭС��a����10^looplength���ټ�ȥa�ɻ�Ϊ����С��
		int i;
		double dec = m_dec;
		for ( i = 0; i < m_looplength; i++)
		{
			dec *= 10;
			de *= 10;
		}
		nu = ceil(dec - m_dec);
		de -= 1;
	}

	while (true) 
	{
		double fl = floor(nu * de);
		double diff = fl - nu * de;
		double fab = fabs(diff);
		//if (fabs(floor(nu * de) - nu * de) < 1E-30)  //ͨ������ȡ��ȡ��С������������, ֱ��С���������ȫ���ܵ�С����֮ǰ
		if(fab<1E-30)
		{													//�����ڸ������������, ��ʹ��fabs˫���ȸ������ֵ�����ж����
			break;
		}
		de = de * 10;
		nu_10 *= 10;
	}
	if (m_looplength == 0)
	{
		nu = nu_10;
	}

	setNu((long)nu), setDe((long)de);
	appr();
}

ostream& operator<<(ostream& output, Rational &r)  //����cout<<
{
	int choice;
	output << r.getNu() << "/" << r.getDe() << endl;
	cout
		<< "�Ƿ���ʾС����ʽ?(1�� 2��)" << endl
		<< "����������ѡ��: ";
	cin >> choice;
	if (choice == 1)
	{
		r.toDec();
		cout << r.getDec() << endl;
	}
	// TODO: �ڴ˴����� return ���
	return output;
}

istream& operator>>(istream& input, Rational &r)  //����cin>>
{
	//�������:1.����3/6  2.����С��3.27  3.ѭ��С��3.33333,1
	//long nu, de;
	double nu;  //���ӻ�С��
	long de;  //��ĸ��ѭ���ڳ���
	char c;
	input >> nu;
	c = getchar();  //������,������/��,��ʵ������5/7�����ķ�����ʽ,�ֱ��ȡ��5��7
	if (c != '\n')  //��Ϊ����С��
	{
		input >> de;
	}
	else  //Ϊ����С��
	{
		de = 0;
	}
	if (de == 0 && c == '/')
	{
		cout << "����! ��ĸ����Ϊ0!!" << endl;
		exit(-1);
	}

	if (c == '/')  //��Ϊ����
	{
		r.setNu((long)nu), r.setDe(de);
		r.toDec();
	}
	else  //��ΪС��
	{
		r.setDec(nu);
		r.setLoopLength(de);
		r.toFrac();
	}


	r.appr();
	// TODO: �ڴ˴����� return ���
	return input;  //����istream����ʹ��cin������������,����cin>>r1>>r2>>r3;
}
