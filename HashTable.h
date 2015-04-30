#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include "LinkedList.h"
using namespace std;

class HashTable{

public:
	// Default constructor
	// PARAM: 
	// PRE:
	// POST: Creates an empty Hashtable of size 101
	HashTable(void);
	// constructor
	// PARAM: size = size of the hashtable to be created 
	// PRE:
	// POST: Creates an empty Hashtable with given size
	HashTable(int size);
	// Copy constructor
	// PARAM: ht is the hashtable to be assigned to the calling object
	// PRE:
	// POST: Creates an object that is a copy of ht
	HashTable(const HashTable & ht);
	// Destructor
	// PARAM:
	// PRE:
	// POST: Memory associated with hashtable is de-allocated
	~HashTable(void); 
	// Overloaded assignment operator
	// In ht1 = ht2 assigns ht2 to ht1 and returns ht1
	// PARAM: ht = hashtable to be assigned to the calling object
	// PRE:
	// POST: Copies ht to calling object, returns calling object
	HashTable & operator= (const HashTable & ht);
	// Inserts string in hashtable, if not existing
	// PARAM: s = string to be inserted
	// PRE: inserting only lower case characters(no special characters and no upper case)
	// POST: s is inserted into hashtable and retrun true, otherwise return false
	bool insert(string);
	// Removes string  from the hashtable
	// PARAM: s = string to be removed
	// PRE:
	// POST: Removes s from hashtable return true if s was in the
	//       table, false otherwise
	bool remove(string);
	// Searchs list for a string in hashtable 
	// PARAM: s = string to be searched for
	// PRE:
	// POST: return true if string is in the table, false otherwise
	bool search(string)const;
	// determine the number of items in hashtable
	// PARAM:
	// PRE:
	// POST: return number of items in the hashtable
	int size()const;
	// determine the size of the array of Hashtable
	// PARAM:
	// PRE:
	//returns the size of the hash table’s underlying array 
	int maxSize()const;
	// determine the loadfactor of the Hashtable
	// PARAM:
	// PRE:
	//returns the size of the hash table’s underlying array 
	double loadFactor()const;
	//Create a intersection set of calling object and parameter 
    // PRE: two Hashtable objects created
    // POST: return a vector of strings containing the intersection of calling object and parameter object
    // PARAM: hashtable object to be used for intersection operation
	vector<string> intersection(const HashTable & ht)const;
	//Create a difference set of calling object and parameter 
    // PRE: two Hashtable objects created
    // POST: return a vector of strings containing the difference of calling object and parameter object
    // PARAM: hashtable object to be used for difference operation
	vector<string> difference(const HashTable & ht)const;
	//Create a union set of calling object and parameter 
    // PRE: two Hashtable objects created
    // POST: return a vector of strings containing the union of calling object and parameter object
    // PARAM: hashtable object to be used for union operation
	vector<string> unions(const HashTable & ht)const;

private:

	int arraySize;
	int hashTableSize;
	LinkedList* listArr;
	// determies if number is prime
	// PARAM: n = number to be checked
	// PRE:
	//returns true if number is prime, otherwise false
	bool primeCheck(int n);
	// HelperMethod: Makes a deep copy of a Hashtable
	// PARAM: ht is the table to copied
	// PRE: Calling object is empty
	// POST: table contents are identical to ht
	void deepCopy(const HashTable & ht);
	// Calculates the hash value of a given string
	// PARAM: s= the string to decode
	// PRE: string is in lower case
	// POST: returns a hash value for the passed string
	int hashFunc(const string s)const;
	// HelperMethod:deallocate memory associated with a hashtable object
	// PARAM:
	// PRE:
	// POST: Memory associated with hashtable is de-allocated
	void deleteTable();

};