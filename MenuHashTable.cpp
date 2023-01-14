#include <iostream>
#include "MenuHashTable.h"
#include "ValueValidator.h"
#include "Menu.h"

using namespace std;

void ShowHashTable(HashTable* table)
{
	cout << "\nHash Table:" << endl;
	Element* currentElement;
	for (int i = 0; i < table->Size; i++)
	{
		currentElement = table->Array[i]->Head;
		if (currentElement == nullptr)
		{
			cout << "Key: [ ] - Value: [ ]" << endl;
			continue;
		}
		if (currentElement->Next == nullptr)
		{
			//TODO: duplication
			ForShow(currentElement);
			cout << endl;
			continue;
		}
		while (currentElement != nullptr)
		{
			//TODO: duplication
			ForShow(currentElement);
			cout << " -> ";
			currentElement = currentElement->Next;
		}
		cout << endl;
	}
	cout << "Count of element: " << table->Count << endl << endl;
}

void MenuHashTable()
{
	HashTable* table = InitHashTable(4);

	cout << "Work with Hash Table." << endl;

	cout << "1. Add element to hash table.\n"
			"2. Remove element from table.\n"
			"3. Find element by key.\n"
			"0. Go back.\n" << endl;

	while (true)
	{
		int numberOfTask = CheckingForDigit("Enter number action: ");

		switch (numberOfTask)
		{
			case 1:
			{
				string key = InputString("Enter a key: ");
				string value = InputString("Enter a value: ");
				Element* element = CreateElement(key, value);
				int index = HashFunction(key, table->Size);
				if (!AddElement(table, element, index))
				{
					cout << "This element already exists in Hash Table." << endl;
				}
				ShowHashTable(table);
				break;
			}
			case 2:
			{
				string key = InputString("Enter a key: ");
				if (!RemoveElement(table, key))
				{
					cout << "This element does not exist in Hash Table." << endl;
				}
				ShowHashTable(table);
				break;
			}
			case 3:
			{
				string key = InputString("Enter a key: ");
				string data;
				if (FindElement(table, key, data))
				{
					cout << "Found information in Hash Table: " << data << endl;
				}
				else
				{
					cout << "Not Found information in Hash Table." << endl;
				}
				break;
			}
			case 0:
			{
				DeleteTable(table);
				system("cls");
				return;
			}
			default:
			{
				cout << "Enter correct number of action." << endl;
				break;
			}
		}
	}
}