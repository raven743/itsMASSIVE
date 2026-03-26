#pragma once
#include <iostream>

class Queue
{
public:
	struct Node
	{
		int Value;
		Node* Next;
	};
private:
	Node* BeginList;
public:
	Queue()
	{
		BeginList = nullptr;
	}
	~Queue()
	{
		Clear();
	}

	void Add(int value)
	{
		Node* newNode = new Node();
		Node* current = BeginList;
		newNode->Value = value;
		newNode->Next = nullptr;

		if (BeginList == nullptr)
		{
			BeginList = newNode;
			return;
		}

		while (current->Next != nullptr)
		{
			current = current->Next;
		}
		current->Next = newNode;
	}

	void Clear()
	{
		if (BeginList == nullptr)
			return;

		Node* current = BeginList;
		Node* next = nullptr;

		while (current != nullptr)
		{
			next = current->Next;
			delete current;
			current = next;
		}
		BeginList = nullptr;
	}

	void PrintToConsole()
	{
		if (BeginList == nullptr)
		{
			std::cout << "Its empty..." << std::endl;
			return;
		}

		Node* current = BeginList;
		Node* next = nullptr;

		std::cout << "Entering list..." << std::endl;
		while (current != nullptr)
		{
			std::cout << "Current value = " << current->Value << "\n";
			current = current->Next;
		}
		std::cout << std::endl;
	}

	void Remove()
	{
		if (BeginList == nullptr)
			return;

		Node* current = BeginList;
		BeginList = BeginList->Next;
		delete current;
	}

	bool IsContain(int value)
	{
		Node* current = BeginList;
		while (current != nullptr)
		{
			if (current->Value == value)
				return true;
			current = current->Next;
		}
		return false;
	}
private:
};

