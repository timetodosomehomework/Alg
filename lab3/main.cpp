#include <iostream>
#include "BinHeap.h"
using namespace std;

int main()
{
	Heap heap;
	for (int i = 0; i < 10; i++) //filling heap
	{
		heap.insert(i + 2);
	}
	Iterator* heap_iterator_bft = heap.create_bft_iterator(); //bft
	while (heap_iterator_bft->hasnext())
	{
		cout << heap_iterator_bft->next_bft() << '\t';
	}
	cout << endl;
	heap.remove(6); //delete 6 element in heap
	Iterator* heap_iterator_dft = heap.create_dft_iterator(); //dft
	while (heap_iterator_dft->hasnext())
	{
		cout << heap_iterator_dft->next_dft() << '\t';
	}
	return 0;
}
