#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> maxHeap;

    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);
    maxHeap.push(40);
    maxHeap.push(50);

    cout << "Max Heap elements in order of extractions: " << endl;
    while (!maxHeap.empty())
    {
        cout << maxHeap.top() << " ";
        cout << endl;
        maxHeap.pop();
    }

    return 0;
}