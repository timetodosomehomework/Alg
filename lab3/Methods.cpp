#include <iostream>
#include "BinHeap.h"
using namespace std;

void Heap::siftDown(int index) //for heapify, sort element from up to down
{
	int left = 2 * index + 1, right = 2 * index + 2; //index of childs
	if ((left < size) && (heap[index] < heap[left])) //if left child is bigger than parent
	{
		int temp = heap[index];
		heap[index] = heap[left];
		heap[left] = temp;
		siftDown(left);
	}
	if ((right < size) && (heap[index] < heap[right])) //if right child is bigger than parent
	{
		int temp = heap[index];
		heap[index] = heap[right];
		heap[right] = temp;
		siftDown(right);
	}
}

void Heap::siftUp(int index) //for heapify, sort element from down to up
{
	int parent = (index - 1) / 2;
	if ((parent >= 0) && (heap[index] > heap[parent]))
	{
		int temp = heap[index];
		heap[index] = heap[parent];
		heap[parent] = temp;
		siftUp(parent);
	}
}

void Heap::heapify(int index) //heap sorting
{
	siftDown(index);
	siftUp(index);
}

bool Heap::contains(int key) //check if heap contains element
{
	for (int i = 0; i < size; i++)
	{
		if (key = heap[i])
		{
			return true;
		}
	}
	return false;
}

void Heap::insert(int key) //insert element in heap
{
	size++;
	heap[size - 1] = key;
	heapify(size - 1);
}

int Heap::at(int index) //get element at index
{
	return heap[index];
}

void Heap::print() //print heap
{
	for (int i = 0; i < size; i++)
	{
		cout << heap[i] << '\t';
	}
}

void Heap::remove(int key) //remove element from heap
{
	if (contains(key))
	{
		for (int i = 0; i < size; i++)
		{
			if (key = heap[i])
			{
				int temp = heap[i];
				heap[i] = heap[size];
				heap[size] = heap[i];
				size--;
				heapify(i);
			}
		}
	}
}


Iterator* Heap::create_bft_iterator() //createiterator for bft
{
	return new HeapIterator(0, size, heap);
}

Iterator* Heap::create_dft_iterator() //create iterator for dft
{
	return new HeapIterator(0, size, heap);
}

bool Heap::HeapIterator::hasnext() //check if next element in the heap
{
	return current < h_size;
}

int Heap::HeapIterator::next_bft() //get next element
{
	int temp = head[current];
	current++;
	return temp;
}

Heap::Stack::Stack() //for stack initialisation
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

int Heap::Stack::at(size_t index) //get element at index
{
	size_t counter = 0;
	Node* current = head;
	while (counter != index)
	{
		current = current->next;
		counter++;
	}
	return current->data;
}

void Heap::Stack::push_front(int key) //adding to the beginning of the stack
{
	if (size == 0) //if it's first element
	{
		head = new Node(key);
		tail = head;
	}
	else //if it isn't first element
	{
		head = new Node(key, head);
	}
	size++;
}

void Heap::Stack::pop_front() //remove the first element
{
	if (size == 0) //if there are no elements in the stack
		return;
	if (size == 1) //if there is only one element in the stack
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else //if there is more than one element in the stack
	{
		Node* del = head;
		head = head->next;
		head->previous = nullptr;
		delete del;
	}
	size--;
}

static Heap::Stack stack; //stack

int Heap::HeapIterator::next_dft() //get next element
{
	int temp = head[current];
	if (2 * current + 2 < h_size)
	{
		stack.push_front(2 * current + 2);
	}
	if (2 * current + 1 < h_size)
	{
		current = 2 * current + 1;
	}
	else
	{
		current = stack.at(0);
		stack.pop_front();
	}
	return temp;
}


