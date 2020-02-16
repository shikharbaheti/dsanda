using namespace std;
#include <iostream>
#include <vector>

vector<double> doubler(vector<double> a, vector<double> b)
{
    vector<double> c;
    for (int i = 0; i < a.size(); i++)
    {
        double thingToBePushed = a.at(i) * b.at(i);
        c.push_back(thingToBePushed);
    }
    return c;
}

int main()
{
    cout << "Starting now" << endl;
    vector<double> one;

    // PUSHING THINGS INTO ONE
    one.push_back(3);
    one.push_back(5);
    one.push_back(4);

    vector<double> two;
    // PUSHING THINGS INTO TWO
    two.push_back(2);
    two.push_back(7);
    two.push_back(5);

    vector<double> result;
    result = doubler(one, two);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}