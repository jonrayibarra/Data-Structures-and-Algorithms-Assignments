#include "PQueue.h"

#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	PQueue p(10);

	// make sure class handles an empty heap 
	cout << p.top() << endl;

	// add 11 values to the heap --- only room for 10, this shouldn't crash
	for (int i = 0; i < 11; i++)
		p.enqueue(rand() % 100);

	// let's now view top and dequeue, 11 times --- values should be displayed 
	// in order and not crash. Numbers end with -1 because last top/dequeue is
	// on an empty queue.
	for (int i = 0; i < 11; i++)
	{
		cout << p.top() << " ";
		p.dequeue();
	}

	cout << endl;

	cin.get();
}