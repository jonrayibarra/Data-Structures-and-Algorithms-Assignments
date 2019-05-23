#include <iostream>
using namespace std;

#ifndef AVLTREE_H
#define AVLTREE_H

class AVLTree {
private:
	// variables
	struct Node {
		int value;
		Node* left;
		Node* right;
	};
	Node* root;

	// functions
	void clear(Node*&);
	int height(Node*);
	void rotateRight(Node*&);
	void rotateLeft(Node*&);
	void rotateRightLeft(Node*&);
	void rotateLeftRight(Node*&);
	int difference(Node*);
	void balance(Node*&);
	void append(Node*&, int);
	void remove(Node*&, int);
	bool find(Node*, int);
	void print(Node*);

public:
	AVLTree();
	~AVLTree();
	void clear();
	void append(int);
	void remove(int);
	bool find(int);
	void print();
	bool isEmpty();
	bool isFull();
};

#endif

AVLTree::AVLTree() {
	// initialize root to null
	root = nullptr;
}

AVLTree::~AVLTree() {
	// free up all memory
	clear();
}

void AVLTree::clear() {
	// call private clear and pass arguments
	clear(root);
}

void AVLTree::append(int v) {
	// accept value to add, calls pvt append, pass arg
	append(root, v);
}

void AVLTree::remove(int v) {
	// accept value to remove, calls pvt remove, pass arg
	remove(root, v);
}

bool AVLTree::find(int v) {
	// accept value to find, calls pvt find, pass arg, return t or f
	if (find(root, v))
		return true;

	else
		return false;
}

void AVLTree::print() {
	// calls pvt print, pass arg
	int h;
	h = height(root);
	cout << endl << "height is " << h << endl;
	print(root);
}

bool AVLTree::isEmpty() {
	return root == nullptr;
}

bool AVLTree::isFull() {
	Node *dummy = new Node;

	if (dummy) {
		delete dummy;
		return false;
	}

	else
		return true;
}

void AVLTree::clear(Node*& r) {
	if (r != nullptr) {
		clear(r->left);
		clear(r->right);
		delete r;
		r = nullptr;
	}
}

int AVLTree::height(Node* r) {
	if (r == nullptr)
		return 0;

	else {
		int LH, RH;
		LH = height(r->left);
		RH = height(r->right);

		if (LH > RH)
			return 1 + LH;

		else
			return 1 + RH;
	}
}

void AVLTree::rotateRight(Node*& r) {
	Node* p = r->left;
	r->left = p->right;
	p->right = r;
	r = p;
}

void AVLTree::rotateLeft(Node*& r) {
	Node* p = r->right;
	r->right = p->left;
	p->left = r;
	r = p;
}

void AVLTree::rotateRightLeft(Node*& r) {
	rotateRight(r->right);
	rotateLeft(r);
}

void AVLTree::rotateLeftRight(Node*& r) {
	rotateLeft(r->left);
	rotateRight(r);
}

int AVLTree::difference(Node* r) {
	return height(r->right) - height(r->left);
}

void AVLTree::balance(Node*& r) {
	// left heavy
	if (difference(r) == -2) {
		if (difference(r->left) == -1)
			rotateRight(r);

		else
			rotateLeftRight(r);
	}

	// right heavy
	else if (difference(r) == 2) {
		if (difference(r->right) == 1)
			rotateLeft(r);

		else
			rotateRightLeft(r);
	}
}

void AVLTree::append(Node*& r, int v) {
	if (r == nullptr) {
		r = new Node();
		r->value = v;
		r->left = nullptr;
		r->right = nullptr;
	}

	else if (v < r->value) {
		append(r->left, v);
		balance(r);
	}

	else {
		append(r->right, v);
		balance(r);
	}

	int h;
	h = height(root);
}

void AVLTree::remove(Node*& r, int v) {
	if (r == nullptr)
		return;

	else if (v < r->value) {
		remove(r->left, v);
	}

	else if (v > r->value)
		remove(r->right, v);

	else {
		if ((r->left == nullptr) && (r->right == nullptr)) {
			delete r;
			r = nullptr;
		}

		else if ((r->left != nullptr) && (r->right == nullptr)) {
			Node* p = r;
			r = r->left;
			delete p;
		}

		else if ((r->left == nullptr) && (r->right != nullptr)) {
			Node* p = r;
			r = r->right;
			delete p;
		}

		else {
			Node* p = r->right;
			while (p->left != nullptr)
				p = p->left;

			p->left = r->left;
			p = r;
			r = r->right;
			delete p;
		}
	}
	balance(root);

	/* trying a different method (did not work)
	int heightdiff = difference(r);

	if (heightdiff > 1) {
		if (difference(r->right) >= 0)
			rotateLeft(r);

		else
			rotateRightLeft(r);
	}

	else if (heightdiff < -1) {
		if (difference(r->right) <= 0)
			rotateRight(r);

		else
			rotateLeftRight(r);
	}*/
}

bool AVLTree::find(Node* r, int v) {
	if (r == nullptr) {
		cout << endl << "value not found" << endl;
		return false;
	}

	else if (r->value == v) {
		cout << endl << "value found" << endl;
		return true;
	}

	else if (v < r->value)
		find(r->left, v);

	else
		find(r->right, v);
}

void AVLTree::print(Node* r) {
	if (r != nullptr) {
		print(r->left);
		cout << r->value;
		print(r->right);
	}
}