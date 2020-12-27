#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
#include "Array.h"
using namespace std;

void Array::Print() //Print array
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << '\t';
	cout << endl << endl;
}

int* Array::GetPointer() //Return pointer on the array
{
	return arr;
}

void Array::Set() //Set value of massive elements (test for binary search)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = i + 2;
	}
}

size_t Array::BinarySearch(int key) //Binary search
{
	int left = 0, right = size - 1, middle;
	while (left <= right)
	{
		middle = (left + right) / 2; //Get the middle element
		if (arr[middle] < key)
		{
			left = middle + 1; //Border shift
		}
		else
			if (arr[middle] > key)
			{
				right = middle - 1; //Border shift
			}
			else
				return middle;
	}
}

void Array::QuickSort(int* arr, int left, int right) //Quick sort
{
	int left_hold = left;
 	int right_hold = right;
	int pivot = arr[left];
	while (left < right)
	{
		while ((arr[right] >= pivot) && (left < right))
			right--; //Border shift
		if (left != right)
		{
			arr[left] = arr[right];
			left++; //Border shift
		}
		while ((arr[left] <= pivot) && (left < right))
			left++; //Border shift
		if (left != right)
		{
			arr[right] = arr[left];
			right--; //Border shift
		}
	}
	arr[left] = pivot;
	pivot = left;
	left = left_hold;
	right = right_hold;
	if (left < pivot)
		QuickSort(arr, left, pivot - 1); //Recursion
	if (right > pivot)
		QuickSort(arr, pivot + 1, right); //Recursion
}

void Array::BubbleSort() //Bubble sort
{
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j]; //Swap elements
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

bool Array::IsSorted() //Check if array is sorted (for Bogosort)
{
	int n = size;
	while (--n > 0)
	{
		if (arr[n] < arr[n - 1])
		{
			return false;
		}
	}
	return true;
}

void Array::Shuffle() //Randomly shuffle array elements (for Bogosort)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		int temp = arr[i], random_index = rand() % size;
		arr[i] = arr[random_index];
		arr[random_index] = temp;
	}
}

void Array::BogoSort() //Bogosort
{
	while (!IsSorted())
		Shuffle();
}