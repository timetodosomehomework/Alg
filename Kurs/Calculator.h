#pragma once
#include <iostream>
#include "List.h"
using namespace std;

class Calculator
{
private:

	class Node
	{
	public:

		enum class Character { plus, minus, mult, div, pow, unary, cos, sin, tg, ctg, ln, log, sqrt, cbrt, pi, e, o_bracket, c_bracket, number, unknown }; //enumeration of all characters
		enum class Priority { unknown, brackets,  plus, minus, mult_div, pow, function, number }; //enumeration of all character's priority

		Node(string data, Character character, Priority priority, Node* next = nullptr, Node* previous = nullptr)
		{
			this->data = data;
			this->character = character;
			this->priority = priority;
			this->next = next;
			this->previous = previous;
		};
		string data;
		Character character;
		Priority priority;
		Node* next;
		Node* previous;
		size_t length;
	};
	Node* head;
	Node* tail;
	size_t size;
	bool correct; //expression is correct or not

public:

	Calculator() //constructor
	{
		head = nullptr;
		tail = head;
		size = 0;
		correct = true;
	}

	~Calculator() //destructor
	{
		if (size == 1) //if there is only one element in the list
		{
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else //if there are more than one elements in the list
		{
			Node* current = head, * previous = current;
			do
			{
				current = current->next;
				delete previous;
				previous = current;
			} while (current->next != nullptr);
			delete previous;
			head = nullptr;
			tail = nullptr;
		}
		size = 0;
		correct = true;
	}

	void push_back(string data, Node::Character character, Node::Priority priority);//adding to the end of the list
	void push_front(string data, Node::Character character, Node::Priority priority);//adding to the beginning of the list
	void pop_back();//remove the last element
	void print_to_console();//print the list to the console 
	void give_priority(string data, size_t index);//give character a priority
	bool isCorrect(); //check for corectness of expression
	bool read(string data); //read the expression
	void toPrefix(); //to prefix form
	double calculate(); //calculate the expression
};