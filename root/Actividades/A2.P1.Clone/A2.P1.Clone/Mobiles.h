#ifndef MOBILES_H
#define MOBILES_H

#include <iostream>
#include <string>

using namespace std;

class Mobiles
{
protected:
	string* brand;
	string* model;
	string user;
	bool power;

public:
	virtual Mobiles* clone() = 0;

	Mobiles(){}

	bool turnOn(bool* status)
	{
		if (*status == 0)
		{
			cout << *brand << " device is turned ON." << endl;
			power = 1;
			return power;
		}

		else
		{
			cout << *brand << " device is already turned ON." << endl;
		}
	}

	bool turnOff(bool* status)
	{
		if (*status == 1)
		{
			cout << *brand << " device is turned OFF." << endl;
			power = 0;
			return power;
		}

		else
		{
			cout << *brand << " device is already turned OFF." << endl;
		}
	}

	void restart(bool* status)
	{
		if()
	}

	void reset()
	{

	}
};

template <class Subclass>
class CloneCRTP : public Mobiles 
{
public:
	Mobiles clone() 
	{
		return new Subclass(*this);
		return new dynamic_cast<Subclass&>(*this);
	}
};

class Tablet : public CloneCRTP<Tablet>
{
public:
	Tablet(const Tablet& temp)
	{

	}

	Mobiles* clone() {
		return new Tablet(*this);
	}
};

class Smartphone : public CloneCRTP<Smartphone>
{
public:
	Smartphone(const Smartphone& temp)
	{

	}

	Mobiles* clone() {
		return new Smartphone(*this);
	}
};

class Smartwatch : public CloneCRTP<Smartwatch>
{
public:
	Smartwatch(const Smartwatch& temp)
	{

	}

	Mobiles* clone() {
		return new Smartwatch(*this);
	}
};
#endif