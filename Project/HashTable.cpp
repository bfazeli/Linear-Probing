#include "HashTable.h"

ostream & operator<<(ostream & out, const HashTable & hashTable)
{
	// TODO: insert return statement here
	for (int i = 0; i < hashTable.capacity; i++)
		out << "Index " << i << " " << (hashTable.table[i] != -1) ? hashTable.table[i] : 'E';

	return out;
}

HashTable::HashTable()
{
	capacity = CAPACITY;
	numOfElements = 0;

	table = new int[capacity];
	fill_n(table, capacity, -1);	// Fills the array with -1's
}

HashTable::HashTable(int capacity)
{
	this->capacity = capacity;
	numOfElements = 0;

	table = new int[capacity];
	fill_n(table, capacity, -1);
}

HashTable::HashTable(const HashTable & otherHashTable)
{
	capacity = otherHashTable.capacity;
	numOfElements = otherHashTable.numOfElements;
	table = new int[capacity];

	for (int i = 0; i < numOfElements; ++i)
	{
		table[i] = otherHashTable.table[i];
	}
}

void HashTable::insert(int key)
{
	int hash = hashValue(key);
	if (numOfElements == capacity)
	{
		cout << "Table is full. Cannot insert.";
	}
	else
	{
		if (table[hash] != -1)
		{
			while (++hash != -1);
			table[hash] = key;
		}
		else
		{
			table[hash] = key;
		}
		++numOfElements;
	}
}

bool HashTable::search(int key) const
{
	int hash = hashValue(key);
	if (table[hash] == key)
	{
		return true;
	}
	else if (table[hash] != key)
	{
		int originalHash = hash;
		while (++hash)
		{
			if (hash >= capacity) hash = 0;
			else if (table[hash] == key) return true;
			else if (table[hash] == -1 || originalHash - 1 == hash) return false;
		}
		return true;
	}
	else
	{
		return false;
	}
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




