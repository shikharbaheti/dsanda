#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

int num_push = 0;
int num_pop = 0;

/*
Note the STL stack<int> has (roughly) the following methods:
    bool empty() const;
    int size() const;
    int top() cosnt;
    void push(int);
    void pop();

Write code only where you see:
    // TODO: YOUR CODE HERE
*/

void flip_stack(stack<int> &src_stack, stack<int> &dst_stack)
{
    while (!src_stack.empty())
    {
        ++num_push;
        ++num_pop;
        dst_stack.push(src_stack.top());
        src_stack.pop();
    }
}

class queue
{
private:
    // Only use these data members. Don't add any other data members
    stack<int> stackA;
    stack<int> stackB;

public:
    bool empty() const
    {
        return stackA.empty() && stackB.empty();
    }
    int size() const
    {
        return stackA.size() + stackB.size();
    }
    void enqueue(int elem)
    {
        ++num_push;
        stackA.push(elem);
    }

    // Implement the dequeue using STL stack and the function flip_stack. Assume queue is not empty.
    int dequeue()
    {
        // TODO: YOUR CODE HERE
        if (stackB.empty())
        {
            while (!stackA.empty())
            {
                stackB.push(stackA.pop);
            }
        }
        int item = stackB.pop();
        return item;
    }
};

void show_counts(queue &q, int elems)
{
    if (!q.empty())
    {
        cerr << "QUEUE IMPLEMENTATION ERROR" << endl;
        exit(-1);
    }
    cout << "Number of elements:        " << elems << endl;
    cout << "Number of PUSH operations: " << num_push << endl;
    cout << "Number of POP  operations: " << num_pop << endl;
    cout << endl;
    num_push = num_pop = 0;
}
void add_range(queue &q, int a, int b)
{
    for (int i = a; i <= b; ++i)
    {
        q.enqueue(i);
    }
}
void del_range(queue &q, int a, int b)
{
    for (int j = a; j <= b; ++j)
    {
        if (q.empty() || q.dequeue() != j)
        {
            cerr << "QUEUE IMPLEMENTATION ERROR" << endl;
            exit(-1);
        }
    }
}

int main()
{
    queue q;

    add_range(q, 1, 3);
    del_range(q, 1, 3);
    add_range(q, 4, 8);
    del_range(q, 4, 5);
    add_range(q, 9, 10);
    del_range(q, 6, 10);
    show_counts(q, 10);

    add_range(q, 1, 47);
    del_range(q, 1, 43);
    add_range(q, 48, 87);
    del_range(q, 44, 60);
    add_range(q, 88, 100);
    del_range(q, 61, 100);
    show_counts(q, 100);

    add_range(q, 1, 570);
    del_range(q, 1, 493);
    add_range(q, 571, 819);
    del_range(q, 494, 703);
    add_range(q, 820, 1000);
    del_range(q, 704, 1000);
    show_counts(q, 1000);
}
