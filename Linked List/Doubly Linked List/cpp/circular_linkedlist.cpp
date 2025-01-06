#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr)
    {
    }
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList() : head(nullptr) {}
    void insertAtEndf(int value);
    void deleteNode(int value);
    void display();
    bool isEmpty()
    {
        return head == nullptr;
    }
    bool search(int value);
};

void CircularLinkedList::insertAtEndf(int value)
{
    Node *newNode = new Node(value);
    if (isEmpty())
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void CircularLinkedList::deleteNode(int value)
{
    if (isEmpty())
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node *temp = head;
    Node *prev = nullptr;

    if (temp->data == value)
    {
        if (temp->next == head)
        {
            delete temp;
            head = nullptr;
            return;
        }

        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        delete temp;
        head = head->next;
    }
    else
    {
        prev = temp;
        temp = temp->next;
        while (temp != head && temp->data != value)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp->data == value)
        {
            prev->next = temp->next;
            delete temp;
        }
        else
        {
            cout << "Node with value " << value;
        }
    }
}

void CircularLinkedList::display()
{
    if (isEmpty())
    {
        cout << "List is empty!." << endl;
        return;
    }

    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

bool CircularLinkedList::search(int value)
{
    if (isEmpty())
    {
        return false;
    }

    Node *temp = head;
    do
    {
        if (temp->data == value)
        {
            return true;
        }
        temp = temp->next;
    } while (temp != head);

    return false;
}
int main()
{
    CircularLinkedList cll;
    cll.insertAtEndf(10);
    cll.insertAtEndf(20);
    cll.insertAtEndf(30);
    cll.insertAtEndf(40);

    cout << "Circular linked list: ";
    cll.display();

    cout << "Searching for 20: " << (cll.search(20) ? "Found!" : "Not found!");

    cll.deleteNode(30);
    cout << "After deleting 30: ";
    cll.display();
    cll.display();
    return 0;
}