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
	string version;

public:
	virtual Mobiles* clone() = 0;

	Mobiles(){}

	Mobiles(string brand, string model, string user, string version) : brand(new string(brand)), model(new string(model)), user(user), version(version)
	{

	}

	void turnOn()
	{
		cout << user << "'s device is on" << endl;
	}

	void turnOff()
	{
		cout << user << "'s device is off" << endl;
	}

	void restart()
	{
		cout << user << "'s device restarted" << endl;
	}

	void reset()
	{
		cout << user << "'s device reset" << endl;
	}
};

template <class Base, class Subclass>
class CloneCRTP : public Base 
{
public:
	Base* clone() 
	{
		return new Subclass(dynamic_cast<Subclass&>(*this));
	}
};

class Tablet : public CloneCRTP<Mobiles,Tablet>
{
public:
	Tablet(string b, string m, string u, string v)
	{
		brand = &b;
		model = &m;
		user = u;
		version = v;
	}

	Tablet(const Tablet& temp)
	{
		brand = temp.brand;
		model = temp.model;
		user = temp.user;
		version = temp.version;
	}

	Mobiles* clone() {
		return new Tablet(*this);
	}
};

class Smartphone : public CloneCRTP<Mobiles, Smartphone>
{
public:
	Smartphone(string b, string m, string u, string v)
	{
		brand = &b;
		model = &m;
		user = u;
		version = v;
	}

	Smartphone(const Smartphone& temp)
	{
		brand = temp.brand;
		model = temp.model;
		user = temp.user;
		version = temp.version;
	}

	Mobiles* clone() {
		return new Smartphone(*this);
	}
};

class Smartwatch : public CloneCRTP<Mobiles, Smartwatch>
{
public:
	Smartwatch(string b, string m, string u, string v)
	{
		brand = &b;
		model = &m;
		user = u;
		version = v;
	}

	Smartwatch(const Smartwatch& temp)
	{
		brand = temp.brand;
		model = temp.model;
		user = temp.user;
		version = temp.version;
	}

	Mobiles* clone() {
		return new Smartwatch(*this);
	}
};
#endif