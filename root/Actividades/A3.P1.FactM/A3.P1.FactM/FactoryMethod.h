#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

#include <iostream>

using namespace std;

class Product
{
public:
	virtual void operation1() = 0;
	virtual void operation2() = 0;
};

class Product1 : public Product
{
public:
	void operation1()
	{
		cout << "I'm in operation 1 Prod 1" << endl;
	}

	void operation2()
	{
		cout << "I'm in operation 2 Prod 1" << endl;
	}
};

class Product2 : public Product
{
public:
	void operation1()
	{
		cout << "I'm in operation 1 Prod 2" << endl;
	}

	void operation2()
	{
		cout << "I'm in operation 2 Prod 2" << endl;
	}
};

class Creator
{
public:
	virtual Product* factoryMethod(int) = 0;

	Product* createProduct(int type) 
	{
		Product* myProduct = factoryMethod(type);
		myProduct->operation1();
		myProduct->operation2();
		return myProduct;
	}
};

class ConcreteCreator : public Creator
{
	Product* factoryMethod(int type)
	{
		if (type == 1)
		{
			return new Product1;
		}

		else
		{
			return new Product2;
		}
	}
};
#endif
