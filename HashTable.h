#pragma once
#include "Chain.h"

/// @brief Структура хэш-таблицы.
struct HashTable
{
	/// @brief Число роста хэш-таблицы.
	const int GrowthFactor = 2;

	/// @brief Количество внесенных элементов.
	int Count;

	/// @brief Размер хэш-таблицы.
	int Size;

	/// @brief Двумерный динамический массив цепочек.
	Chain** Array;
};

/// @brief Создает хеш-таблицу.
/// @param size - Размер.
/// @return Возвращает хеш-таблицу.
HashTable* InitHashTable(int size);

/// @brief Создает элемент.
/// @param key - Ключ.
/// @param value - Значение.
/// @return Возвращает элемент.
Element* CreateElement(string key, string value);

/// @brief Добавление элемента в хеш-таблицу.
/// @param table - Таблица.
/// @param element - Элемент.
/// @param index - Индекс.
/// @return Возвращает true, если элемент был успешно вставлен, иначе false.
bool AddElement(HashTable* table, Element* element, int index);

/// @brief Разрешение столкновений.
/// @param first - Первый элемент.
/// @param element - Элемент.
void ResolveCollisions(Element* first, Element* element);

/// @brief Преобразуйте значение ключа в хеш-сумму.
/// @param key - Ключ.
/// @param tableSize - Размер таблицы.
/// @return Возвращает хеш-сумму.
int HashFunction(std::string key, int tableSize);

/// @brief Ищет элемент с заданным ключом.
/// @param table - Таблица.
/// @param key - Ключ.
/// @param data - Значение.
/// @return Возвращает true, если элемент найден, иначе false.
bool FindElement(HashTable* table, string key, string& data);

/// @brief Удаляет элемент с заданным ключом.
/// @param table - Таблица.
/// @param key - Ключ.
/// @return Возвращает true, если элемент был успешно удален, иначе false.
bool RemoveElement(HashTable* table, string key);

/// @brief Удаляет хеш-таблицу.
/// @param table - Таблица.
void DeleteTable(HashTable* table);

/// @brief Перехеширование таблицы.
/// @param table - Таблица.
void Rehashing(HashTable* table);