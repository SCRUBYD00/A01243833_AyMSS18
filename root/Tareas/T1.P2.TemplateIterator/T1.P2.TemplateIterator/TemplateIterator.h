#ifndef TEMPLATEITERATOR_H
#define TEMPALTEITERATOR_H

#include <iostream>

using namespace std;

template <class T>
class Collection;

template <class T>
class Iterator
{
protected:
	Collection<T>* collection;
	int cont;

public:
	virtual T next() = 0;
	virtual bool hasNext() = 0;
};

template <class T>
class Collection
{
public:
	virtual void add(T element) = 0;
	virtual T at(int position) = 0;
	virtual Iterator<T>* getIterator() = 0;
	virtual int getNumElements() = 0;
};

template <class T>
class Array;

template <class T>
class ArrayIterator : public Iterator<T>
{
public:
	ArrayIterator(Array<T>* Array)
	{
		collection = (Collection<T>*)Array;
		cont = 0;
	}

	T next()
	{
		return collection->at(cont++);
	}

	bool hasNext()
	{
		if (cont >= collection->getNumElements())
		{
			return false;
		}

		return true;
	}
};

template<class T>
class Array : public Collection<T>
{
protected:
	T* array;
	int size;
	int numElems;

public:
	Array()
	{
		size = 10;
		array = new T[size];
		numElems = 0;
	}

	void add(T element)
	{
		if (numElems >= size)
		{
			cout << "ERROR: NO HAY ESPACIO EN EL ARREGLO!!" << endl;
		}
		array[numElems++] = element;
	}

	T at(int position)
	{
		if (size <= position < 0)
		{
			cout << "ERROR: INDICE INVALIDO!!" << endl;
			throw "out_of_range";
		}
		return array[position];
	}

	Iterator<T>* getIterator()
	{
		return new ArrayIterator<T>(this);
	}

	int getNumElements()
	{
		return numElems;
	}
};
#endif
