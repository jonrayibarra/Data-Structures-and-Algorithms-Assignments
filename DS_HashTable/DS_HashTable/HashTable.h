#include <iostream>
#include <string>
using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable {
private:
	struct Element {
		string key;
		int mark;
	};

	Element* table;
	int size;
	int hash(string);

public:
	HashTable(int);
	~HashTable();
	void insert(string);
	void remove(string);
	bool isFull();
	bool isEmpty();
	void clear();
	void print();
	bool find(string);
};

#endif

HashTable::HashTable(int s) {
	table = new Element[s];
	for (int counter = 0; counter < s; counter++)
		table[counter].mark = 0;
	size = s;
}

HashTable::~HashTable() {
	delete[] table;
}

void HashTable::insert(string s) {
	if (!isFull()) {
		int hashindex = hash(s);
		int counter = hashindex;
		do {
			if (table[counter].mark != 2) {
				table[counter].key = s;
				table[counter].mark = 2;
				return;
			}

			else {
				counter++;
				counter %= size;
			}
		} while (counter != hashindex);
	}
}

void HashTable::remove(string s) {
	if (!isEmpty()) {
		int hashindex = hash(s);
		int counter = hashindex;
		do {
			if ((table[counter].mark == 2) && (table[counter].key == s)) {
				table[counter].mark = 1;
				return;
			}

			else {
				counter++;
				counter %= size;
			}
		} while ((counter != hashindex));
	}
}

bool HashTable::isFull() {
	for (int counter = 0; counter < size; counter++) {
		if ((table[counter].mark == 0) || (table[counter].mark == 1))
			return false;
	}

	return true;
}

bool HashTable::isEmpty() {
	for (int counter = 0; counter < size; counter++) {
		if (table[counter].mark == 2)
			return false;
	}

	return true;
}

void HashTable::clear() {
	for (int counter = 0; counter < size; counter++) {
		table[counter].mark = 0;
	}
}

void HashTable::print() {
	for (int counter = 0; counter < size; counter++) {
		if (table[counter].mark == 2)
			cout << table[counter].key << endl;
	}
}

bool HashTable::find(string s) {
	int hashindex = hash(s);
	int counter = hashindex;
	do {
		if ((table[counter].mark == 2) && (table[counter].key == s))
			return true;

		else {
			counter++;
			counter %= size;
		}
	} while ((counter != hashindex));

	return false;
}

int HashTable::hash(string s) {
	return s.length() % size;
}