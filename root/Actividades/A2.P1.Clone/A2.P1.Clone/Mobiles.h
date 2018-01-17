#ifndef MOBILES_H
#define MOBILES_H

#include <iostream>
#include <string>

using namespace std;

class Mobiles
{
protected:
	int* power;
	string* user;
	string marca;
	string model;

public:
	virtual Mobiles* clone() = 0;

	bool encender(int* status)
	{

	}

	bool apagar(int* status)
	{

	}

	void reinicia()
	{

	}

	void restaurar()
	{

	}
};

class Tablet : public Mobiles
{
public:
	Tablet(const Tablet& temp)
	{

	}

	Mobiles* clone() {
		return new Tablet(*this);
	}
};

class Smartphone : public Mobiles
{
public:
	Smartphone(const Smartphone& temp)
	{

	}

	Mobiles* clone() {
		return new Smartphone(*this);
	}
};

class Smartwatch : public Mobiles
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