#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Collection.h"
#include "Stress_ball.h"
#include <fstream>
#include <string>

using namespace std;

int main()
{
    srand(time(NULL));
    cout << "We are now running tests on Collection class." << endl;
    cout << "////////////////// DEFAULT CONSTRUCTOR TEST WITH ONE ARGUMENT OF CAPACITY //////////////////" << endl;
    int numbs = 12;
    Collection test = numbs;
    // cout << "The capacity initially is: " << test.get_capacity() << endl;
    // cout << "The size is intially: " << test.get_size() << endl;
    for (int i = 0; i < numbs; i++)
    {
        test.insert_item(Stress_ball());
    }

    cout << "Printing items: \n";
    test.print_items();
    cout << endl;
    // cout << "The capacity finally is: " << test.get_capacity() << endl;
    // cout << "The size is finally: " << test.get_size() << endl;
    cout << endl;
    // cout << "////////////////// Running move constructor //////////////////" << endl;
    // Collection test3(move(test));
    // test3.print_items();
    // cout << endl;
    cout << "////////////////// Running move assignment //////////////////" << endl;
    Collection test4;
    test4 = move(test);
    test4.print_items();
    cout << endl;
    // cout << "The capacity for Test 4 (move) is: " << test4.get_capacity() << endl;
    // cout << "The size for Test 4 (move): " << test4.get_size() << endl;
    cout << endl;
    cout << "////////////////// TESTING ISTREAM //////////////////" << endl;
    Collection input1;
    string filename1 = "stress_balls.data";
    ifstream file1(filename1);
    file1 >> input1;
    input1.print_items();
    cout << endl;
    // cout << input1.get_size() << endl;
    // cout << input1.get_capacity() << endl;
    cout << endl;
    cout << "////////////////// TESTING ISTREAM 2 //////////////////" << endl;
    Collection input2;
    string filename2 = "stress_balls2.data";
    ifstream file2(filename2);
    file2 >> input2;
    input2.print_items();
    cout << endl;
    // cout << input2.get_size() << endl;
    // cout << input2.get_capacity() << endl;
    cout << endl;
    cout << "////////////////// TESTING UNION //////////////////" << endl;
    Collection unionTest;
    unionTest = make_union(input1, input2);
    unionTest.print_items();
    cout << endl;
    // cout << unionTest.get_size() << endl;
    // cout << unionTest.get_capacity() << endl;
    cout << endl;
    cout << "////////////////// TESTING SORTING //////////////////" << endl;
    sort_by_size(unionTest, Sort_choice::selection_sort);
    unionTest.print_items();
    cout << endl;
    sort_by_size(unionTest, Sort_choice::bubble_sort);
    unionTest.print_items();
    cout << endl;
    sort_by_size(unionTest, Sort_choice::insertion_sort);
    unionTest.print_items();
    cout << endl;
    // cout << "////////////////// TESTING SWAP //////////////////" << endl;
    // swap(input1, input2);
    // cout << "OUTPUTTING INPUT 1 WHO HAS INPUT 2 NOW" << endl;
    // input1.print_items();
    // cout << "OUTPUTTING INPUT 2 WHO HAS INPUT 1 NOW" << endl;
    // input2.print_items();
}
