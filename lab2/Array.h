#pragma once
#include <ctime>
#include <stdlib.h>

class Array
{
private:
	long size; //Size
	int* arr; //Pointer
public:
	Array(int n = 1) //Constructor
	{
		size = n;
		arr = new int[size];
		srand(time(0));
		for (int i = 0; i < size; i++) //Fill array with random elements
		{
			arr[i] = rand() % 10000;
		}
	}
	~Array() //Destructor
	{
		delete[]arr;
	}
	int* GetPointer(); //Return pointer on the array
	void Set(); //Set value of massive elements (test for binary search)
	void Print(); //Print array
	size_t BinarySearch(int key); //Binary search
	void QuickSort(int* arr, int left, int right); //Quick sort
	void BubbleSort(); //Bubble sort
	bool IsSorted(); //Check if array is sorted (for Bogosort)
	void Shuffle(); //Randomly shuffle array elements (for Bogosort)
	void BogoSort(); //Bogosort
};