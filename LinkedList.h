#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class LinkedList
{
	//friend class HashTable;
public:
	LinkedList(void);
	LinkedList(const LinkedList & ls);//copy constructor
	~LinkedList(void); //destructor

	bool insert(string);
	bool remove(string);
	bool empty()const;
	void print()const;
	void reverse_print()const;
	bool search(string s)const;
	vector<string> get()const;
	// Overloaded assignment operator
	LinkedList & operator= (const LinkedList & st);

private:
	
	class Node {
	public:
		string data;
		Node* next;

		Node(string s): data(s), next(NULL) {};
		Node(string s, Node* nd): data(s), next(nd) {};
	};

	Node* front;
	void deepCopy(const LinkedList & ls);
	void deleteList();
	void reverse_print_rec(Node* nd) const;
};



