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
		appr();  //初始化后进行一次约分
	}
	void appr();  //约分
	long getNu() { return m_numerator; }
	long getDe() { return m_denominator; }
	void setNu(long nu) { m_numerator = nu; }
	void setDe(long de) { m_denominator = de; }


private:
	long m_numerator, m_denominator;  //分子和分母
};

class Rational: public Ration
{
public:
	Rational(long nu=0, long de=1):Ration(nu,de)  //分数的重载
	{
		toDec();
	}
	Rational(double rational, int looplength =0)  //小数的重载
	{
		m_looplength = looplength;
		m_dec = rational;
		toFrac();
	}
	Rational operator + (Rational r2);  //加法
	Rational operator - (Rational r2);  //减法
	Rational operator * (Rational r2);  //乘法
	Rational operator / (Rational r2);  //除法

	friend ostream& operator << (ostream& output, Rational &r);  //输出
	friend istream& operator >> (istream& input, Rational &r);  //输入

	void toDec();  //分数转小数
	void setDec(double dec) { m_dec = dec; }
	void setLoopLength(int lpl) { m_looplength = lpl; }
	double getDec() { return m_dec; }
	void toFrac();  //小数转分数

private:
	double m_dec;   //分数的小数形式
	int m_looplength;  //循环小数循环节的长度, 0表示不是循环小数
};


int main()
{
	int choice;
	do
	{
		cout
			<< "--有理数的四则运算--" << endl
			<< "1.重载流运算符以及分数约分功能测试" << endl
			<< "2.小数与分数转换功能测试" << endl
			<< "3.重载运算符功能测试" << endl
			<< "4.退出测试" << endl
			<< "请输入号码进行选择: ";
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			Rational r;
			cout
				<< "--重载流运算符功能测试--" << endl
				<< "请输入分数(例如:4/6),输入后系统会自动对其进行约分:" << endl;
			cin >> r;
			cout
				<< "您输入的分数的最简分数为:" << endl
				<< r << endl;
		}
		else if (choice == 2)
		{
			int looplength=0;
			cout
				<< "--小数与分数转换功能测试--" << endl;
			cout
				<< "请输入一个小数" << endl
				<< "例如:有限小数1.6 或者 循环小数1.333333,1(1代表循环节长度为1):" << endl;
			Rational r;
			cin >> r;
			cout << r;
		}
		else if (choice == 3)
		{
			Rational r1, r2, r3;
			cout
				<< "--重载运算符功能测试--" << endl
				<< "请输入r1: ";
			cin >> r1;
			cout
				<< "请输入r2: ";
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
			cout << "测试结束" << endl;
		}
		else
		{
			cout << "输入的号码错误! 请重新输入!" << endl;
		}
		cout << "按enter键继续...." << endl;
		getchar();
		getchar();
		system("cls");
	} while (choice != 4);
	

	

	return 0;
}

void Ration::appr()  //利用辗转相除法求最大公约数,并对分数进行约分
{
	long nu = getNu(), de = getDe();
	long t, orignal_nu = nu, orignal_de = de;
	while (de!=0)
	{
		t = nu % de;
		nu = de;
		de = t;
	}
	setNu(orignal_nu / nu), setDe(orignal_de / nu);  //将分子分母同时除于最大公约数
}

Rational Rational::operator+(Rational r2)  //重载+号
{
	Rational r3;
	r3.setDe(getDe() * r2.getDe());
	r3.setNu(getNu() * r2.getDe() + r2.getNu() * getDe());
	r3.appr();  //计算后进行约分
	return r3;
}

Rational Rational::operator-(Rational r2)  //重载-号
{
	Rational r3;
	r3.setDe(getDe() * r2.getDe());
	r3.setNu(getNu() * r2.getDe() - r2.getNu() * getDe());
	r3.appr();  //计算后进行约分
	return r3;
}

Rational Rational::operator*(Rational r2)  //重载*号
{
	Rational r3;
	r3.setDe(getDe() * r2.getDe());
	r3.setNu(getNu() * r2.getNu());
	r3.appr();  //计算后进行约分
	return r3;
}

Rational Rational::operator/(Rational r2)  //重载/号
{
	Rational r3;
	r3.setDe(getDe() * r2.getNu());
	r3.setNu(getNu() * r2.getDe());
	r3.appr();  //计算后进行约分
	return r3;
}

void Rational::toDec()
{
	double d_nu = (double)getNu();
	m_dec = d_nu / getDe();
}

void Rational::toFrac()  //思路:将小数当作分子化为整数, 分母乘于10^n
{
	double nu, de;

	de = 1.0;
	nu = m_dec;
	double nu_10 = nu;
	if (m_looplength != 0)  //循环节长度不为0, 为循环小数
	{
		//循环节长度为looplength，原小数a乘以10^looplength后再减去a可化为有限小数
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
		//if (fabs(floor(nu * de) - nu * de) < 1E-30)  //通过向下取整取出小数的整数部分, 直到小数点后数字全部跑到小数点之前
		if(fab<1E-30)
		{													//但由于浮点数存在误差, 故使用fabs双精度浮点绝对值函数判断误差
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

ostream& operator<<(ostream& output, Rational &r)  //重载cout<<
{
	int choice;
	output << r.getNu() << "/" << r.getDe() << endl;
	cout
		<< "是否显示小数形式?(1是 2否)" << endl
		<< "输入号码进行选择: ";
	cin >> choice;
	if (choice == 1)
	{
		r.toDec();
		cout << r.getDec() << endl;
	}
	// TODO: 在此处插入 return 语句
	return output;
}

istream& operator>>(istream& input, Rational &r)  //重载cin>>
{
	//三种情况:1.分数3/6  2.有限小数3.27  3.循环小数3.33333,1
	//long nu, de;
	double nu;  //分子或小数
	long de;  //分母或循环节长度
	char c;
	input >> nu;
	c = getchar();  //检测符号,若吸收/号,则实现输入5/7这样的分数形式,分别读取除5和7
	if (c != '\n')  //不为有限小数
	{
		input >> de;
	}
	else  //为有限小数
	{
		de = 0;
	}
	if (de == 0 && c == '/')
	{
		cout << "错误! 分母不能为0!!" << endl;
		exit(-1);
	}

	if (c == '/')  //若为分数
	{
		r.setNu((long)nu), r.setDe(de);
		r.toDec();
	}
	else  //若为小数
	{
		r.setDec(nu);
		r.setLoopLength(de);
		r.toFrac();
	}


	r.appr();
	// TODO: 在此处插入 return 语句
	return input;  //返回istream对象使得cin可以连续读入,例如cin>>r1>>r2>>r3;
}
