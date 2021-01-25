#include "Calculator.h";
#define _USE_MATH_DEFINES
#include <math.h>
const size_t number_length = 50;


void Calculator::push_back(string data, Node::Character character, Node::Priority priority)//adding to the end of the list
{
	if (size == 0) //if it's first element
	{
		head = new Node(data, character, priority);
		tail = head;
	}
	else //if it isn't first element
	{
		tail->next = new Node(data, character, priority, nullptr, tail);
		tail = tail->next;
	}
	size++;
}

void Calculator::push_front(string data, Node::Character character, Node::Priority priority)//adding to the beginning of the list
{
	if (size == 0) //if it's first element
	{
		head = new Node(data, character, priority);
		tail = head;
	}
	else //if it isn't first element
	{
		head->previous = new Node(data, character, priority);
		head->previous->next = head;
		head = head->previous;
	}
	size++;
}

void Calculator::pop_back()//remove the last element
{
	if (size == 1) //if there is only one element in the list
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else //if there is more than one element in the list
	{
		Node* del = tail;
		tail = tail->previous;
		tail->next = nullptr;
		delete del;
	}
	size--;
}

void Calculator::print_to_console()//print the list to the console 
{
	Node* current = head;
	cout << current->data;
	while (current->next != nullptr)
	{
		current = current->next;
		cout << ' ' << current->data;
	}
}

void Calculator::give_priority(string data, size_t index)//give character a priority
{
	switch (data[index])
	{
	case '+': tail->character = Node::Character::plus;
		tail->priority = Node::Priority::plus;
		tail->length = 1;
		break;
	case '-': if ((index == 0) || (index - 1 == '('))
	{
		tail->character = Node::Character::unary;
		tail->priority = Node::Priority::function;
		tail->length = 1;
	}
			else
	{
		tail->character = Node::Character::minus;
		tail->priority = Node::Priority::minus;
		tail->length = 1;
	}
			break;
	case '*': tail->character = Node::Character::mult;
		tail->priority = Node::Priority::mult_div;
		tail->length = 1;
		break;
	case '/': tail->character = Node::Character::div;
		tail->priority = Node::Priority::mult_div;
		tail->length = 1;
		break;
	case '^': tail->character = Node::Character::pow;
		tail->priority = Node::Priority::pow;
		tail->length = 1;
		break;
	case 'c': if (data[index + 1] == 'o' && data[index + 2] == 's')
	{
		tail->character = Node::Character::cos;
		tail->priority = Node::Priority::function;
		tail->length = 3;
	}
			if (data[index + 1] == 't' && data[index + 2] == 'g')
			{
				tail->character = Node::Character::ctg;
				tail->priority = Node::Priority::function;
				tail->length = 3;
			}
			if (data[index + 1] == 'b' && data[index + 2] == 'r' && data[index + 3] == 't')
			{
				tail->character = Node::Character::cbrt;
				tail->priority = Node::Priority::function;
				tail->length = 4;
			}
			break;
	case 's': if (data[index + 1] == 'i' && data[index + 2] == 'n')
	{
		tail->character = Node::Character::sin;
		tail->priority = Node::Priority::function;
		tail->length = 3;
	}
			if (data[index + 1] == 'q' && data[index + 2] == 'r' && data[index + 3] == 't')
			{
				tail->character = Node::Character::sqrt;
				tail->priority = Node::Priority::function;
				tail->length = 4;
			}
			break;
	case 't': if (data[index + 1] == 'g')
	{
		tail->character = Node::Character::tg;
		tail->priority = Node::Priority::function;
		tail->length = 2;
	}
			break;
	case 'l': if (data[index + 1] == 'o' && data[index + 2] == 'g')
	{
		tail->character = Node::Character::log;
		tail->priority = Node::Priority::function;
		tail->length = 3;
	}
			if (data[index + 1] == 'n')
			{
				tail->character = Node::Character::ln;
				tail->priority = Node::Priority::function;
				tail->length = 2;
			}
			break;
	case 'p': if (data[index + 1] == 'i')
	{
		tail->character = Node::Character::pi;
		tail->priority = Node::Priority::number;
		tail->length = 2;
	}
			break;
	case 'e': tail->character = Node::Character::e;
		tail->priority = Node::Priority::number;
		tail->length = 1;
		break;
	case '(': tail->character = Node::Character::o_bracket;
		tail->priority = Node::Priority::brackets;
		tail->length = 1;
		break;
	case ')': tail->character = Node::Character::c_bracket;
		tail->priority = Node::Priority::brackets;
		tail->length = 1;
		break;
	case '0':                                  //if it's a number
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{
		string number = "";
		number.push_back(data[index]);
		bool correct_input = true;
		size_t count_dots = 0;
		size_t current_length = 1;
		while (((data[index + current_length] >= 48) && (data[index + current_length] <= 57)) || (data[index + current_length] == '.'))
		{
			if (data[index + current_length] == '.')
			{
				count_dots++;
			}
			if ((data[index] = '0' && data[index + 1] != '.') || (current_length > number_length) || (count_dots > 1))
			{
				correct_input = false;
				break;
			}
			number.push_back(data[index + current_length]);
			current_length++;
		}
		if (correct_input)
		{
			tail->character = Node::Character::number;
			tail->priority = Node::Priority::number;
			tail->length = current_length;
		}
		else
		{
			cout << "Incorrect input in " << index + current_length + 1 << " position";
		}
		break;
	}
	} 
}

