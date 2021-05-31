#include<iostream>
#include <list>
#include"LinkedList.h"


int main(int argc, char** argv)
{
  
    LinkedList<int> myList = { 10, 20, 30, 40, 50, 60 };
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 6" << std::endl;

    myList.PushBack(70);
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 7" << std::endl;

    myList.PushFront(5);
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 8" << std::endl;

    myList.PopBack();
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 7" << std::endl;

    myList.PopFront();
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 6" << std::endl;

    myList.Remove(std::find(myList.begin(), myList.end(), 30));
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 5" << std::endl;

    myList.PopBack();
    myList.PopBack();
    myList.PopBack();
    myList.PopBack();
    myList.PopBack();
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 0" << std::endl;





    //LinkedList<int> myList;

    //myList.PushBack(10);
    //myList.PushBack(20);
    //myList.PushBack(30);

    //myList.PushFront(5);
    //myList.PushFront(4);
    //myList.PushFront(3);

    //myList.PopFront(); // should remove 3
    //myList.PopBack(); // should remove 30

    //// loop through each node in the linked list
    //// print its value
    //LinkedList<int>::Node* iter = myList.FirstNode();
    //while (iter != nullptr)
    //{
    //    std::cout << iter->value << std::endl <<std::endl;
    //    iter = iter->next;
    //}

    /*LinkedList<int> myList = { 10, 20, 30, 40, 50, 60 };

     Remove the value 40 - get the iterator
    auto iter = std::find(myList.begin(), myList.end(), 10);

     remove the node
    myList.Remove(iter);

    for (auto& iter : myList)
    {
        std::cout << iter << std::endl;
    }*/
}