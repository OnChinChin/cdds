#include "pch.h"
#include "CppUnitTest.h"

#include "../AIE_Collections/LinkedList.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AIEUnitTests
{
	TEST_CLASS(AIEUnitTests)
	{
	public:
		
        TEST_METHOD(Can_Create_Empty_List)
        {
            // Setup
            // -------------------------------
            LinkedList<int> list;

            // -------------------------------
            // Below we assert, check our expectations match

            // First and Last node in an empty list should be null
            Assert::IsNull(list.FirstNode());
            Assert::IsNull(list.LastNode());

            // the IsEmpty function should return true
            //Assert::IsTrue(list.IsEmpty());

            // for an empty list begin and end should be the same
            Assert::IsTrue(list.begin() == list.end());

            // an empty list should have a count of 0
            Assert::IsTrue(list.Count() == 0);
        }

        TEST_METHOD(Can_Create_List_With_Initialiser_List)
        {
            // Setup
            // -------------------------------
            LinkedList<int> list = { 10, 20, 30, 40 };

            // -------------------------------
            // Below we assert, check our expectations match


            // First and Last nodes should not be null
            Assert::IsNotNull(list.FirstNode());
            Assert::IsNotNull(list.LastNode());

            // First and Last nodes should have a value of 10 and 40
            Assert::AreEqual(list.FirstNode()->value, 10);
            Assert::AreEqual(list.LastNode()->value, 40);

            // The IsEmpty function should return false
            //Assert::IsFalse(list.IsEmpty());

            // should be able to iterate through each item
            // lets check the values are as we expect
            int arr[5] = { 10, 20, 30, 40 };
            int index = 0;

            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
                // de-reference iter to get its value
                // compare it against the value in our array
                Assert::AreEqual(*iter, arr[index]);
                index++;
            }
        }

        TEST_METHOD(Popfront)
        {
            LinkedList<int> list = { 10, 20, 30, 40 };

            list.PopFront();

            Assert::IsNotNull(list.FirstNode());
            Assert::IsNotNull(list.LastNode());

            // First and Last nodes should have a value of 10 and 40
            Assert::AreEqual(list.FirstNode()->value, 20);
            Assert::AreEqual(list.LastNode()->value, 40);

            // The IsEmpty function should return false
            //Assert::IsFalse(list.IsEmpty());

            // should be able to iterate through each item
            // lets check the values are as we expect
            int arr[4] = { 20, 30, 40 };
            int index = 0;

            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
                // de-reference iter to get its value
                // compare it against the value in our array
                Assert::AreEqual(*iter, arr[index]);
                index++;
            }

        }

        TEST_METHOD(PopBack)
        {
            LinkedList<int> list = { 10, 20, 30, 40 };

            list.PopBack();

            Assert::IsNotNull(list.FirstNode());
            Assert::IsNotNull(list.LastNode());

            // First and Last nodes should have a value of 10 and 40
            Assert::AreEqual(list.FirstNode()->value, 10);
            Assert::AreEqual(list.LastNode()->value, 30);

            // The IsEmpty function should return false
            //Assert::IsFalse(list.IsEmpty());

            // should be able to iterate through each item
            // lets check the values are as we expect
            int arr[4] = { 10, 20, 30 };
            int index = 0;

            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
                // de-reference iter to get its value
                // compare it against the value in our array
                Assert::AreEqual(*iter, arr[index]);
                index++;
            }
        }

        TEST_METHOD(PushBackandPushFront)
        {
            LinkedList<int> list;

            list.PushBack(10);
            list.PushBack(20);
            list.PushBack(30);
            list.PushFront(5);
            

            Assert::AreEqual(list.FirstNode()->value, 5);
            Assert::AreEqual(list.LastNode()->value, 30);


            // The IsEmpty function should return false
            //Assert::IsFalse(list.IsEmpty());

            // should be able to iterate through each item
            // lets check the values are as we expect
            int arr[5] = { 5, 10, 20, 30, };
            int index = 0;

            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
                // de-reference iter to get its value
                // compare it against the value in our array
                Assert::AreEqual(*iter, arr[index]);
                index++;
            }
        }

        TEST_METHOD(Clear)
        {
            LinkedList<int> list = { 10, 20, 30, 40 };

            list.Clear();

  

            // First and Last nodes should have a value of 10 and 40
            Assert::AreEqual(list.FirstNode()->value, 1);
            Assert::AreEqual(list.LastNode()->value, 30);

            // The IsEmpty function should return false
            //Assert::IsFalse(list.IsEmpty());

            // should be able to iterate through each item
            // lets check the values are as we expect
            int arr[4] = { 10, 20, 30 };
            int index = 0;

            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
                // de-reference iter to get its value
                // compare it against the value in our array
                Assert::AreEqual(*iter, arr[index]);
                index++;
            }
        }

    };
}
