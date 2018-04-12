#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Subject
{
private:
	vector <Observer*> subscribers;

public:
	void attach(Observer* sub)
	{
		subscribers.push_back(sub);
	}

	void detach(Observer* sub)
	{

	}

	void publish(string text)
	{
		cout << text << endl;
		notifyAll(text);
	}

	void notifyAll(string text)
	{
		for (int i = 0; i < subscribers.size(); i++)
			subscribers[i]->update(text);
	}
};

class Observer
{
private:
	string name;

public:
	Observer(string n)
	{
		name = n;
	}

	void update(string text)
	{
		cout<<name<<""
	}
};
#endif