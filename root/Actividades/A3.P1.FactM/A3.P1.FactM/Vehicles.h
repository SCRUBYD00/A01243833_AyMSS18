#ifndef VEHICLES_H
#define VEHICLES_H

#include <iostream>

using namespace std;

class Vehicle
{
public:
	virtual void assembly() = 0;
	virtual void paintjob() = 0;
	virtual void delivery() = 0;
	virtual void repair() = 0;
};

class Dodge : public Vehicle
{
public:
	void assembly()
	{
		cout << "Dodge assembly" << endl;
	}

	void paintjob()
	{
		cout << "Dodge paintjob" << endl;
	}

	void delivery()
	{
		cout << "Dodge delivery" << endl;
	}

	void repair()
	{
		cout << "Dodge repair" << endl;
	}
};

class BMW : public Vehicle
{
public:
	void assembly()
	{
		cout << "BMW assembly" << endl;
	}

	void paintjob()
	{
		cout << "BMW paintjob" << endl;
	}

	void delivery()
	{
		cout << "BMW delivery" << endl;
	}

	void repair()
	{
		cout << "BMW repair" << endl;
	}
};

class Volkswagen : public Vehicle
{
public:
	void assembly()
	{
		cout << "Volkswagen assembly" << endl;
	}

	void paintjob()
	{
		cout << "Volkswagen paintjob" << endl;
	}

	void delivery()
	{
		cout << "Volkswagen delivery" << endl;
	}

	void repair()
	{
		cout << "Volkswagen repair" << endl;
	}
};

class Nissan : public Vehicle
{
public:
	void assembly()
	{
		cout << "Nissan assembly" << endl;
	}

	void paintjob()
	{
		cout << "Nissan paintjob" << endl;
	}

	void delivery()
	{
		cout << "Nissan delivery" << endl;
	}

	void repair()
	{
		cout << "Nissan repair" << endl;
	}
};

class Creator
{
public:
	template <class Car>
	Car* factoryMethod()
	{
		return new Car;
	}

	template <class Car>
	Car* create()
	{
		Car* temp;
		temp = factoryMethod<Car>();
		temp->assembly();
		temp->paintjob();
		temp->delivery();
		temp->repair();
		return temp;
	}
};
#endif