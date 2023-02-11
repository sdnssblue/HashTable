#include <iostream>
#include "ValueValidator.h"
#include "MenuHashTable.h"
#include "MenuDictionary.h"

using namespace std;

string InputString(const char* text)
{
	while (true)
	{
		cout << text;
		string value;
		cin >> value;

		if (value != "")
		{
			return value;
		}
	}
}

void Show(Element* element)
{
	cout << "Key: " << "[" << element->Key << "]" << " - Value: " << "[" << element->Value << "]";
}


int main()
{
	cout << "Choose function: " << endl;

	while (true)
	{
		cout << "1. Hash Table.\n"
				"2. Dictionary.\n" << endl;

		int numberOfTask = CheckingForDigit("Enter number action: ");

		switch (numberOfTask)
		{
			case 1:
			{
				system("cls");
				MenuHashTable();
				break;
			}
			case 2:
			{
				system("cls");
				MenuDictionary();
				break;
			}
			default:
			{
				cout << "Enter correct number of action." << endl;
				break;
			}
		}
	}
}