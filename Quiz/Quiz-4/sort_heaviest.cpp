// sorting items from the heaviest to lightest
// by selecting the heaviest item at each time

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int comparisons = 0;

ostream &operator<<(ostream &out, vector<int> &v)
{
  for (int i = 0; i < v.size(); i++)
  {
    out << v.at(i) << " ";
  }
  return out;
}
void sort_heaviest(vector<int> &v)
{
  for (int k = 0; k < v.size() - 1; k++)
  {
    int index = k;
    for (int i = k + 1; i < v.size(); i++)
    {
      comparisons++;
      if (v.at(i) > v.at(index))
      {
        index = i;
      }
    }
    swap(v.at(k), v.at(index));
  }
}

int main()
{
  srand(time(NULL));

  cout << "//////Test 1 for vector v ///////////////////////////////" << endl;
  vector<int> v;
  for (int i = 0; i < 10; i++)
  {
    int num = (rand() % 10) + 1;
    v.push_back(num);
  }

  cout << "initial vector v:\n";
  cout << v;
  cout << endl;
  sort_heaviest(v);
  cout << endl;
  cout << "# of comparisons to sort v: " << comparisons << endl;
  cout << "vector v after sorting:\n";
  cout << v;
  cout << endl;
  cout << endl;
  cout << endl;

  cout << "//////Test 2 for vector v1 ///////////////////////////////" << endl;
  vector<int> v1;
  for (int i = 0; i < 10; i++)
  {
    int num = (rand() % 10) + 1;
    v1.push_back(num);
  }
  cout << "initial vector v:\n";
  cout << v1;
  cout << endl;
  sort_heaviest(v1);
  cout << endl;
  cout << "# of comparisons to sort v: " << comparisons << endl;
  cout << "vector v after sorting:\n";
  cout << v1;
  cout << endl;
  cout << endl;
  cout << endl;
}
