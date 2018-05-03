#ifndef CLOCK_H
#define CLOCK_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>

using namespace std;

class Clock
{
private:
	time_t now;
	char* dt;

	static Clock* instance;
	Clock();
	~Clock();

public:
	void getTime();
	static Clock* getInstance();
	static Clock* deleteInstance();
};

Clock::Clock()
{
	now = time(0);
	dt = ctime(&now);
}

Clock:: ~Clock() {}

void Clock::getTime()
{
	cout << dt;
}

Clock* Clock::getInstance() 
{
	if (instance == 0) 
	{
		instance = new Clock;
	}
	return instance;
}

Clock* Clock::deleteInstance() 
{
	if (instance != NULL) 
	{
		delete instance;
		instance = NULL;
	}
	return instance;
}

Clock* Clock::instance = 0;
#endif