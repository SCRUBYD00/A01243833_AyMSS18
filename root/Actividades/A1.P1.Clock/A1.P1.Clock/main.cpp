#include "Clock.h"

int main()
{
	Clock* instance1 = Clock::getInstance();
	instance1->getTime();
	instance1->deleteInstance();

	int x;
	cin >> x;
	return 0;
}