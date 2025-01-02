#include <iostream>
#include <vector>

using namespace std;

class MaxHeap
{
private:
    vector<int> heap;
    void heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest])
        {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest])
        {
            largest = right;
        }

        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }
    void bubbleUp(int index)
    {
        while (index > 0 && heap[(index - 1) / 2] < heap[index])
        {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

public:
    void insert(int value)
    {
        heap.push_back(value);
        bubbleUp(heap.size() - 1);
    }

    int extractMax()
    {
        if (heap.empty())
        {
            cout << "Heap is empty" << endl;
            return -1;
        }
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return maxVal;
    }

    int peek()
    {
        if (heap.empty())
        {
            cout << "Heap is empty.";
            return -1;
        }
        return heap[0];
    }

    void buildHeap(const vector<int> &arr)
    {
        heap = arr;

        for (int i = heap.size() / 2 - 1; i >= 0; --i)
        {
            heapify(i);
        }
    }

    int size()
    {
        return heap.size();
    }

    bool empty()
    {
        return heap.empty();
    }

    void display()
    {
        for (int val : heap)
        {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main()
{
    MaxHeap maxHeap;
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(30);
    maxHeap.insert(40);

    cout << "Heap after insertions: ";
    maxHeap.display();

    cout << "Extracted max: " << maxHeap.extractMax() << endl;
    maxHeap.display();

    cout << "Peek: " << maxHeap.peek() << endl;
    vector<int> arr = {10, 20, 5, 30, 40};
    maxHeap.buildHeap(arr);
    cout << "Heap after building from array: " << endl;
    maxHeap.display();

    cout << "Size of heap: " << maxHeap.size() << endl;

    cout << "Is heap empty? " << (maxHeap.empty() ? "Yes" : "No") << endl;
    return 0;
}