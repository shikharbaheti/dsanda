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

    cout << "///// CREATING COLLECTION 1 FROM USER INPUT /////" << endl;
    Collection input1;
    string filename1 = "stress_balls.data";
    ifstream file1(filename1);
    file1 >> input1;
    input1.print_items();
    cout << endl;
    cout << endl;
    cout << "///// CREATING COLLECTION 2 FROM USER INPUT /////" << endl;
    Collection input2;
    string filename2 = "stress_balls2.data";
    ifstream file2(filename2);
    file2 >> input2;
    input2.print_items();
    cout << endl;
    cout << endl;

    cout << "///// SORTING COLLECTION 1 AND STATS/////" << endl;
    sort_by_size(input1, Sort_choice::bubble_sort);
    input1.print_items();
    cout << endl;
    cout << "The number of red stress balls in Collection 1: " << input1.total_items(Stress_ball_colors::red) << endl;
    cout << "The number of blue stress balls in Collection 1: " << input1.total_items(Stress_ball_colors::blue) << endl;
    cout << "The number of yellow stress balls in Collection 1: " << input1.total_items(Stress_ball_colors::yellow) << endl;
    cout << "The number of green stress balls in Collection 1: " << input1.total_items(Stress_ball_colors::green) << endl;
    cout << "The total number of stress balls in Collection 1: " << input1.total_items() << endl;
    cout << endl;

    cout << "///// SORTING COLLECTION 2 AND STATS/////" << endl;
    sort_by_size(input2, Sort_choice::bubble_sort);
    input2.print_items();
    cout << endl;
    cout << "The number of red stress balls in Collection 2: " << input2.total_items(Stress_ball_colors::red) << endl;
    cout << "The number of blue stress balls in Collection 2: " << input2.total_items(Stress_ball_colors::blue) << endl;
    cout << "The number of yellow stress balls in Collection 2: " << input2.total_items(Stress_ball_colors::yellow) << endl;
    cout << "The number of green stress balls in Collection 2: " << input2.total_items(Stress_ball_colors::green) << endl;
    cout << "The total number of stress balls in Collection 2: " << input2.total_items() << endl;
    cout << endl;

    cout << "///// UNION OF COLLECTION 1 AND TWO/////" << endl;
    Collection unionCollection = make_union(input1, input2);
    unionCollection.print_items();
    cout << endl;
    cout << "The total number of stress balls in Union with same qualities: 0" << endl;
    cout << "The total number of stress balls in Union: " << unionCollection.total_items() << endl;
    cout << endl;

    cout << "///// SWAPPING ONE AND TWO/////" << endl;
    swap(input1, input2);
    cout << "OUTPUTTING INPUT 1 WHO HAS INPUT 2 NOW" << endl;
    input1.print_items();
    cout << endl;
    cout << "OUTPUTTING INPUT 2 WHO HAS INPUT 1 NOW" << endl;
    input2.print_items();
    cout << endl;
}
