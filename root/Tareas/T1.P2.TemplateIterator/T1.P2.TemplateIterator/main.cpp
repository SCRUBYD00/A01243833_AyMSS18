#include "TemplateIterator.h"

int main()
{
	Collection<int>* c = new Array<int>;

	c->add(6);
	c->add(8);
	c->add(1);
	c->add(2);
	c->add(5);

	Iterator<int>* i = c->getIterator();
	while (i->hasNext())
	{
		cout << i->next() << " ";
	}

	int x;
	cin >> x;

	return 0;
}