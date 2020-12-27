#pragma once

class Iterator //Iterator
{
public:
	virtual bool hasnext() = 0;
	virtual int next_bft() = 0; //next for bft
	virtual int next_dft() = 0; //next for dft
};

class Heap //heap
{
private:
	const int max_size = 100; //max size of heap
	int* heap; //pointer on heap
	size_t size; //current size
public:
	Heap() //constructor
	{
		heap = new int(max_size);
		size = 0;
	}
	~Heap() //destructor
	{
		delete[]heap;
	}
	bool contains(int key); //check if heap contains element
	void insert(int key); //insert element in heap
	void remove(int key); //remove element from heap
	void heapify(int index); //heap sorting
	void siftUp(int index); //for heapify, sort element from down to up
	void siftDown(int index); //for heapify, sort element from up to down
	void print(); //print heap
	int at(int index); //get element at index
	Iterator* create_dft_iterator(); //create iterator for dft
	Iterator* create_bft_iterator(); //create iterator for bft

	class HeapIterator: public Iterator //Iterator
	{
	public:
		HeapIterator(int start, size_t size, int* heap)
		{
			current = start;
			h_size = size;
			head = heap;
		}
		bool hasnext() override; //check if next element in the heap
		int next_bft() override; //get next element
		int next_dft() override; //get next element
	private:
		int current;
		size_t h_size;
		int* head;
	};

	class Stack //stack
	{
	private:

		class Node
		{
		public:
			Node(int data, Node* next = nullptr, Node* previous = nullptr)  //constructor
			{
				this->data = data;
				this->next = next;
				this->previous = previous;
			};
			~Node() {}; //destructor

			int data;
			Node* next;
			Node* previous;
		};

		Node* head;
		Node* tail;
		size_t size;

	public:

		Stack(); //for stack initialisation

		void push_front(int newElem); //adding to the beginning of the stack
		void pop_front(); //remove the first element
		int at(size_t index); //getting an element by index (for getting first element)
	};
};


