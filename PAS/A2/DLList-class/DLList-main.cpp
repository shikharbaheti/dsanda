// test of the DLList class

#include <iostream>
#include <cstdlib>
#include "DLList.h"

using namespace std;

int main()
{
     // Construct a linked list with header & trailer
     cout << "Create a new list" << endl;
     DLList dll;
     try
     {
          cout << "list: " << dll << endl
               << endl;
     }
     catch (runtime_error &e)
     {
          cerr << e.what() << endl
               << endl;
     }

     cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
     for (int i = 10; i <= 100; i += 10)
     {
          dll.insert_last(i);
     }
     try
     {
          cout << "list: " << dll << endl
               << endl;
     }
     catch (runtime_error &e)
     {
          cerr << e.what() << endl
               << endl;
     }

     cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
     for (int i = 10; i <= 100; i += 10)
     {
          dll.insert_first(i);
     }
     try
     {
          cout << "list: " << dll << endl
               << endl;
     }
     catch (runtime_error &e)
     {
          cerr << e.what() << endl
               << endl;
     }

     cout << "Copy to a new list" << endl;
     DLList dll2(dll);
     cout << "list2: " << dll2 << endl
          << endl;

     cout << "Assign to another new list" << endl;
     DLList dll3;
     dll3 = dll;
     cout << "list3: " << dll3 << endl
          << endl;

     cout << "Delete the last 10 nodes" << endl;
     for (int i = 0; i < 10; i++)
     {
          dll.remove_last();
     }
     cout << "list: " << dll << endl
          << endl;

     cout << "Delete the first 10 nodes" << endl;
     try
     {
          for (int i = 0; i < 10; i++)
          {
               dll.remove_first();
          }
     }
     catch (runtime_error &e)
     {
          cerr << e.what() << endl
               << endl;
     }
     try
     {
          cout << "list: " << dll << endl
               << endl;
     }
     catch (runtime_error &e)
     {
          cerr << e.what() << endl
               << endl;
     }
     // Check the other two lists
     cout << "Make sure the other two lists are not affected." << endl;
     cout << "list2: " << dll2 << endl;
     cout << "list3: " << dll3 << endl
          << endl;

     cout << "////// PERFORMING ADDITIONAL TESTS//////" << endl
          << endl;

     cout << "////// TESTING INSERT AFTER//////" << endl;
     cout << "Getting a P value on list 2 to test insert_after() \n";
     DLListNode *list2pValue = dll2.first_node()->next->next;
     cout << "The value (obj) at selected P value: " << list2pValue->obj << endl;
     cout << "Inserting a value of 17 after our P (" << list2pValue->obj << ") value " << endl;
     dll2.insert_after(*list2pValue, 17);
     cout << "The new list two after inserting value: " << endl;
     cout << dll2 << endl
          << endl;

     cout << "////// TESTING INSERT BEFORE//////" << endl;
     cout << "Getting a P value on list 3 to test insert_before() \n";
     DLListNode *list3pValue = dll3.first_node()->next->next->next->next;
     cout << "The value (obj) at selected P value: " << list3pValue->obj << endl;
     cout << "Inserting a value of 11 before our P (" << list3pValue->obj << ") value " << endl;
     dll3.insert_before(*list3pValue, 11);
     cout << "The new list two after inserting value: " << endl;
     cout << dll3 << endl
          << endl;

     cout << "////// TESTING REMOVE AFTER//////" << endl;
     cout << "Getting a P value on list 2 to test remove_after() \n";
     DLListNode *list21pValue = dll2.first_node()->next->next->next->next;
     cout << "The value (obj) at selected P value: " << list21pValue->obj << endl;
     cout << "Removing and returning node after our P (" << list21pValue->obj << ") value " << endl;
     cout << "Removed value: " << dll2.remove_after(*list21pValue) << endl;
     cout << "The new list two after removing value: " << endl;
     cout << dll2 << endl
          << endl;

     cout << "////// TESTING REMOVE BEFORE//////" << endl;
     cout << "Getting a P value on list 3 to test remove_after() \n";
     DLListNode *list31pValue = dll3.first_node()->next->next->next->next->next->next->next;
     cout << "The value (obj) at selected P value: " << list31pValue->obj << endl;
     cout << "Removing and returning node before our P (" << list31pValue->obj << ") value " << endl;
     cout << "Removed value: " << dll3.remove_before(*list31pValue) << endl;
     cout << "The new list two after removing value: " << endl;
     cout << dll3 << endl
          << endl;

     cout << "////// TESTING REMOVE BEFORE HEADER//////" << endl;
     DLListNode *list22pValue = dll2.first_node()->prev;
     try
     {
          cout << "Removed value: " << dll2.remove_before(*list22pValue) << endl;
     }
     catch (runtime_error &e)
     {
          cerr << e.what() << endl
               << endl;
     }

     cout << "////// TESTING REMOVE AFTER TRAILER//////" << endl;
     DLListNode *list32pValue = dll3.theTrailerPointer();
     try
     {
          cout << "Removed value: " << dll3.remove_after(*list32pValue) << endl;
     }
     catch (runtime_error &e)
     {
          cerr << e.what() << endl
               << endl;
     }

     cout << "////// TESTING MOVE ASSIGNMENT//////" << endl;
     DLList dll4 = move(dll2);
     try
     {
          cout << "list DLL4: " << dll4 << endl
               << endl;
     }
     catch (runtime_error &e)
     {
          cerr << e.what() << endl
               << endl;
     }

     cout << "////// TESTING MOVE CONSTRUCTOR//////" << endl;
     DLList dll5(move(dll3));
     try
     {
          cout << "list DLL5: " << dll5 << endl
               << endl;
     }
     catch (runtime_error &e)
     {
          cerr << e.what() << endl
               << endl;
     }

     return 0;
}
