#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <ctime>

using namespace std;

class Clock
{
private:
	static Clock* instance;
	Clock() {}

public:
	static Clock* getInstance()
	{
		if (instance == 0)
		{
			instance = new Clock;
		}

		return instance;
	}

	void getTime()
	{

	}
};

Clock* Clock::instance = 0;
#endif