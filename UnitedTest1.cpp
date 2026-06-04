#include "CppUnitTest.h"
#include "LinkedList.h"
#include "node.h"
#include <sstream>
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListUnitTests
{
    TEST_CLASS(NodeTests)
    {
    public:
        TEST_METHOD(ConstructorCreatesNode)
        {
            Node node(10);

            Assert::AreEqual(10, node.value);
            Assert::IsTrue(node.next == nullptr);
        }
    };

    TEST_CLASS(LinkedListConstructorsTests)
    {
    public:
        TEST_METHOD(DefaultConstructorCreatesEmptyList)
        {
            LinkedList list;

            Assert::IsTrue(list.isEmpty());
            Assert::AreEqual(static_cast<std::size_t>(0), list.getSize());
            Assert::AreEqual(std::string("[]"), list.ToString());
        }

        TEST_METHOD(InitializerListConstructorCreatesList)
        {
            LinkedList list = { 1, 2, 3 };

            Assert::AreEqual(static_cast<std::size_t>(3), list.getSize());
            Assert::AreEqual(std::string("[1, 2, 3]"), list.ToString());
        }

        TEST_METHOD(CopyConstructorCreatesIndependentCopy)
        {
            LinkedList source = { 1, 2, 3 };
            LinkedList copy(source);

            copy[0] = 100;

            Assert::AreEqual(1, source[0]);
            Assert::AreEqual(100, copy[0]);
        }

        TEST_METHOD(MoveConstructorMovesData)
        {
            LinkedList source = { 1, 2, 3 };
            LinkedList moved(std::move(source));

            Assert::AreEqual(std::string("[1, 2, 3]"), moved.ToString());
            Assert::IsTrue(source.isEmpty());
        }
    };

    TEST_CLASS(LinkedListAssignmentTests)
    {
    public:
        TEST_METHOD(CopyAssignmentCopiesData)
        {
            LinkedList source = { 4, 5, 6 };
            LinkedList result;

            result = source;

            Assert::AreEqual(source.ToString(), result.ToString());
        }

        TEST_METHOD(MoveAssignmentMovesData)
        {
            LinkedList source = { 4, 5, 6 };
            LinkedList result;

            result = std::move(source);

            Assert::AreEqual(std::string("[4, 5, 6]"), result.ToString());
            Assert::IsTrue(source.isEmpty());
        }
    };

    TEST_CLASS(LinkedListModificationTests)
    {
    public:
        TEST_METHOD(PushBackAddsElementToEnd)
        {
            LinkedList list;

            list.push_back(1);
            list.push_back(2);

            Assert::AreEqual(std::string("[1, 2]"), list.ToString());
        }

        TEST_METHOD(PushFrontAddsElementToStart)
        {
            LinkedList list = { 2, 3 };

            list.push_front(1);

            Assert::AreEqual(std::string("[1, 2, 3]"), list.ToString());
        }

        TEST_METHOD(InsertAddsElementByIndex)
        {
            LinkedList list = { 1, 3 };

            list.insert(1, 2);

            Assert::AreEqual(std::string("[1, 2, 3]"), list.ToString());
        }

        TEST_METHOD(PopBackRemovesLastElement)
        {
            LinkedList list = { 1, 2, 3 };

            list.pop_back();

            Assert::AreEqual(std::string("[1, 2]"), list.ToString());
        }

        TEST_METHOD(PopFrontRemovesFirstElement)
        {
            LinkedList list = { 1, 2, 3 };

            list.pop_front();

            Assert::AreEqual(std::string("[2, 3]"), list.ToString());
        }

        TEST_METHOD(EraseRemovesElementByIndex)
        {
            LinkedList list = { 1, 2, 3 };

            list.erase(1);

            Assert::AreEqual(std::string("[1, 3]"), list.ToString());
        }

        TEST_METHOD(RemoveDeletesFirstMatchingValue)
        {
            LinkedList list = { 1, 2, 3 };

            const bool removed = list.remove(2);

            Assert::IsTrue(removed);
            Assert::AreEqual(std::string("[1, 3]"), list.ToString());
        }

        TEST_METHOD(ModifyChangesValueByIndex)
        {
            LinkedList list = { 1, 2, 3 };

            list.modify(1, 20);

            Assert::AreEqual(20, list[1]);
        }

        TEST_METHOD(ClearRemovesAllElements)
        {
            LinkedList list = { 1, 2, 3 };

            list.clear();

            Assert::IsTrue(list.isEmpty());
            Assert::AreEqual(std::string("[]"), list.ToString());
        }
    };

    TEST_CLASS(LinkedListSearchTests)
    {
    public:
        TEST_METHOD(FindReturnsIndexOfValue)
        {
            LinkedList list = { 10, 20, 30 };

            Assert::AreEqual(1, list.find(20));
            Assert::AreEqual(-1, list.find(100));
        }

        TEST_METHOD(ContainsChecksValue)
        {
            LinkedList list = { 10, 20, 30 };

            Assert::IsTrue(list.contains(20));
            Assert::IsFalse(list.contains(100));
        }
    };

    TEST_CLASS(LinkedListOperatorsTests)
    {
    public:
        TEST_METHOD(IndexOperatorReturnsElement)
        {
            LinkedList list = { 7, 8, 9 };

            Assert::AreEqual(8, list[1]);
        }

        TEST_METHOD(ConstIndexOperatorReturnsElement)
        {
            const LinkedList list = { 7, 8, 9 };

            Assert::AreEqual(8, list[1]);
        }

        TEST_METHOD(OutputOperatorWritesListToStream)
        {
            LinkedList list = { 1, 2, 3 };
            std::ostringstream output;

            output << list;

            Assert::AreEqual(std::string("[1, 2, 3]"), output.str());
        }

        TEST_METHOD(InputOperatorReadsListFromStream)
        {
            LinkedList list;
            std::istringstream input("3 5 6 7");

            input >> list;

            Assert::AreEqual(std::string("[5, 6, 7]"), list.ToString());
        }
    };

    TEST_CLASS(LinkedListExceptionTests)
    {
    public:
        TEST_METHOD(IndexOperatorThrowsWhenIndexIsInvalid)
        {
            LinkedList list = { 1, 2, 3 };

            Assert::ExpectException<std::out_of_range>([&list] { list[10]; });
        }

        TEST_METHOD(ConstIndexOperatorThrowsWhenIndexIsInvalid)
        {
            const LinkedList list = { 1, 2, 3 };

            Assert::ExpectException<std::out_of_range>([&list] { list[10]; });
        }

        TEST_METHOD(InsertThrowsWhenIndexIsInvalid)
        {
            LinkedList list = { 1, 2, 3 };

            Assert::ExpectException<std::out_of_range>([&list] { list.insert(10, 100); });
        }

        TEST_METHOD(EraseThrowsWhenIndexIsInvalid)
        {
            LinkedList list = { 1, 2, 3 };

            Assert::ExpectException<std::out_of_range>([&list] { list.erase(10); });
        }

        TEST_METHOD(PopBackThrowsWhenListIsEmpty)
        {
            LinkedList list;

            Assert::ExpectException<std::out_of_range>([&list] { list.pop_back(); });
        }

        TEST_METHOD(PopFrontThrowsWhenListIsEmpty)
        {
            LinkedList list;

            Assert::ExpectException<std::out_of_range>([&list] { list.pop_front(); });
        }
    };
}
