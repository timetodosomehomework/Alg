#include "pch.h"
#include "CppUnitTest.h"
#include "../kurs/CalcMethods.cpp"
#include "../kurs/ListMethods.cpp"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace kurstest
{
	TEST_CLASS(kurstest)
	{
	public:

		Calculator calc;

		TEST_METHOD(read_if_correct)
		{
			string str = "2+3$";
			Assert::AreEqual(true, calc.read(str));
		}
		TEST_METHOD(read_if_incorrect)
		{
			string str = ")($";
			Assert::AreEqual(false, calc.read(str));
			str = ")3+7$";
			Assert::AreEqual(false, calc.read(str));
			str = "1.25.3+4$";
			Assert::AreEqual(false, calc.read(str));
			str = "25-*589$";
			Assert::AreEqual(false, calc.read(str));
		}
		TEST_METHOD(calculation)
		{
			string str = "3^3/2$";
			calc.read(str);
			calc.toPrefix();
			Assert::AreEqual((double)13.5, calc.calculate());
		}
	};
}
