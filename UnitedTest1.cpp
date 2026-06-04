#include "CppUnitTest.h"

#include <sstream>
#include <stdexcept>
#include <utility>

#include "LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListUnitTests {
    TEST_CLASS(NodeTests) {
    public:
        TEST_METHOD(ConstructorCreatesNodeWithValue) {
            Node node(15);

            Assert::AreEqual(15, node.value);
            Assert::IsNull(node.next);
        }
    };

    TEST_CLASS(LinkedListTests) {
    public:
        TEST_METHOD(DefaultConstructorCreatesEmptyList) {
            LinkedList list;

            Assert::IsTrue(list.isEmpty());
            Assert::AreEqual(static_cast<std::size_t>(0), list.getSize());
            Assert::AreEqual(std::string("[]"), list.ToString());
        }

        TEST_METHOD(InitializerListConstructorCreatesList) {
            LinkedList list = { 1, 2, 3 };

            Assert::AreEqual(static_cast<std::size_t>(3), list.getSize());
            Assert::AreEqual(std::string("[1, 2, 3]"), list.ToString());
        }

        TEST_METHOD(CopyConstructorCreatesIndependentCopy) {
            LinkedList list = { 1, 2, 3 };
            LinkedList copy(list);

            copy[0] = 100;

            Assert::AreEqual(1, list[0]);
            Assert::AreEqual(100, copy[0]);
        }

        TEST_METHOD(MoveConstructorMovesData) {
            LinkedList list = { 1, 2, 3 };
            LinkedList moved(std::move(list));

            Assert::AreEqual(std::string("[1, 2, 3]"), moved.ToString());
            Assert::IsTrue(list.isEmpty());
        }

        TEST_METHOD(CopyAssignmentCopiesData) {
            LinkedList list = { 4, 5, 6 };
            LinkedList assigned;

            assigned = list;

            Assert::AreEqual(list.ToString(), assigned.ToString());
        }

        TEST_METHOD(MoveAssignmentMovesData) {
            LinkedList list = { 7, 8, 9 };
            LinkedList assigned;

            assigned = std::move(list);

            Assert::AreEqual(std::string("[7, 8, 9]"), assigned.ToString());
            Assert::IsTrue(list.isEmpty());
        }

        TEST_METHOD(PushBackAddsElementToEnd) {
            LinkedList list;

            list.push_back(10);
            list.push_back(20);

            Assert::AreEqual(std::string("[10, 20]"), list.ToString());
        }

        TEST_METHOD(PushFrontAddsElementToBeginning) {
            LinkedList list;

            list.push_front(10);
            list.push_front(20);

            Assert::AreEqual(std::string("[20, 10]"), list.ToString());
        }

        TEST_METHOD(InsertAddsElementByIndex) {
            LinkedList list = { 1, 3 };

            list.insert(1, 2);

            Assert::AreEqual(std::string("[1, 2, 3]"), list.ToString());
        }

        TEST_METHOD(PopBackRemovesLastElement) {
            LinkedList list = { 1, 2, 3 };

            list.pop_back();

            Assert::AreEqual(std::string("[1, 2]"), list.ToString());
        }

        TEST_METHOD(PopFrontRemovesFirstElement) {
            LinkedList list = { 1, 2, 3 };

            list.pop_front();

            Assert::AreEqual(std::string("[2, 3]"), list.ToString());
        }

        TEST_METHOD(EraseRemovesElementByIndex) {
            LinkedList list = { 1, 2, 3 };

            list.erase(1);

            Assert::AreEqual(std::string("[1, 3]"), list.ToString());
        }

        TEST_METHOD(RemoveDeletesElementByValue) {
            LinkedList list = { 1, 2, 3 };

            const bool removed = list.remove(2);

            Assert::IsTrue(removed);
            Assert::AreEqual(std::string("[1, 3]"), list.ToString());
        }

        TEST_METHOD(FindReturnsIndexOrMinusOne) {
            LinkedList list = { 10, 20, 30 };

            Assert::AreEqual(1, list.find(20));
            Assert::AreEqual(-1, list.find(100));
        }

        TEST_METHOD(ContainsChecksValuePresence) {
            LinkedList list = { 10, 20, 30 };

            Assert::IsTrue(list.contains(20));
            Assert::IsFalse(list.contains(100));
        }

        TEST_METHOD(ModifyChangesElementByIndex) {
            LinkedList list = { 1, 2, 3 };

            list.modify(1, 99);

            Assert::AreEqual(std::string("[1, 99, 3]"), list.ToString());
        }

        TEST_METHOD(IndexOperatorReturnsElement) {
            LinkedList list = { 1, 2, 3 };

            list[1] = 22;

            Assert::AreEqual(22, list[1]);
        }

        TEST_METHOD(ConstIndexOperatorReturnsElement) {
            const LinkedList list = { 1, 2, 3 };

            Assert::AreEqual(2, list[1]);
        }

        TEST_METHOD(ClearRemovesAllElements) {
            LinkedList list = { 1, 2, 3 };

            list.clear();

            Assert::IsTrue(list.isEmpty());
            Assert::AreEqual(static_cast<std::size_t>(0), list.getSize());
        }

        TEST_METHOD(OutputOperatorWritesListToStream) {
            LinkedList list = { 1, 2, 3 };
            std::ostringstream output;

            output << list;

            Assert::AreEqual(std::string("[1, 2, 3]"), output.str());
        }

        TEST_METHOD(InputOperatorReadsListFromStream) {
            LinkedList list;
            std::istringstream input("3 5 6 7");

            input >> list;

            Assert::AreEqual(std::string("[5, 6, 7]"), list.ToString());
        }

        TEST_METHOD(InvalidIndexThrowsException) {
            LinkedList list = { 1, 2, 3 };

            Assert::ExpectException<std::out_of_range>([&list]() {
                list[100];
            });
        }

        TEST_METHOD(ModifyInvalidIndexThrowsException) {
            LinkedList list = { 1, 2, 3 };

            Assert::ExpectException<std::out_of_range>([&list]() {
                list.modify(10, 100);
            });
        }
    };
}
