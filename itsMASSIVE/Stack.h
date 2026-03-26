#pragma once
#include <iostream>

class Stack
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
	Stack()
	{
		BeginList = nullptr;
	}
	~Stack()
	{
		Clear();
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
			std::cout << "The list is empty." << std::endl;
			return;
		}

		Node* current = BeginList;
		Node* next = nullptr;

		std::cout << "Entering the list...\n" << std::endl;
		while (current != nullptr)
		{
			std::cout << "Current value: " << current->Value << "\n";
			current = current->Next;

		}
		std::cout << std::endl;
	}

	void Remove()
	{
		if (BeginList == nullptr)
			return;

		if (BeginList->Next == nullptr)
		{
			delete BeginList;
			BeginList = nullptr;
			return;
		}

		Node* current = BeginList;
		while (current->Next->Next != nullptr)
		{
			current = current->Next;
		}
		delete current->Next;
		current->Next = nullptr;
	}

	void Add(int value)
	{
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

