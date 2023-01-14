#include "ValueValidator.h"
#include <iostream>
#include <string>

using namespace std;

int CheckingForDigit(const char* text)
{
	if (text != "")
	{
		cout << text;
	}

	int value;

	while (true)
	{
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "An error has been detected! Try again! \n\nEnter number of action: ";
			continue;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (cin.gcount() > 1)
		{
			cout << "An error has been detected! Try again! \n\nEnter number of action: ";
			continue;
		}
		break;
	}
	return value;
}