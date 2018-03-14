#ifndef ITERATOR
#define ITERATOR

#include <iostream>

using namespace std;

class IntCollection;

class Iterator
{
protected:
	IntCollection* collection;
	int cont;

public:
	virtual int next() = 0;
	virtual bool hasNext() = 0;
};

class IntCollection
{
public:
	virtual void add(int element) = 0;
	virtual int at(int position) = 0;
	virtual Iterator* getIterator() = 0;
	virtual int getNumElements() = 0;
};

class IntArray;

class ArrayIterator : public Iterator
{
public:
	ArrayIterator(IntArray* IntArray)
	{
		collection = (IntCollection*)IntArray;
		cont = 0;
	}

	int next()
	{
		return collection->at(cont++);
	}

	bool hasNext()
	{
		if (cont >= collection->getNumElements())
		{
			return false;
		}
	}
};

class IntArray : public IntCollection
{
protected:
	int* array;
	int size;
	int numElems;

public:
	IntArray()
	{
		size = 10;
		array = new int[size];
		numElems = 0;
	}

	void add(int element)
	{
		if (numElems >= size)
		{
			cout << "ERROR: NO HAY ESPACIO EN EL ARREGLO!!" << endl;
		}
		array[numElems++] = element;
	}

	int at(int position)
	{
		if (size <= position < 0)
		{
			cout << "ERROR: INDICE INVALIDO!!" << endl;
			throw "out_of_range";
		}
		return array[position];
	}

	Iterator* getIterator()
	{
		return new ArrayIterator(this);
	}

	int getNumElements()
	{
		return numElems;
	}
};
#endif