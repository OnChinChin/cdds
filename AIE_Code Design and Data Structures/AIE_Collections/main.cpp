#include<iostream>
#include <list>
#include"LinkedList.h"


int main(int argc, char** argv)
{
  
    /*LinkedList<int> myList = { 10, 20, 30, 40, 50, 60 };
    myList.Clear();
    for (auto& i : myList)
    {
        std::cout << i << std::endl;
    }*/
    //std::cout << "Count: " << myList.Count() << "\t\t Expected: 6" << std::endl;

    //myList.PushBack(70);
    //std::cout << "Count: " << myList.Count() << "\t\t Expected: 7" << std::endl;

    //myList.PushFront(5);
    //std::cout << "Count: " << myList.Count() << "\t\t Expected: 8" << std::endl;

    //myList.PopBack();
    //std::cout << "Count: " << myList.Count() << "\t\t Expected: 7" << std::endl;

    //myList.PopFront();
    //std::cout << "Count: " << myList.Count() << "\t\t Expected: 6" << std::endl;

    //myList.Remove(std::find(myList.begin(), myList.end(), 30));
    //std::cout << "Count: " << myList.Count() << "\t\t Expected: 5" << std::endl;

    //myList.PopBack();
    //myList.PopBack();
    //myList.PopBack();
    //myList.PopBack();
    //myList.PopBack();
    //std::cout << "Count: " << myList.Count() << "\t\t Expected: 0" << std::endl;





    LinkedList<int> myList;

    myList.PushBack(10);
    myList.PushBack(20);
    myList.PushBack(30);

    myList.PushFront(5);
    myList.PushFront(4);
    myList.PushFront(3);

    


    // loop forward through each node in the linked list - print its value
    LinkedList<int>::Node* fIter = myList.FirstNode();
    while (fIter != nullptr)
    {
        std::cout << fIter->value << std::endl;
        fIter = fIter->next;
    }

    std::cout << std::endl << std::endl;

    // loop backward through the linked list - print its value
    LinkedList<int>::Node* rIter = myList.LastNode();
    while (rIter != nullptr)
    {
        std::cout << rIter->value << std::endl;
        rIter = rIter->prev;
    }
}