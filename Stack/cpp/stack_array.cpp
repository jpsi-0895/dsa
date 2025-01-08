#include <iostream>
#define MAX 100
using namespace std;
class Stack
{
private:
    int arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if (top == MAX - 1)
        {
            cout << "Stack overflow!.";
            return;
        }
        arr[++top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow!.";
            return;
        }
        top--;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    int size()
    {
        return top + 1;
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty!.";
            return;
        }
        return arr[top];
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Top element: " << s.peek() << endl;
    s.pop();
    cout << "Top element after pop: ";
    cout << "Stack size: " << s.size();

    if (s.isEmpty())
    {
        cout << "The stack is empty!.";
    }
    else
    {
        cout << "The stack is not empty!.";
    }
    return 0;
}