bool Calculator::isCorrect()//check for corectness of expression
{
	Node* current = head;
	size_t brackets_counter = 0;
	if (current->priority >= Node::Priority::plus && current->priority <= Node::Priority::pow)
	{
		cout << "Incorrect input in 1 position";
		return false;
	}
	while (current != nullptr)
	{
		if (current->character == Node::Character::unknown)
		{
			cout << "\nIncorrect character: " << current->data;
			return false;
		}
		if ((current->character == Node::Character::c_bracket) && (brackets_counter == 0))
		{
			cout << "\nMissing open bracket";
			return false;
		}
		if (current->character == Node::Character::o_bracket)
			brackets_counter++;
		if (current->character == Node::Character::c_bracket)
			brackets_counter--;
		if (current->previous != nullptr)
		{
			if ((current->previous->priority >= Node::Priority::plus && current->previous->priority <= Node::Priority::pow && current->priority >= Node::Priority::plus && current->priority <= Node::Priority::pow) || (current->previous->character == Node::Character::unary && current->character == Node::Character::o_bracket) || (current->previous->character == Node::Character::c_bracket && (current->character == Node::Character::o_bracket || current->priority == Node::Priority::number || current->priority == Node::Priority::function)) || (current->character == Node::Character::c_bracket && !(current->previous->priority == Node::Priority::number || current->previous->character == Node::Character::c_bracket)) || (current->previous->character == Node::Character::o_bracket && !(current->priority == Node::Priority::number || current->priority == Node::Priority::function || current->character == Node::Character::o_bracket)) || (current->previous->character == Node::Character::number && (current->priority == Node::Priority::function || current->priority == Node::Priority::number || current->character == Node::Character::o_bracket)))
			{
				cout << "Two mismatched operators in a row";
				return false;
			}
		}
		current = current->next;
	}
	if (brackets_counter != 0)
	{
		cout << "Missing close bracket";
		return false;
	}
	return true;
}

bool Calculator::read(string data)//read the expression
{
	char stop = '$';
	bool stop_flag = false;
	for (int i = 0; !stop_flag; i += tail->length)
	{
		while (data[i] == ' ')
		{
			i++;
		}
		if (correct == false || data[i] == stop)
		{
			stop_flag = true;
			break;
		}
		push_back("", Node::Character::unknown, Node::Priority::unknown);
		give_priority(data, i);
		if (tail->character == Node::Character::unknown)
		{
			stop_flag = true;
			tail->length = 1;
		}
		for (int j = i; j < i + tail->length; j++)
		{
			tail->data.push_back(data[j]);
		}
	}
	if (!isCorrect())
	{
		correct = false;
		return false;
	}
	return true;
}

