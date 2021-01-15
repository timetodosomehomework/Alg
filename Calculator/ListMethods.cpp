#include <iostream>
#include <stdexcept>
#include <string>
#include "List.h"
using namespace std;

LinkedList::LinkedList() //constructor
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

void LinkedList::push_back(double newElem) //adding to the end of the list
{
	if (size == 0) //if it's first element
	{
		head = new Node(newElem);
		tail = head;
	}
	else //if it isn't first element
	{
		tail->next = new Node(newElem, nullptr, tail);
		tail = tail->next;
	}
	size++;
}

double LinkedList::pop_back() //return last element and delete it
{
	if (size == 1) //if there is only one element in the list
	{
		double temp = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;
		size--;
		return temp;
	}
	else //if there is more than one element in the list
	{
		Node* del = tail;
		double temp = tail->data;
		tail->previous->next = nullptr;
		tail = tail->previous;
		delete del;
		size--;
		return temp;
	}
}



