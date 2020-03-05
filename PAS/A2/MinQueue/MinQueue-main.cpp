#include <iostream>
#include <string>
#include <stdexcept>
#include "MinQueue.h"
using namespace std;
int main()
{
    cout << " -------MAKING INTEGER QUEUE------- " << endl;
    MinQueue<int> queue1;

    cout << "////// PRINTING EMPTY QUEUE 1 //////" << endl;
    cout << "Queue 1: " << endl;
    try
    {
        queue1.printMQ();
    }
    catch (runtime_error &e)
    {
        cerr << e.what() << endl
             << endl;
    }
    //populating the integer queue with numbers upto 20!
    for (int i = 0; i < 20; i++)
    {
        queue1.enqueue(i);
    }

    cout << "////// PRINTING QUEUE 1 FILLED WITH INTEGERS //////" << endl;
    cout << "Queue 1: " << endl;
    queue1.printMQ();

    cout << "Size of Queue before: " << queue1.sizeMQ() << endl;

    cout << "////// Dequeuing AN ELEMENT //////" << endl;
    queue1.dequeue();

    cout << "////// PRINTING QUEUE 1 UPDATED //////" << endl;
    queue1.printMQ();

    cout << "Size of Queue after: " << queue1.sizeMQ() << endl;
    cout << "Minimum of Queue: " << queue1.min() << endl;

    cout << endl;
    return 0;
}