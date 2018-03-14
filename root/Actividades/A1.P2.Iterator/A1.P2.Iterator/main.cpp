#include "Iterator.h"

int main()
{
	IntCollection* c = new IntArray;

	c->add(6);
	c->add(8);
	c->add(1);
	c->add(2);
	c->add(5);

	Iterator* i = c->getIterator();
	while (i->hasNext())
	{
		cout << i->next() << " ";
	}

	int x;
	cin >> x;

	return 0;
}