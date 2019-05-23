#include "HashTable.h"
#include <iostream>
using namespace std;



int main()
{
	HashTable h(5);

	cout << h.isFull() << ", " << h.isEmpty() << endl;

	h.insert("Hello!");

	cout << h.isFull() << ", " << h.isEmpty() << endl;
	h.insert("Hello!");
	h.insert("How");
	h.insert("Are");
	h.insert("You?");
	h.print();
	h.remove("Hello!");
	h.remove("Hello!");
	h.print();

	cout << h.isFull() << ", " << h.isEmpty() << endl;

	cout << h.find("How") << ", " << h.find("Hello") << endl;
	cout << h.find("Dog") << endl;

	h.remove("Dog");
	h.print();
	h.clear();
	h.print();
	cin.get();
}