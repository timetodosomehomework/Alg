#pragma once

class LinkedList
{
private:

	class Node
	{
	public:
		Node(double data, Node* next = nullptr, Node* previous = nullptr)  //constructor
		{
			this->data = data;
			this->next = next;
			this->previous = previous;
		};
		~Node() {}; //destructor

		double data;
		Node* next;
		Node* previous;
	};

	Node* head;
	Node* tail;
	size_t size;

public:

	LinkedList(); //constructor

	void push_back(double newElem); //adding to the end of the list
	double pop_back(); //remove the last element
};
