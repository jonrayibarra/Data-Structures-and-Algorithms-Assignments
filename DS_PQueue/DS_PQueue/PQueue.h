#include <iostream>
using namespace std;

#ifndef PQUEUE_H
#define PQUEUE_H

class PQueue {
private:
	int* heap;
	int size;
	int bottom;

	void ReHeapUp();
	void ReHeapDown();

public:
	PQueue(int);
	~PQueue();
	void enqueue(int);
	void dequeue();
	int top();
};

#endif

PQueue::PQueue(int s) {
	heap = new int[s];
	size = s;
	bottom = -1;
	//heap = newarray;
}

PQueue::~PQueue() {
	delete[] heap;
}

void PQueue::enqueue(int i) {
	if (bottom != size - 1) {
		bottom += 1;
		heap[bottom] = i;
		ReHeapUp();
	}

	/*else
		cout << "Unable to enqueue." << endl;*/
}

void PQueue::dequeue() {
	if (bottom != -1) {
		int temp = heap[0];
		heap[0] = heap[bottom];
		heap[bottom] = temp;
		bottom -= 1;
		ReHeapDown();
	}

	/*else
		cout << "Unable to dequeue." << endl;*/
}

int PQueue::top() {
	if (bottom != -1)
		return heap[0];

	else
		return -1;

	/*else
		cout << "Empty heap..." << endl;*/
}

void PQueue::ReHeapUp() {
	int i = bottom;
	int parent, temp;
	while (i != 0) {
		parent = ((i - 1) / 2);
		if (heap[i] > heap[parent]) {
			temp = heap[i];
			heap[i] = heap[parent];
			heap[parent] = temp;
		}

		else
			return;

		i = parent;
	}
}

void PQueue::ReHeapDown() {
	int parent = 0;
	int leftchild, rightchild, bottomchild, temp;
	while (parent < bottom) {
		leftchild = ((2 * parent) + 1);
		rightchild = ((2 * parent) + 2);
		if (leftchild <= bottom) {
			if (leftchild == bottom)
				bottomchild = leftchild;

			else {
				if (heap[leftchild] > heap[rightchild])
					bottomchild = leftchild;

				else
					bottomchild = rightchild;
			}
		}

		else
			return;

		if (heap[parent] < heap[bottomchild]) {
			temp = heap[parent];
			heap[parent] = heap[bottomchild];
			heap[bottomchild] = temp;
			parent = bottomchild;
		}

		else
			return;
	}
}