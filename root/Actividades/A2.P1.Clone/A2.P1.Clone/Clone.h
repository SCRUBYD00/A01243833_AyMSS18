#ifndef CLONE_H
#define CLONE_H

#include <iostream>

using namespace std;

class Prueba 
{
public:
	int *val;
	int val2;

	Prueba()	// Default Constructor
	{

	}

	Prueba(int val) : val(new int(val)), val2(val2)	// Parameter Constructor
	{
		cout << "Parametro: " << val << endl;
	}

	Prueba(const Prueba& temp)	// Copy Constructor
	{
		val2 = *(temp.val);
		val = new int(*(temp.val));
	}
};
#endif