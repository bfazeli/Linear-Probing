/*
	Fazeli, Bijan

	CS A200
	March 2, 2017

	Lab 5
*/

#include "HashTable.h"

ostream & operator<<(ostream & out, const HashTable & hashTable)
{
	// TODO: insert return statement here
	for (int i = 0; i < hashTable.capacity; i++)
	{
		out << "Index " << i << ": ";
		if (hashTable.table[i] != -1)
		{
			out << hashTable.table[i];
		}
		else
		{
			out << "E";
		}
		cout << "\n";
	}

	return out;
}

int nextPrime(const HashTable & hashTable)
{
	int number = hashTable.capacity;
	while (!isPrime(++number));

	return number;
}

bool isPrime(int number)
{
	for (int i = 2, check = (int)sqrt((double)(number)); i <= check && !isPrime; ++i)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

HashTable::HashTable()
{
	capacity = CAPACITY;
	numOfElements = 0;

	table = new int[capacity];
	for (int i = 0; i < capacity; ++i)
		table[i] = -1;		// Fills the array with -1's
}

HashTable::HashTable(int capacity)
{
	this->capacity = capacity;
	numOfElements = 0;

	table = new int[capacity];
	for (int i = 0; i < capacity; ++i)
		table[i] = -1;		// Fills the array with -1's
}

HashTable::HashTable(const HashTable & otherHashTable)
{
	capacity = otherHashTable.capacity;
	numOfElements = otherHashTable.numOfElements;
	table = new int[capacity];

	for (int i = 0; i < capacity; ++i)
	{
		table[i] = otherHashTable.table[i];
	}
}

void HashTable::insert(int key)
{
	int hash = hashValue(key);
	if (numOfElements == capacity)
	{
		cerr << "Table is already full!!!";
	}
	else
	{
		while (table[hash] != -1 || table[hash] != -2)
		{
			hash = (hash == (capacity - 1)) ? 0 : hash + 1;
		}

		table[hash] = key;
		++numOfElements;
	}
}

bool HashTable::search(int key) const
{
	int hash = hashValue(key);

	if (numOfElements == 0) return false;
	else if (table[hash] == key)
	{
		return true;
	}
	else
	{
		for (int counter = 0;
			(counter < capacity) && (table[hash] != key) && (table[hash] != -1);
			++counter)
		{
			hash = (hash == (capacity - 1) ? 0 : hash + 1);
		}

		return table[hash] == key;
	}
}

void HashTable::remove(int key)
{
	int hash = hashValue(key);
	if (search(key))
	{
		while (table[hash] != key) 
			++hash;
		table[hash] = -2;
		--numOfElements;
	}
	else
	{
		cerr << "Could not delete the element, element is not in the table.";
	}
}

void HashTable::rehash()
{
	if (numOfElements > capacity/2)
	{

	}
	int* newTable = 
	

}

int HashTable::getCapacity() const
{
	return capacity;
}

HashTable& HashTable::operator=(const HashTable & rightSide)
{
	// TODO: insert return statement here
	if (this != &rightSide)
	{
		if (capacity != rightSide.capacity)
		{
			delete[] table;
			table = new int[rightSide.capacity];
			capacity = rightSide.capacity;
		}
		for (int i = 0; i < rightSide.numOfElements; ++i)
		{
			table[i] = rightSide.table[i];
		}
		numOfElements = rightSide.numOfElements;
	}
	else
	{
		cerr << "Attempted assignment to itself.";
	}
	return *this;

}

int & HashTable::operator[](int index) const
{
	// TODO: insert return statement here
	return table[index];
}

HashTable::~HashTable()
{
	delete[] table;
	table = NULL;
}

int HashTable::hashValue(int key) const
{
	return key % capacity;
}




