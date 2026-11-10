#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08_1_Char/Lab_08_1_Char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab081Char
{
    TEST_CLASS(UnitTestLab081Char)
    {
    public:
        TEST_METHOD(TestMethodCharFunctions)
        {
            char testStr1[] = "aaaaXbbbb";
            Assert::IsTrue(Include(testStr1));

            char testStr2[50] = "a1111b2222c";
            Change(testStr2);
            Assert::AreEqual("a**b**c", testStr2);
        }
    };
}