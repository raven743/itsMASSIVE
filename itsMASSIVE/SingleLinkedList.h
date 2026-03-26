#pragma once
#include <iostream>

class SingleLinkedList
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
	SingleLinkedList()
	{
		BeginList = nullptr;
	}
	~SingleLinkedList()
	{
		Clear();
 	}

	void Append(int value)
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
			std::cout << "AJle enTa. oH nycT" << std::endl;
			return;
		}
		Node* current = BeginList;
		Node* next = nullptr;

		std::cout << "JlaH, BblBo2ly cnucok" << std::endl;
		while (current != nullptr)
		{
			std::cout << "Tekylljee zHa4eHue -- " << current->Value << "\n";
			current = current->Next;

		}
		std::cout << std::endl;
	}

	void RemoveFromEnd()
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

	void RemoveFromBegin()
	{
		if (BeginList == nullptr)
			return;
		Node* current = BeginList;
		BeginList = BeginList->Next;
		delete current;
	}

	void AddToBegin(int value)
	{
		Node* newNode = new Node();

		newNode->Value = value;
		newNode->Next = nullptr;

		if (BeginList == nullptr)
		{
			BeginList = newNode;
			return;
		}
		Node* current = BeginList;
		newNode->Next = current;
		BeginList = newNode;
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

