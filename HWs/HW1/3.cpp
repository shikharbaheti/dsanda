using namespace std;
#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

template <typename T>
T binarySearch(vector<T> search, T target)
{
    T l = search.at(0);
    T r = search.at(search.size() - 1);

    while (l <= r)
    {
        T m = l + (r - l) / 2;
        if (search.at(m) == target)
            return m;
        if (search.at(m) < target)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main()
{
    srand(time(0));
    vector<int> one;

    for (int i = 0; i < 10; i++)
    {
        one.push_back(rand() % 10);
    }

    for (int i = 0; i < one.size(); i++)
    {
        cout << one[i] << " ";
    }
    cout << endl;

    int result = binarySearch(one, 8);

    if (result == -1)
    {
        cout << "Element is not present in array" << endl;
    }
    else
    {
        cout << "Element is present at index " << result << endl;
    }

    return 0;
}