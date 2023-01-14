#include <iostream>
#include "MenuDictionary.h"
#include "ValueValidator.h"
#include "Menu.h"

using namespace std;

void ShowDictionary(Dictionary* dictionary)
{
	cout << "\nDictionary:" << endl;
	Element* currentElement;
	for (int i = 0; i < dictionary->Table->Size; i++)
	{
		currentElement = dictionary->Table->Array[i]->Head;

		if (currentElement == nullptr)
		{
			cout << "";
			continue;
		}

		while (currentElement != nullptr)
		{
			//TODO: duplication
			ForShow(currentElement);
			currentElement = currentElement->Next;
			cout << endl;
		}
	}
	cout << endl;
}

void MenuDictionary()
{
	Dictionary* dictionary = InitDictionary();
	cout << "Work with Dictionary." << endl;

	cout << "1. Add element to dictionary.\n"
			"2. Remove element from dictionary.\n"
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
				if (!AddElement(dictionary, element, key))
				{
					cout << "This element already exists in Dictionary." << endl;
				}
				ShowDictionary(dictionary);
				break;
			}
			case 2:
			{
				string key = InputString("Enter a key: ");
				if (!RemoveElement(dictionary, key))
				{
					cout << "This element does not exist in Dictionary." << endl;
				}
				ShowDictionary(dictionary);
				break;
			}
			case 3:
			{
				string key = InputString("Enter a key: ");
				string data;
				if (FindElement(dictionary, key, data))
				{
					cout << "Found information: " << data << endl;
				}
				else
				{
					cout << "Not Found." << endl;
				}
				break;
			}
			case 0:
			{
				DeleteDictionary(dictionary);
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