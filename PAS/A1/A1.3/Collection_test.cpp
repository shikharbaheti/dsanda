#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Stress_ball.h"
#include "Jeans.h"
#include <fstream>
#include <string>

using namespace std;
using CollectionSB = Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes>;
using CollectionJN = Collection<Jeans, Jeans_colors, Jeans_sizes>;

void test_stress_balls()
{
    cout << "///// CREATING COLLECTION 1 FROM USER INPUT /////" << endl;
    CollectionSB input1;
    string filename1 = "stress_balls.data";
    ifstream file1(filename1);
    file1 >> input1;
    input1.print_items();
    cout << endl;
    cout << endl;
    cout << "///// CREATING COLLECTION 2 FROM USER INPUT /////" << endl;
    CollectionSB input2;
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
    cout << "The number of small stress balls in Collection 1: " << input1.total_items(Stress_ball_sizes::small) << endl;
    cout << "The number of medium stress balls in Collection 1: " << input1.total_items(Stress_ball_sizes::medium) << endl;
    cout << "The number of large stress balls in Collection 1: " << input1.total_items(Stress_ball_sizes::large) << endl;
    cout << "The total number of stress balls in Collection 1: " << input1.total_items() << endl;
    cout << endl;

    cout << "///// SORTING COLLECTION 2 AND STATS/////" << endl;
    sort_by_size(input2, Sort_choice::selection_sort);
    input2.print_items();
    cout << endl;
    cout << "The number of red stress balls in Collection 2: " << input2.total_items(Stress_ball_colors::red) << endl;
    cout << "The number of blue stress balls in Collection 2: " << input2.total_items(Stress_ball_colors::blue) << endl;
    cout << "The number of yellow stress balls in Collection 2: " << input2.total_items(Stress_ball_colors::yellow) << endl;
    cout << "The number of green stress balls in Collection 2: " << input2.total_items(Stress_ball_colors::green) << endl;
    cout << "The number of small stress balls in Collection 2: " << input2.total_items(Stress_ball_sizes::small) << endl;
    cout << "The number of medium stress balls in Collection 2: " << input2.total_items(Stress_ball_sizes::medium) << endl;
    cout << "The number of large stress balls in Collection 2: " << input2.total_items(Stress_ball_sizes::large) << endl;
    cout << "The total number of stress balls in Collection 2: " << input2.total_items() << endl;
    cout << endl;

    cout << "///// UNION OF COLLECTION 1 AND TWO AND STATS/////" << endl;
    CollectionSB unionCollection = make_union(input1, input2);
    unionCollection.print_items();
    cout << endl;
    cout << "The total number of stress balls in Union: " << unionCollection.total_items() << endl;
    cout << "The number of red stress balls in Union: " << unionCollection.total_items(Stress_ball_colors::red) << endl;
    cout << "The number of blue stress balls in Union: " << unionCollection.total_items(Stress_ball_colors::blue) << endl;
    cout << "The number of yellow stress balls in Union: " << unionCollection.total_items(Stress_ball_colors::yellow) << endl;
    cout << "The number of green stress balls in Union: " << unionCollection.total_items(Stress_ball_colors::green) << endl;
    cout << "The number of small stress balls in Union: " << unionCollection.total_items(Stress_ball_sizes::small) << endl;
    cout << "The number of medium stress balls in Union: " << unionCollection.total_items(Stress_ball_sizes::medium) << endl;
    cout << "The number of large stress balls in Union: " << unionCollection.total_items(Stress_ball_sizes::large) << endl;
    cout << endl;

    cout << "///// SWAPPING ONE AND TWO/////" << endl;
    swap(input1, input2);
    cout << "OUTPUTTING INPUT 1 WHO HAS INPUT 2 NOW" << endl;
    input1.print_items();
    cout << endl;
    cout << "OUTPUTTING INPUT 2 WHO HAS INPUT 1 NOW" << endl;
    input2.print_items();
    cout << endl;

    cout << "///// SORTING COLLECTION 1 AGAIN!/////" << endl;
    sort_by_size(input1, Sort_choice::insertion_sort);
    input1.print_items();
    cout << endl;
};
void test_jeans()
{
    cout << "///// CREATING COLLECTION 1 FROM USER INPUT /////" << endl;
    CollectionJN input1;
    string filename1 = "jeans.data";
    ifstream file1(filename1);
    file1 >> input1;
    input1.print_items();
    cout << endl;
    cout << endl;
    cout << "///// CREATING COLLECTION 2 FROM USER INPUT /////" << endl;
    CollectionJN input2;
    string filename2 = "jeans2.data";
    ifstream file2(filename2);
    file2 >> input2;
    input2.print_items();
    cout << endl;
    cout << endl;

    cout << "///// SORTING COLLECTION 1 AND STATS/////" << endl;
    sort_by_size(input1, Sort_choice::bubble_sort);
    input1.print_items();
    cout << endl;
    cout << "The number of white jeans in Collection 1: " << input1.total_items(Jeans_colors::white) << endl;
    cout << "The number of blue jeans in Collection 1: " << input1.total_items(Jeans_colors::blue) << endl;
    cout << "The number of brown jeans in Collection 1: " << input1.total_items(Jeans_colors::brown) << endl;
    cout << "The number of black jeans in Collection 1: " << input1.total_items(Jeans_colors::black) << endl;
    cout << "The number of tall jeans in Collection 1: " << input1.total_items(Jeans_sizes::tall) << endl;
    cout << "The number of grande jeans in Collection 1: " << input1.total_items(Jeans_sizes::grande) << endl;
    cout << "The number of venti jeans in Collection 1: " << input1.total_items(Jeans_sizes::venti) << endl;
    cout << "The total number of jeans in Collection 1: " << input1.total_items() << endl;
    cout << endl;

    cout << "///// SORTING COLLECTION 2 AND STATS/////" << endl;
    sort_by_size(input2, Sort_choice::selection_sort);
    input2.print_items();
    cout << endl;
    cout << "The number of white jeans in Collection 2: " << input2.total_items(Jeans_colors::white) << endl;
    cout << "The number of blue jeans in Collection 2: " << input2.total_items(Jeans_colors::blue) << endl;
    cout << "The number of brown jeans in Collection 2: " << input2.total_items(Jeans_colors::brown) << endl;
    cout << "The number of black jeans in Collection 2: " << input2.total_items(Jeans_colors::black) << endl;
    cout << "The number of tall jeans in Collection 2: " << input2.total_items(Jeans_sizes::tall) << endl;
    cout << "The number of grande jeans in Collection 2: " << input2.total_items(Jeans_sizes::grande) << endl;
    cout << "The number of venti jeans in Collection 2: " << input2.total_items(Jeans_sizes::venti) << endl;
    cout << "The total number of jeans in Collection 2: " << input2.total_items() << endl;
    cout << endl;

    cout << "///// UNION OF COLLECTION 1 AND TWO AND STATS/////" << endl;
    CollectionJN unionCollection = make_union(input1, input2);
    unionCollection.print_items();
    cout << endl;
    cout << "The total number of jeans in Union: " << unionCollection.total_items() << endl;
    cout << "The number of white jeans in Union: " << unionCollection.total_items(Jeans_colors::white) << endl;
    cout << "The number of blue jeans in Union: " << unionCollection.total_items(Jeans_colors::blue) << endl;
    cout << "The number of brown jeans in Union: " << unionCollection.total_items(Jeans_colors::brown) << endl;
    cout << "The number of black jeans in Union: " << unionCollection.total_items(Jeans_colors::black) << endl;
    cout << "The number of tall jeans in Union: " << unionCollection.total_items(Jeans_sizes::tall) << endl;
    cout << "The number of grande jeans in Union: " << unionCollection.total_items(Jeans_sizes::grande) << endl;
    cout << "The number of venti jeans in Union: " << unionCollection.total_items(Jeans_sizes::venti) << endl;
    cout << endl;

    cout << "///// SWAPPING ONE AND TWO/////" << endl;
    swap(input1, input2);
    cout << "OUTPUTTING INPUT 1 WHO HAS INPUT 2 NOW" << endl;
    input1.print_items();
    cout << endl;
    cout << "OUTPUTTING INPUT 2 WHO HAS INPUT 1 NOW" << endl;
    input2.print_items();
    cout << endl;

    cout << "///// SORTING COLLECTION 1 AGAIN!/////" << endl;
    sort_by_size(input1, Sort_choice::insertion_sort);
    input1.print_items();
    cout << endl;
};

int main()
{
    srand(time(NULL));
    int answer;
    cout << "What version to test: stress_ball (= 0) or jeans (= 1): ";
    cin >> answer;
    if (answer == 0)
    {
        test_stress_balls();
    }
    else if (answer == 1)
    {
        test_jeans();
    }
    else
        cout << "Wrong value: " << answer << endl;
    return 0;
}