void Calculator::toPrefix() //to prefix form
{
	Calculator* stack = new Calculator;
	Calculator* prefix = new Calculator;
	Node* current = tail;
	for (int i = 0; i < size; i++)
	{
		switch (current->character)
		{
		case Node::Character::c_bracket:
			stack->push_back(current->data, current->character, current->priority);
			break;
		case Node::Character::number:
			prefix->push_front(current->data, current->character, current->priority);
			break;
		case Node::Character::o_bracket:
			while (stack->tail->character != Node::Character::c_bracket)
			{
				prefix->push_front(stack->tail->data, stack->tail->character, stack->tail->priority);
				stack->pop_back();
			}
			break;
		default:
			if (stack->size == 0)
			{
				stack->push_back(current->data, current->character, current->priority);
			}
			else
			{
				while (stack->tail->priority >= current->priority)
				{
					prefix->push_front(stack->tail->data, stack->tail->character, stack->tail->priority);
					stack->pop_back();
					if (stack->size == 0)
						break;
				}
				stack->push_back(current->data, current->character, current->priority);
			}
		}
		current = current->previous;
	}
	while (stack->size != 0)
	{
		if (stack->tail->character != Node::Character::c_bracket)
		{
			prefix->push_front(stack->tail->data, stack->tail->character, stack->tail->priority);
		}
		stack->pop_back();
	}
	head = prefix->head;
	current = head;
	for (int i = 0; i < prefix->size; i++)
	{
		tail = current;
		current = current->next;
	}
	size = prefix->size;
}

double Calculator::calculate() //calculate the expression
{
	Node* prefix = tail;
	LinkedList* stack = new LinkedList;
	double a, b;
	while (prefix != nullptr)
	{
		switch (prefix->character)
		{
		case Node::Character::plus:
			a = stack->pop_back();
			b = stack->pop_back();
			stack->push_back(a + b);
			break;
		case Node::Character::minus:
			a = stack->pop_back();
			b = stack->pop_back();
			stack->push_back(a - b);
			break;
		case Node::Character::mult:
			a = stack->pop_back();
			b = stack->pop_back();
			stack->push_back(a * b);
			break;
		case Node::Character::div:
			a = stack->pop_back();
			b = stack->pop_back();
			stack->push_back(a / b);
			break;
		case Node::Character::pow:
			a = stack->pop_back();
			b = stack->pop_back();
			stack->push_back(pow(a, b));
			break;
		case Node::Character::unary:
			a = stack->pop_back();
			stack->push_back((-1) * a);
			break;
		case Node::Character::cos:
			a = stack->pop_back();
			stack->push_back(cos(a));
			break;
		case Node::Character::sin:
			a = stack->pop_back();
			stack->push_back(sin(a));
			break;
		case Node::Character::tg:
			a = stack->pop_back();
			stack->push_back(tan(a));
			break;
		case Node::Character::ctg:
			a = stack->pop_back();
			stack->push_back(1 / tan(a));
			break;
		case Node::Character::ln:
			a = stack->pop_back();
			stack->push_back(log(a));
			break;
		case Node::Character::log:
			a = stack->pop_back();
			stack->push_back(log10(a));
			break;
		case Node::Character::sqrt:
			a = stack->pop_back();
			stack->push_back(sqrt(a));
			break;
		case Node::Character::cbrt:
			a = stack->pop_back();
			stack->push_back(cbrt(a));
			break;
		case Node::Character::pi:
			stack->push_back(M_PI);
			break;
		case Node::Character::e:
			stack->push_back(M_E);
			break;
		case Node::Character::number:
			stack->push_back(atof(prefix->data.c_str()));
			break;
		}
		prefix = prefix->previous;
	}
	return stack->pop_back();
}