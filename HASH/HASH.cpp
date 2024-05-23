#include <iostream>
#include <string>
#include <cctype>
#include "HT.h"
using namespace std;

int main() {
	// Initialaising
	HT table;
	string key, value;

	cout << "Welcome, it's hash table and you can do with it whatever you want.";
start:
	int choice;
	cout << "\n\nSo, your choise:\n1 - Add element\n2 - Delete element\n3 - Info about key\n4 - Show the table\n0 - Exit\nEnter the number: ";
	cin >> choice;

	// Checking user entered not a number
	if (cin.fail()) {
		cout << "\nTry again, you should aim on your number keys :)\n";
		cin.clear();
		cin.ignore();
		goto start;
	}

	// Menu
	if (choice == 1) goto add;
	if (choice == 2) goto del;
	if (choice == 3) goto get;
	if (choice == 4) goto sho;
	if (choice == 0) goto exit;
	if (choice > 3) {
		cout << "\nPlease, enter the number that include in menu :(\n";
		goto start;
	}

add:
	cout << "\n\nKey: ";
	cin >> key;
	if (key.empty() && !isalpha(key[0])) {
		cout << "\nThe key must start with the letter!\n";
		goto add;
	}
	cout << "Value: ";
	cin >> value;
	table.add(key, value);
	goto start;
del:
	cout << "\n\nEnter the key for deleting the element: ";
	cin >> key;
	table.remove(key);
	goto start;
get:
	cout << "\n\nEnter the key: ";
	cin >> key;
	if (key.empty() && !isalpha(key[0])) {
		cout << "\nThe key must start with the letter!\n";
		goto get;
	}
	value = table.get(key);
	cout << "\nThe value of key '" << key << "' - " << value << "\n";
	goto start;
sho:
	cout << "\n\nHere is yuor table: \n\n";
	table.show();
	goto start;
exit:
	return 0;
}