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
	/*heap.remove(6);*/
	Iterator* heap_iterator_bft = heap.create_bft_iterator();
	while (heap_iterator_bft->hasnext())
	{
		cout << heap_iterator_bft->next_bft() << '\t';
	}
	cout << endl;
	/*heap.remove(0);*/
	Iterator* heap_iterator_dft = heap.create_dft_iterator();
	while (heap_iterator_dft->hasnext())
	{
		cout << heap_iterator_dft->next_dft() << '\t';
	}
	return 0;
}