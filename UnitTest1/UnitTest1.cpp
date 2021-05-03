#include "pch.h"
#include "CppUnitTest.h"
#include"../аистд_ЛР2/Huffman.h"
#include<string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Decode)
		{
			string str = "Bad boys, bad boys what you gonna do when they come for you?";
			huffman a(str);
			string decoded = a.deCode();
			Assert::AreEqual(str, decoded);
		}
		TEST_METHOD(Code)
		{
			string str = "abbccc"; // a- 00, b - 01, c - 1
			huffman a(str);
			string sup = "000101111";
			string coded = a.res();
			Assert::AreEqual(sup, coded);
		}
		TEST_METHOD(Code2)
		{
			string str = "ab babababa ?"; // a - 5 times, b - 5 times, ' ' - 2 times, ? - 1 time.
			huffman a(str);
			string sup = "110101011011011011101100"; // b - 0, a - 11, ' ' - 101, ? - 100
			string coded = a.res();
			Assert::AreEqual(sup, coded);
		}
	};
}
