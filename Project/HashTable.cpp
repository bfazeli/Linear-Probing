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
		cout << "Table is full. Cannot insert.";
	}
	else
	{
		if (table[hash] != -1)
		{
			do {
				hash = (hash != capacity - 1) ? ++hash : 0;
			} while (table[hash] != -1);
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
	bool value = false;
	if (table[hash] == key)
	{
		value = true;
	}
	else if (table[hash] != key)
	{
		int originalHash = hash;
		while (originalHash-1 != hash)
		{
			if (hash == capacity) hash = 0;
			else if (table[hash] == key) value = true;
			else if (table[hash] == -1 || originalHash - 1 == hash) value = false;
		}
	}
	
	return value;
	
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




