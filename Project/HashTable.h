#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <math.h>
using namespace std;

const int CAPACITY = 11;

class HashTable
{
	/*
		Overloaded instream operator
		This is a friend function that prints out the table in
		the following format:

			Index 0: (value is displayed, or "E" to indicate is empty)
			Index 1: (value is displayed, or "E" to indicate is empty)
			...		 (other indices are displayed)
			Index 9: (value is displayed, or "E" to indicate is empty)
			Index 10: (value is displayed, or "E" to indicate is empty)

		Parameters: an object of the ostream class, and an object
					of the HashTable class
	*/
	friend ostream& operator<<(ostream& out, const HashTable& hashTable);

	/*
		This is a friend function that returns the next prime number of the capacity
	*/
	friend int nextPrime(const HashTable& hashTable);

	friend bool isPrime(int number);

public:

	/*
		Default constructor
		The function initializes the hash table
		to capacity 11 (which is already set as a constant),
		the number of elements to 0, and creates a dynamic
		array of integers.In addition, your constructor will
		populate each index of the array with - 1, to indicate
		that slots are available.
	*/
	HashTable();


	/*
		Overloaded constructor
		The function initializes the hash table
		to a given capacity, the number of elements to 0, and
		creates a dynamic array of integers. In addition, your
		constructor will populate each index of the array with -1,
		to indicate that slots are available.

		Parameter: the capacity of the table
	*/
	HashTable(int capacity);

	/*
		Copy constructor
		The function creates a new hash table and copies
		all the elements from the hash table passed as a parameter
		into the newly created hash table.

		Parameter: an object of the HashTable class
	*/
	HashTable(const HashTable& otherHashTable);

	/*
		Function insert
		The function will call the function hashValue to find
		the index where the key should be inserted and insert the key.
		The function uses linear probing to handle collisions.
		If the table is full, the function outputs the error message,
		"Table is full. Cannot insert."

		Parameter: a key to insert into the hash table
	*/
	void insert(int key);

	/*
		Function search
		The function returns true if the item is found, and false otherwise.
		Make sure when searching that you STOP if:
			- you have gone once around the whole array OR
			- you find an empty slot OR
			- you found the key

		Check the warnings window to see if all paths return a value.

		Parameter: the key to search
	*/
	bool search(int key) const;

	/*
		Function remove
		Function will remove an element in the Hash table if it is found,
			else it will output an error messsage.
	*/
	void remove(int key);

	/*
		Function rehash
		Function will rehash the table 
	*/
	void rehash();

	/*
		Function getCapacity
		The function returns the capacity of the table.
	*/
	int getCapacity() const;

	/*
		Overloaded assignment operator

		Parameter: an object of the class HashTable
	*/
	HashTable& operator=(const HashTable& rightSide);

	/*
		Overloaded subscript operator
		The function returns the value at a 
		specific index in the hash table.

		Parameter: an int indicating the index of the value in the
				   hash table that must be returned
	*/
	int& operator[](int index) const;

	/*
		Destructor
		The function deletes the dynamic table from memory and resets 
		the pointer to NULL.
	*/
	~HashTable();

private:

	/*
		Function hashValue
		The function is a private function that returns the 
		hash value given by the formula

					h(key) = key % n

		Parameter: the key
	*/
	int hashValue(int key) const;
	
	int *table;				//pointer to the hash table
    int numOfElements;		//number of items in the hash table
    int capacity;			//maximum length of the hash table	
};

#endif
