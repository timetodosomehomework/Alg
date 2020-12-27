#include <iostream>
#include <time.h>
#include "Array.h"
using namespace std;

void CountingSort1(char* arr_char, int size) //Counting sort
{
	int max = arr_char[0];
	for (int i = 0; i < size; i++) //Search for max
	{
		if (arr_char[i] > max)
		{
			max = arr_char[i];
		}
	}
	max -= 21; //Because it's ASCII
	int* count_arr = new int(max + 1);
	for (int i = 0; i < max + 1; i++) //Fill the new array with 0
	{
		count_arr[i] = 0;
	}
	for (int i = 0; i < size; i++) //The number of different elements is recorded at the corresponding index
	{
		count_arr[arr_char[i] - 21]++;
	}
	int count = 0;
	for (int i = 0; i < max + 1; i++) //Overwrite the initial array
	{
		for (int j = 0; j < count_arr[i]; j++)
		{
			arr_char[count] = i + 21;
			count++;
		}
	}
}

int main() //Sample program with algorithms
{
	int size = 10;
	Array arr(size);
	/*arr.Print();*/
	//arr.BogoSort();
	/*arr.Print();*/
	/*clock_t current_bs = clock();
	arr.BubbleSort();
	clock_t finish_bs = clock();*/
	arr.Print();
	clock_t current_qs = clock(); //Initial time
	arr.QuickSort(arr.GetPointer(), 0, size - 1);
	clock_t finish_qs = clock(); //Finish time
	arr.Print();
	

	//For time output

	/*cout << "bubble - " <<(double)(finish_bs - current_bs) / CLOCKS_PER_SEC << endl;*/
	cout << "quick - " << (double)(finish_qs - current_qs) / CLOCKS_PER_SEC << endl;
	/*cout << finish_time - current_time;*/
	

	//For char array

	/*const int size = 14; 
	char arr[size] = {'F','d','o','\\','!','k','d','j','a','F','1','3','1','}'};
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << '\t';
	}
	cout << endl;
	CountingSort1(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << '\t';
	}*/
	return 0;
}