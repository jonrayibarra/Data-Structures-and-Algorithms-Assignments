#include <iostream>
using namespace std;

#ifndef MYINTDEQUE_H
#define MYINTDEQUE_H

class MyIntDeque {
private:
	struct Node {
		int value;
		Node *next;
		Node *prev;
	};

	Node *first;
	Node *last;

public:
	MyIntDeque();
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

MyIntDeque::MyIntDeque() {
	// Constructor: initialize f and b pointers to null
	first = nullptr;
	last = nullptr;
}

MyIntDeque::~MyIntDeque() {
	// Destructor: free all memory used
	clear();
}

void MyIntDeque::push_back(int i) {
	if (!isFull()) {
		Node *n = new Node;
		n->next = n;
		n->prev = n;
		n->value = i;

		if (isEmpty()) {
			first = n;
			last = n;
			n->next = first;
			n->prev = last;
		}

		else {
			n->prev = last;
			last->next = n;
			n->next = first;
			last = last->next;
		}
	}

	else
		cout << "Unable to push to back." << endl;
}

void MyIntDeque::push_front(int i) {
	if (!isFull()) {
		Node *n = new Node;
		n->next = n;
		n->prev = n;
		n->value = i;

		if (isEmpty()) {
			first = n;
			last = n;
			n->next = first;
			n->prev = last;
		}

		else {
			n->next = first;
			first->prev = n;
			n->prev = last;
			first = first->prev;
		}
	}

	else
		cout << "Unable to push to front." << endl;
}

void MyIntDeque::pop_back() {
	if (isEmpty()) {
		cout << "Unable to pop back." << endl;
		return;
	}

	else {
		// only one node
		if (first == first->next) {
			delete first;
			first = nullptr;
			last = nullptr;
		}

		// multiple nodes
		else {
			Node *p = last;
			Node *q = last->prev;
			q->next = last->next;
			first->prev = q;
			last = last->prev;
			delete p;
		}
	}
}

void MyIntDeque::pop_front() {
	if (isEmpty()) {
		cout << "Unable to pop front." << endl;
		return;
	}

	else {
		// only one node
		if (first == first->next) {
			delete first;
			first = nullptr;
			last = nullptr;
		}

		// multiple nodes
		else {
			Node *p = first;
			Node *q = first->next;
			q->prev = first->prev;
			last->next = q;
			first = first->next;
			delete p;
		}
	}
}

int MyIntDeque::size() {
	if (isEmpty())
		return 0;

	else {
		// only one node
		if (first == first->next)
			return 1;

		// multiple nodes
		else {
			int total = 1; // starts at 1 to count last node
			Node *p = first;
			
			while (p != last) {
				total += 1;
				p = p->next;
			}

			return total;
		}
	}
}

int MyIntDeque::front() {
	if (isEmpty())
		return -1;

	else
		return first->value;
}

int MyIntDeque::back() {
	if (isEmpty())
		return -1;

	else
		return last->value;
}

bool MyIntDeque::isFull() {
	Node *dummy = new Node;

	if (dummy) {
		delete dummy;
		return false;
	}

	else
		return true;
}

bool MyIntDeque::isEmpty() {
	return first == nullptr;
}

void MyIntDeque::clear() {
	if (isEmpty())
		return;

	else {
		Node *nil = first;
		Node *p = first;
		Node *q;

		do {
			q = p;
			p = p->next;
			delete q;
		} while (p != nil);
	}

	first = nullptr;
	last = nullptr;
}