#pragma once
#include <string>

/// @brief Представляет реализацию по представлению элемента.
struct Element
{
	/// @brief Ключ.
	string Key;

	/// @brief Значение.
	string Value;

	/// @brief Указатель на следующий элемент.
	Element* Next = nullptr;
};