#include "HashTable.h"	

using namespace std;

HashTable* InitHashTable(int size)
{
	HashTable* table = new HashTable();

	table->Count = 0;
	table->Size = size;
	table->Array = new Chain* [table->Size];

	for (int i = 0; i < table->Size; i++)
	{
		Chain* newChain = new Chain;
		table->Array[i] = newChain;
		table->Array[i]->Size = 0;
		table->Array[i]->Head = nullptr;
	}
	return table;
}

Element* CreateElement(string key, string value)
{
	Element* element = new Element;
	element->Key = key;
	element->Value = value;
	element->Next = nullptr;

	return element;
}

bool AddElement(HashTable* table, Element* element, int index)
{
	const float fillFactor = 4.0 / 3.0;
	Element* currentElement = table->Array[index]->Head;
	while (currentElement != nullptr)
	{
		if (currentElement->Key == element->Key && currentElement->Value == element->Value)
		{
			return false;
		}

		currentElement = currentElement->Next;
	}
	if (table->Array[index]->Head == nullptr)
	{
		table->Array[index]->Head = element;
	}
	else
	{
		ResolveCollisions(table->Array[index]->Head, element);
	}
	table->Array[index]->Size++;
	table->Count++;
	int fullValue = table->Size * fillFactor;
	if (table->Count == fullValue)
	{
		Rehashing(table);
	}
	return true;
}

void ResolveCollisions(Element* first, Element* element)
{
	Element* currentElement = first;
	while (currentElement->Next != nullptr)
	{
		currentElement = currentElement->Next;
	}
	currentElement->Next = element;
}

int HashFunction(string key, int tableSize)
{
	int size = key.length();
	int hash = 0;

	for (int i = 0; i < size; i++)
	{
		hash = (hash + key[i]) % tableSize;
	}

	return abs(hash);
}

void Rehashing(HashTable* table)
{
	HashTable* newTable = InitHashTable(table->Size * table->GrowthFactor);
	for (int i = 0; i < table->Size; i++)
	{
		Element* currentElement = table->Array[i]->Head;

		while (currentElement != nullptr)
		{
			int index = HashFunction(currentElement->Key, newTable->Size);
			AddElement(newTable, currentElement, index);
			table->Array[i]->Head = currentElement->Next;
			currentElement->Next = nullptr;
			currentElement = table->Array[i]->Head;
		}
	}

	table->Count = newTable->Count;
	table->Array = newTable->Array;
	table->Size = newTable->Size;
}

bool FindElement(HashTable* table, string key, string& data)
{
	int index = HashFunction(key, table->Size);
	Element* currentElement;
	if (!table->Array[index]->Head)
	{
		return false;

	}
	currentElement = table->Array[index]->Head;
	while (currentElement != nullptr)
	{
		if (currentElement->Key == key)
		{
			data.append(currentElement->Value);
			data.push_back(' ');
		}
		currentElement = currentElement->Next;
	}
	if (data.empty())
	{
		return false;
	}
	return true;
}

bool RemoveElement(HashTable* table, string key)
{
	int removeIndex = HashFunction(key, table->Size);
	if (table->Array[removeIndex]->Size == 0) return false;
	Element* currentElement = table->Array[removeIndex]->Head;
	int count = 0;
	bool isNeedRemove = false;
	while (currentElement != nullptr)
	{
		if (currentElement->Key == key)
		{
			count++;
			isNeedRemove = true;
		}
		currentElement = currentElement->Next;
	}

	if (isNeedRemove == false)
	{
		return false;
	}
	while (count != 0)
	{
		if (table->Array[removeIndex]->Head->Key == key)
		{
			Element* removeElement = table->Array[removeIndex]->Head;
			table->Array[removeIndex]->Head = table->Array[removeIndex]->Head->Next;
			delete removeElement;
		}
		else
		{
			Element* previousRemoveElement = table->Array[removeIndex]->Head;
			int secondCount = 0;

			while (previousRemoveElement->Next->Key != key)
			{
				secondCount++;
				previousRemoveElement = previousRemoveElement->Next;
			}
			Element* deleteElement = previousRemoveElement->Next;

			if (secondCount == table->Array[removeIndex]->Size - 2)
			{
				previousRemoveElement->Next = nullptr;
			}
			else
			{
				previousRemoveElement->Next = previousRemoveElement->Next->Next;
			}
			delete deleteElement;
		}
		table->Count--;
		table->Array[removeIndex]->Size--;
		count--;
	}
	return true;
}

void DeleteTable(HashTable* table)
{
	for (int i = 0; i < table->Size; i++)
	{
		for (int j = 0; j < table->Array[i]->Size; j++)
		{
			Element* removeElement = table->Array[i]->Head;

			if (table->Array[i]->Head->Next != nullptr)
			{
				table->Array[i]->Head = table->Array[i]->Head->Next;
			}
			delete removeElement;
		}
		delete table->Array[i];
	}
	delete[] table->Array;
	delete table;
}