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

