#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;
    s.pop();

    cout << "Top element after pop: " << s.top() << endl;

    if (s.empty())
    {
        cout << "The stack is empty!.";
    }
    else
    {
        cout << "The stack is not empty!.";
    }

    cout << "Stack size:" << s.size();
}