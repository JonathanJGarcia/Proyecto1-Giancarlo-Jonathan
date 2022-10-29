#pragma once
#include <string>

class Reciente
{
	class Node
	{
	public:

		std::string data;


		Node* next;
	};
public:

	Node* header = nullptr;
	Node* Tail = nullptr;
	int count = 0;
	int maxCount = 0;

public:
	int Count();

	void push(std::string item);

	std::string pop();

	void RemoveAt(int index);

	int GetItem(int index);

	bool igual();
};


