#include <iostream>
#define X Complex
#define Y double
using namespace std;
class Complex
{
public:
	void input(Complex*);
	/*X add(X x, X y);*/
	void print(Complex*);
private:
	Y real, image;
};
int main()
{
	Complex* a;
	a->input;
	a->print;
	return 0;
}

void Complex::input(Complex* x)
{
	cin >> x->real;
	cin >> x->image;
}

//X Complex::add(X x, X y)
//{
//
//	return X();
//}

void Complex::print(Complex* x)
{
	if (x->image > 0)
		cout << x->real << "+" << x->image << endl;
	else
		cout << x->real << x->image << endl;
}
