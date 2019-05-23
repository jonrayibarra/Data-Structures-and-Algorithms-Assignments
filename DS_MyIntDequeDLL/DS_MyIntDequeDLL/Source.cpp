#include "MyIntDeque.h"

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int getNumber();

int main()
{
	MyIntDeque m;

	char choice;
	int num;

	do
	{
		cout << "\n\n1 - push_back\n"
			<< "2 - push_front\n"
			<< "3 - pop_back\n"
			<< "4 - pop_front\n"
			<< "5 - size\n"
			<< "6 - front\n"
			<< "7 - back\n"
			<< "8 - isFull\n"
			<< "9 - isEmpty\n"
			<< "0 - clear\n"
			<< "Q - quit\n"
			<< "\n\n> ";

		cin >> choice;
		cin.ignore(1000, 10);

		cout << "\n\n";

		switch (choice)
		{
		case '1':
			num = getNumber();
			m.push_back(num);
			break;
		case '2':
			num = getNumber();
			m.push_front(num);
			break;
		case '3':
			m.pop_back();
			break;
		case '4':
			m.pop_front();
			break;
		case '5':
			cout << "Size of deque: " << m.size() << endl;
			break;
		case '6':
			cout << "Front of deque: " << m.front() << endl;
			break;
		case '7':
			cout << "Back of deque: " << m.back() << endl;
			break;
		case '8':
			cout << "Deque " << (m.isFull() ? "is" : "isn't") << " full.\n";
			break;
		case '9':
			cout << "Deque " << (m.isEmpty() ? "is" : "isn't") << " empty.\n";
			break;
		case '0':
			m.clear();
			break;
		case 'Q':
		case 'q':
			break;
			//default:
		}

	} while (choice != 'Q' && choice != 'q');
}

int getNumber()
{
	int num;

	cout << "Enter a number to store in the deque: ";
	cin >> num;
	cin.ignore(1000, 10);

	return num;
}