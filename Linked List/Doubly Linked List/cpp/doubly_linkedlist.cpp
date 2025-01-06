#include <iostream>
#include <vector>

using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
private:
    /* data */
    Node *head;
    Node *tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (!tail)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtPosition(int value, int position)
    {
        if (position < 1)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 1)
        {
            insertAtBeginning(value);
            return;
        }

        Node *newNode = new Node(value);
        Node *temp = head;

        int count = 1;
        while (temp != nullptr && count < position)
        {
            temp = temp->next;
            count++;
        }

        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev)
        {
            temp->prev->next = newNode;
        }
        temp->prev = newNode;
    }

    void deleteFromBeginning()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *temp = head;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteFromEnd()
    {
        if (!tail)
        {
            cout << "List is empty!." << endl;
            return;
        }

        Node *temp = tail;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }
    void deleteFromPosition(int position)
    {
        if (position < 1)
        {
            cout << "Invalid position!.";
            return;
        }
        if (position == 1)
        {
            deleteFromBeginning();
            return;
        }

        Node *temp = head;
        int count = 1;
        while (temp != nullptr && count < position)
        {
            temp = temp->next;
            count++;
        }
        if (!temp)
        {
            cout << "Position out of range!" << endl;
            return;
        }
        if (temp->prev)
        {
            temp->prev->next = temp->next;
        }
        if (temp->next)
        {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }
    void forwardTraversal()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }
    void backwardTraversal()
    {
        Node *temp = tail;
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->prev;
        }
        cout << endl;
    }
};

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr)
{
}

DoublyLinkedList::~DoublyLinkedList()
{
}

int main()
{
    DoublyLinkedList dll;
    dll.insertAtBeginning(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtBeginning(5);
    dll.insertAtPosition(15, 3);

    cout << "Forward Traversal: ";
    dll.forwardTraversal();
    cout << "Backward Traversal: ";
    dll.backwardTraversal();
    dll.deleteFromBeginning();
    dll.deleteFromEnd();
    dll.deleteFromPosition(2);
    cout << "After Deletions (Forward Traversal): ";
    dll.forwardTraversal();
    return 0;
}