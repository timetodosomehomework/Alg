#include "pch.h"
#include "CppUnitTest.h"
#include "../AlgSort/Array.h"
#include "../AlgSort/AlgSort.cpp"
#include "../AlgSort/main.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlgSortTest
{
	TEST_CLASS(AlgSortTest)
	{
	public:
		
		Array* arr;

		TEST_METHOD_INITIALIZE(setUp) //Before each test
		{
			arr = new Array(10);
		}
		TEST_METHOD_CLEANUP(cleanUp) //After each test
		{
			delete arr;
		}
		TEST_METHOD(BinarySearch) //Test of binary search
		{
			arr->Set();
			Assert::AreEqual(0, (int)arr->BinarySearch(2));
		}
		TEST_METHOD(QuickSort) //Test of quick sort
		{
			Array arr1(5);
			arr1.QuickSort(arr1.GetPointer(), 0, 4);
			Assert::IsTrue(arr1.GetPointer()[3] < arr1.GetPointer()[4]);
			Assert::IsTrue(arr1.GetPointer()[2] < arr1.GetPointer()[3]);
			Assert::IsTrue(arr1.GetPointer()[1] < arr1.GetPointer()[2]);
			Assert::IsTrue(arr1.GetPointer()[0] < arr1.GetPointer()[1]);
		}
		TEST_METHOD(BubbleSort) //Test of bubble sort
		{
			Array arr1(5);
			arr1.BubbleSort();
			Assert::IsTrue(arr1.GetPointer()[3] < arr1.GetPointer()[4]);
			Assert::IsTrue(arr1.GetPointer()[2] < arr1.GetPointer()[3]);
			Assert::IsTrue(arr1.GetPointer()[1] < arr1.GetPointer()[2]);
			Assert::IsTrue(arr1.GetPointer()[0] < arr1.GetPointer()[1]);
		}
		TEST_METHOD(BogoSort) //Test of bogosort
		{
			Array arr1(4);
			arr1.BogoSort();
			Assert::IsTrue(arr1.GetPointer()[2] < arr1.GetPointer()[3]);
			Assert::IsTrue(arr1.GetPointer()[1] < arr1.GetPointer()[2]);
			Assert::IsTrue(arr1.GetPointer()[0] < arr1.GetPointer()[1]);
		}
		TEST_METHOD(CountingSort) //Test of counting sort
		{
			char arr2[5] = { 'j','K','5','!','K' };
			CountingSort1(arr2, 5);
			Assert::IsTrue(arr2[3] < arr2[4]);
			Assert::IsTrue(arr2[2] < arr2[3]);
			Assert::IsTrue(arr2[1] < arr2[2]);
			Assert::IsTrue(arr2[0] < arr2[1]);
		}
	};
}
