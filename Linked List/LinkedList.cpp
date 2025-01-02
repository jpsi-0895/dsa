#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    /* data */
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void insertAtBeginning(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void inserAtEnd(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAfter(Node *prevNode, int data)
{

    if (prevNode == nullptr)
    {
        cout << "the pervious ndoe can not be null.";
        return;
    }
    Node *newNode = new Node(data);

    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void deleteAtBeginning(Node *&head)
{
    if (head == nullptr)
    {
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}
void deleteAtEnd(Node *&head)
{
    if (head == nullptr)
    {
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr && temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

bool search(Node *head, int key)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void traverse(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int lenght(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void reverse(Node *&head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
bool detectLoop(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

void removeDuplicates(Node *head)
{
    Node *current = head;
    while (current != nullptr && current->next != nullptr)
    {
        Node *temp = current;
        while (temp->next != nullptr)
        {
            if (current->data == temp->next->data)
            {
                Node *duplicateNode = temp->next;
                temp->next = temp->next->next;
                delete duplicateNode;
            }
            else
            {
                temp = temp->next;
            }
        }
        current = current->next;
    }
}