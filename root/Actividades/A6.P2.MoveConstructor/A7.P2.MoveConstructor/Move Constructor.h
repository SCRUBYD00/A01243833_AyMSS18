#ifndef MOVE_CONSTRUCTOR
#define MOVE_CONSTRUCTOR

#include <iostream>

using namespace std;

class Foo
{
	int *pointer;

public:
	explicit Foo(int i = 0) :pointer(new int(i))
	{
		cout << "def/para" << endl;
	}

	Foo(const Foo& original)
	{
		pointer = new int(0);
		cout << "copy const" << endl;
	}

	Foo(Foo&& temporal)
	{
		swap(pointer, temporal.pointer);
		temporal.pointer = nullptr;
		cout << "move const" << endl;
	}

	~Foo()
	{
		delete pointer;
		cout << "dest" << endl;
	}
};

Foo returnFoo(Foo temp)
{
	return temp;
}
#endif
