#pragma once
#include "HashTable.h"

/// @brief Структура словаря.
struct Dictionary
{
	/// @brief Таблица.
	HashTable* Table;
};

/// @brief Создание словаря.
/// @return Возвращает словарь.
Dictionary* InitDictionary();

/// @brief Добавляет элемент в словарь.
/// @param dictionary - Словарь.
/// @param element - Элемент.
/// @param key - Ключ.
/// @return Возвращает true, если элемент был успешно добавлен, иначе false.
bool AddElement(Dictionary* dictionary, Element* element, std::string key);

/// @brief Удаление эелмента из словаря.
/// @param dictionary - Словарь.
/// @param key - Ключ.
/// @return Возвращает true, если элемент был успешно удален, иначе false.
bool RemoveElement(Dictionary* dictionary, std::string key);

/// @brief Поиск элемента по заданному ключу в словаре.
/// @param dictionary - Словарь.
/// @param key - Ключ.
/// @param value - Значение.
/// @return Возвращает true, если элемент найден, иначе false.
bool FindElement(Dictionary* dictionary, std::string key, std::string& value);

/// @brief Удаляет словарь.
/// @param dictionary - Словарь.
void DeleteDictionary(Dictionary* dictionary);