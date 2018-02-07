#include <iostream>
using namespace std;

template <int n>
class Repeat : public Repeat<n - 1>
{
public:
	Repeat()
	{
		cout << n << " ";
	}
};

template <>
class Repeat <0>
{
public:
	Repeat()
	{
		cout << "0 ";
	}
};

int addition(int a, int b)
{
	return a + b;
}

int substraction(int a, int b)
{
	return a - b;
}

int operation(int a, int b, int(*f)(int, int))
{
	return f(a, b);
}

typedef int(*f)(int, int);

f getOperation(char o)
{
	if (o == 'r')
		return substraction;

	else
		return addition;
}

int(*getf(char o))(int a, int b)
{
	if (o == 'r')
		return substraction;

	else
		return addition;
}

template <class T, class Function>
T doTemplateFunction(T a, T b, Function F)
{
	return F(a, b);
}

template <class Function>
Function getTemplateOperation(char s)
{
	if (o == 'r')
		return substraction;

	else
		return addition;
}

int main()
{
	//Repeat<100> a;
	//cout << operation(2, 2, addition) << endl;
	//cout << operation(3, 1, substraction) << endl;
	cout << getOperation('s')(2, 2) << endl;
	cout << getf('s')(2, 2) << endl;
	cout << doTemplateFunction(2, 2,addition) << endl;

	int x;
	cin >> x;
	return 0;
}