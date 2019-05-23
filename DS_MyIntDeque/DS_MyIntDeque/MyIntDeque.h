#include <iostream>
using namespace std;

#ifndef MYINTDEQUE_H
#define MYINTDEQUE_H

class MyIntDeque {
private:
	int *list;
	int cap, length, first, last;

public:
	MyIntDeque(int);
	~MyIntDeque();
	void push_back(int);
	void push_front(int);
	void pop_back();
	void pop_front();
	int size();
	int front();
	int back();
	bool isFull();
	bool isEmpty();
	void clear();
};

#endif

MyIntDeque::MyIntDeque(int s) {
	/* Constructor: accept integer and assign value to cap, 
	initialize length to 0, dynamically allocate the array */
	cap = s;
	length = 0;

	list = new int[cap];
}

MyIntDeque::~MyIntDeque() {
	// Destructor: delete the array
	delete[] list;
}

void MyIntDeque::push_back(int i) {
	// accept int and add to end of deque
	if (!isFull()) {
		list[last] = i;
		last = (last + 1) % cap;

		if (first == last)
			last = (((last - 1) % cap) + cap) % cap;

		length++;
	}
	else
		cout << "Unable to push value to back.";
}

void MyIntDeque::push_front(int i) {
	// accept int and add to beginning of deque
	if (!isFull()) {
		list[first] = i;
		first = (first + 1) % cap;

		if (first == last)
			first = (((first - 1) % cap) + cap) % cap;

		length++;
	}
	else
		cout << "Unable to push value to front.";
}

void MyIntDeque::pop_back() {
	// remove int at end of deque
	if (!isEmpty()) {
		cout << list[last] << " popped!";
		last = (((last - 1) % cap) + cap) % cap;
		length--;
	}
	else
		cout << "Unable to pop value to back.";
}

void MyIntDeque::pop_front() {
	// remove int at front of deque
	if (!isEmpty()) {
		cout << list[first] << " popped!";
		first = (first + 1) % cap;
		length--;
	}
	else
		cout << "Unable to pop value to front.";
}

int MyIntDeque::size() {
	return length;
}

int MyIntDeque::front() {
	if (!isEmpty())
		return list[first];
	else
		return -1;
}

int MyIntDeque::back() {
	if (!isEmpty())
		return list[last];
	else
		return -1;
}

bool MyIntDeque::isFull() {
	if (length == cap)
		return true;
	else
		return false;
}

bool MyIntDeque::isEmpty() {
	if (length == 0)
		return true;
	else
		return false;
}

void MyIntDeque::clear() {
	for (int i = 0; i < length; i++) {
		list[i] = NULL;
	}
	
	length = 0;
	first = 0;
	last = 0;

	cout << "Deque cleared!";
}