#pragma once
#include <iostream>
//// односвязный список
//// для списка характерно:
//// добавлять - Append(value)
//// убирать - Remove(value), RemoveFromEnd(),RemoveFromBegin()
//// вставлять в позицию - Insert(valuePosition, value)
//// поиск элемента в списке - IsContain(value)
//
//
//template <typename T>
class LinkedList
{
//public:
//	struct Node
//	{
//		T Value;
//		Node* Next;
//	};
//
//private:
//	Node* BeginList;
//
//public:
//	//конструктор
//	LinkedList()
//	{
//		BeginList = nullptr;
//	}
//
//	//деструктор
//	~LinkedList()
//	{
//		Clear();
//	}
//
//	//добавляем элемент в список
//	void Append(const T& value)
//	{
//		Node* newNode = new Node();
//		Node* current = BeginList;
//		newNode->Value = value;
//		newNode->Next = nullptr;
//		newNode->Prev = nullptr;
//
//		if (BeginList == nullptr)
//		{
//			BeginList = newNode;
//			return;
//		}
//
//		while (current->Next != nullptr)
//		{
//			current = current->Next;
//			current->Prev = current;
//		}
//
//		current->Next = newNode;
//	}
//
//	//удаляем ненужный список
//	void Clear()
//	{
//		if (BeginList == nullptr)
//			return;
//
//		Node* current = BeginList;
//		Node* next = nullptr;
//
//		while (current != nullptr)
//		{
//			next = current->Next;
//			delete current;
//			current = next;
//		}
//		BeginList = nullptr;
//	}
//
//	// выводим список на экран
//	void PrintToConsole()
//	{
//		if (BeginList == nullptr)
//		{
//			std::cout << "AJle enTa. oH nycT" << std::endl;
//			return;
//		}
//
//		Node* current = BeginList;
//		Node* next = nullptr;
//
//		std::cout << "JlaH, BblBo2ly cnucok\n" << std::endl;
//		while (current != nullptr)
//		{
//			std::cout << current->Value << "\t";
//			current = current->Next;
//
//		}
//		std::cout << std::endl;
//
//	}
//
//	// удаляем элемент с конца списка
//	void RemoveFromEnd()
//	{
//		if (BeginList == nullptr)
//			return;
//
//		if (BeginList->Next == nullptr)
//		{
//			delete BeginList;
//			BeginList = nullptr;
//			return;
//		}
//
//		Node* current = BeginList;
//		while (current->Next->Next != nullptr)
//		{
//			current = current->Next;
//		}
//		delete current->Next;
//		current->Next = nullptr;
//	}
//
//	// удаляем элемент с начала списка
//	void RemoveFromBegin()
//	{
//		if (BeginList == nullptr)
//			return;
//
//		Node* current = BeginList;
//		BeginList = BeginList->Next;
//		delete current;
//	}
//
//	// добавляем элемент в начало списка
//	void AddToBegin(const T& value)
//	{
//		Node* newNode = new Node();
//
//		newNode->Value = value;
//		newNode->Next = nullptr;
//
//		if (BeginList == nullptr)
//		{
//			BeginList = newNode;
//			return;
//		}
//
//		Node* current = BeginList;
//		newNode->Next = current;
//		BeginList = newNode;
//	}
//
//	// проверяем есть ли такое значение
//	bool IsContain(const T& value)
//	{
//		Node* current = BeginList;
//		while (current != nullptr)
//		{
//			if (current->Value == value)
//				return true;
//		}
//		return false;
//	}
//
//private:
};
//
