#include "HashTable.h"

// Default constructor
// PARAM: 
// PRE:
// POST: Creates an empty Hashtable of size 101
HashTable::HashTable(void){
	arraySize = 101;
	listArr = new LinkedList[arraySize];
	hashTableSize = 0;
}
// constructor
// PARAM: size = size of the hashtable to be created 
// PRE:
// POST: Creates an empty Hashtable with given size
HashTable::HashTable(int size){
	int sz = 2 *size;
	bool prime = primeCheck(sz);
	
	if (prime){
		arraySize = sz;
		listArr = new LinkedList[arraySize];
		hashTableSize = 0;
	}else{
	
	 int nextPrimeNumber = sz + 1;
 
        //if the number is even, make it odd 
        if(nextPrimeNumber%2 == 0){
            nextPrimeNumber+=1;
        }
 
        //while its not a prime number, check the next odd number
        while(!primeCheck(nextPrimeNumber)){
            nextPrimeNumber+=2;
        }
		arraySize = nextPrimeNumber;
		listArr = new LinkedList[arraySize];
		hashTableSize = 0;
	}

	
}
// Copy constructor
// PARAM: ht is the hashtable to be assigned to the calling object
// PRE:
// POST: Creates an object that is a copy of ht
HashTable::HashTable(const HashTable & ht){

	deepCopy(ht);
}
// Destructor
// PARAM:
// PRE:
// POST: Memory associated with hashtable is de-allocated
HashTable::~HashTable(void){

	deleteTable();
} 
// Overloaded assignment operator
// In ht1 = ht2 assigns ht2 to ht1 and returns ht1
// PARAM: ht = hashtable to be assigned to the calling object
// PRE:
// POST: Copies ht to calling object, returns calling object
HashTable & HashTable::operator= (const HashTable & ht){

	if(this != &ht){
		deleteTable();
		deepCopy(ht);
	}
	return *this;

}
// Inserts string in hashtable, if not existing
// PARAM: s = string to be inserted
// PRE: inserting only lower case characters(no special characters and no upper case)
// POST: s is inserted into hashtable and retrun true, otherwise return false
bool HashTable::insert(string s){
	int arrIndex = hashFunc(s);
	//invalid string entered
	if (arrIndex < 0){
		
			return false;
		}
	//search in the proper linklist for the string
	bool exists = listArr[arrIndex].search(s);
	
	if(!exists){
			
			bool inserted = listArr[arrIndex].insert(s);
			
			if (inserted){
				hashTableSize++;
				return inserted;
			}else{
				//Not inserted
				return false;
			}
	
		
	}else{
	
		return false;
	}
	
}
// Removes string  from the hashtable
// PARAM: s = string to be removed
// PRE:
// POST: Removes s from hashtable return true if s was in the
//       table, false otherwise
bool HashTable::remove(string s){
	
	bool exists = search(s);
	
	if(exists){
		int arrIndex = hashFunc(s);
	
		if (arrIndex < 0){
			//if empty string
				return false;
		}else{
			bool removed = listArr[arrIndex].remove(s);
			
			if (removed){
				hashTableSize--;
				return removed;
			}else{
				//Not inserted
				return false;
			}
			
		}
	}else{
		//string does not exist
		return false;
	
	}
}
// Searchs list for a string in hashtable 
// PARAM: s = string to be searched for
// PRE:
// POST: return true if string is in the table, false otherwise
bool HashTable::search(string s)const{

	int arrIndex = hashFunc(s);
	
	if (arrIndex < 0){
		//if empty string
			return false;
	}else{
		return listArr[arrIndex].search(s);
	}
}
// determine the number of items in hashtable
// PARAM:
// PRE:
// POST: return number of items in the hashtable
int HashTable::size()const{

	return hashTableSize;
}
// determine the size of the array of Hashtable
// PARAM:
// PRE:
//returns the size of the hash table’s underlying array 
int HashTable::maxSize()const{

	return arraySize;
}
// determine the loadfactor of the Hashtable
// PARAM:
// PRE:
//returns the size of the hash table’s underlying array 
double HashTable::loadFactor()const{

	double loadFactor = double(hashTableSize) / double(arraySize);

	return loadFactor;
}
//Create a intersection set of calling object and parameter 
// PRE: two Hashtable objects created
// POST: return a vector of strings containing the intersection of calling object and parameter object
// PARAM: hashtable object to be used for intersection operation
vector<string> HashTable::intersection(const HashTable & ht)const{
	vector<string> result;
	vector<string> temp;
	vector<string> temp2;
	bool exists;

	for(int i = 0; i <arraySize; i++){
		
		temp2 = listArr[i].get();
		temp.insert(temp.end(),temp2.begin(),temp2.end());
		
	}
	
	for(int i = 0; i <temp.size(); i++){
		exists = ht.search(temp[i]);
		
		if (exists){
		
			result.push_back(temp[i]);
		}
	}


	return result;
}
//Create a difference set of calling object and parameter 
// PRE: two Hashtable objects created
// POST: return a vector of strings containing the difference of calling object and parameter object
// PARAM: hashtable object to be used for difference operation
vector<string> HashTable::difference(const HashTable & ht)const{
	vector<string> result;
	vector<string> temp;
	vector<string> temp2;
	bool exists;

	for(int i = 0; i <arraySize; i++){
		
		temp2 = listArr[i].get();
		temp.insert(temp.end(),temp2.begin(),temp2.end());
		
	}
	
	for(int i = 0; i <temp.size(); i++){
		exists = ht.search(temp[i]);
		
		if (!exists){
		
			result.push_back(temp[i]);
		}
	}


	return result;
}
//Create a union set of calling object and parameter 
// PRE: two Hashtable objects created
// POST: return a vector of strings containing the union of calling object and parameter object
// PARAM: hashtable object to be used for union operation
vector<string> HashTable::unions(const HashTable & ht)const{
	
	vector<string> temp;
	vector<string> temp2;
	

	for(int i = 0; i <arraySize; i++){
		
		temp2 = listArr[i].get();
		temp.insert(temp.end(),temp2.begin(),temp2.end());
		
	}
	for(int i = 0; i <ht.arraySize; i++){
		
		temp2 = ht.listArr[i].get();
		temp.insert(temp.end(),temp2.begin(),temp2.end());
		
	}

	return temp;
}
// determies if number is prime
// PARAM: n = number to be checked
// PRE:
//returns true if number is prime, otherwise false
bool HashTable::primeCheck(int n){
	
	int count= 0;

	for(int a=1;a<=n;a++){
	
		if(n%a == 0){
		
			count++;
		}
	}

	if(count==2){
	
		return true;

	}else{

		return false;
	}

}
// Makes a deep copy of a Hashtable
// PARAM: ht is the table to copied
// PRE: Calling object is empty
// POST: table contents are identical to ht
void HashTable::deepCopy(const HashTable & ht){

	arraySize = ht.arraySize;
	listArr = new LinkedList[arraySize];
	hashTableSize = ht.hashTableSize;
	
	//copy contents of the parameter array into calling array(uses linklist assignment operator)
		for(int i=0; i < arraySize; i++){
			listArr[i] = ht.listArr[i];
		}
}
// Calculates the hash value of a given string
	// PARAM: s= the string to decode
	// PRE: string is in lower case (no special characters)
	// POST: returns a hash value for the passed string
int HashTable::hashFunc(const string s)const{
	
	int sum;
	
	if(!s.empty()){

		 sum = s[0]-96;
		//if string is more than one character
		if (s.size() > 1){

			for(int i = 1; i< s.size(); i++){
	
				sum*= 32;
				sum += (s[i]-96);
				sum = sum % arraySize;
		
			}
		}
	}else{
	
		cerr<<"Empty String.Invalid command!"<<endl;
		return -1;
	}
	
	return sum;

}
// HelperMethod:deallocate memory associated with a hashtable object
// PARAM:
// PRE:
// POST: Memory associated with hashtable is de-allocated
void HashTable::deleteTable(){

	delete[] listArr;
}