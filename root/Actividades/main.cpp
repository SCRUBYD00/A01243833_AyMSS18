#include "Clock.h"

int main() 
{
	Clock* instance1 = Clock::getInstance();
	Clock::getInstance();
	Clock* instance2 = Clock::getInstance();
	Clock::getInstance();

	cout << instance1 << endl;
	cout << instance2 << endl;
	
	int x;
	cin >> x;
	return 0;
}