#include "Dictionary.h"

using namespace std;

Dictionary* InitDictionary()
{
	Dictionary* dictionary = new Dictionary;
	dictionary->Table = InitHashTable(4);
	return dictionary;
}

bool AddElement(Dictionary* dictionary, Element* element, string key)
{
	int newIndex = HashFunction(key, dictionary->Table->Size);
	Element* currentElement = dictionary->Table->Array[newIndex]->Head;
	while (currentElement != nullptr)
	{
		if (currentElement->Key == element->Key)
		{
			return false;
		}
		currentElement = currentElement->Next;
	}
	AddElement(dictionary->Table, element, newIndex);
	return true;
}

bool RemoveElement(Dictionary* dictionary, string key)
{
	return RemoveElement(dictionary->Table, key);
}

bool FindElement(Dictionary* dictionary, string key, string& value)
{
	return FindElement(dictionary->Table, key, value);
}

void DeleteDictionary(Dictionary* dictionary)
{
	DeleteTable(dictionary->Table);
	delete dictionary;
}