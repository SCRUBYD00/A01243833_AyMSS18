#include "Move Constructor.h"

int main()
{
	Foo a;
	Foo b(a);
	Foo c(returnFoo(a));

	int x;
	cin >> x;
	return 0;
}