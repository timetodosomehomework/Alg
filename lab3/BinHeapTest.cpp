#include "pch.h"
#include "CppUnitTest.h"
#include "../BinHeap/Methods.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinHeapTest
{
	TEST_CLASS(BinHeapTest)
	{
	public:
		Heap* heap;
		TEST_METHOD_INITIALIZE(setUp) //Before each test
		{
			for (int i = 0; i < 10; i++)
			{
				heap->insert(i + 2);
			}
		}
		TEST_METHOD_CLEANUP(cleanUp) //After each test
		{
			delete heap;
		}
		TEST_METHOD(contains) //check if contains working
		{
			Assert::IsTrue(heap->contains(6));
		}
		TEST_METHOD(insert_and_hepify_and_at) //check if insert, at and hepify working
		{
			heap->insert(20);
			Assert::AreEqual(20, heap->at(0));
		}
		TEST_METHOD(remove) //check if remove working
		{
			heap->remove(0);
			Assert::IsFalse(heap->contains(11));
		}
	};
}
