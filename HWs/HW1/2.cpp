using namespace std;
#include <iostream>
#include <vector>

bool oddExists(vector<int> a)
{
    cout << "Starting ODD EXISTS\n";

    if (a.size() == 1 && a.at(0) % 2 == 1)
    {
        return true;
    }
    for (int i = 1; i < a.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((a.at(i) * a.at(j)) % 2 == 1)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    vector<int> one;
    one.push_back(2);
    one.push_back(2);
    one.push_back(2);
    one.push_back(8);
    one.push_back(2);
    one.push_back(9);

    for (int i = 0; i < one.size(); i++)
    {
        cout << one[i] << " ";
    }
    cout << endl;

    cout << "Size of vector: " << one.size() << endl;

    cout << endl;

    if (oddExists(one))
    {
        cout << "TRUE\n";
    }
    else
    {
        cout << "FALSE \n";
    }

    return 0;
}