#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert at the beginning
void insertAtBeginning(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Function to insert at the end
void insertAtEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert after a specific node
void insertAfter(Node *prevNode, int val)
{
    if (prevNode == nullptr)
    {
        cout << "Previous node cannot be NULL\n";
        return;
    }
    Node *newNode = new Node(val);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to delete a node by value
void deleteByValue(Node *&head, int val)
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }

    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *temp = head;
    while (temp->next && temp->next->data != val)
    {
        temp = temp->next;
    }

    if (temp->next == nullptr)
    {
        cout << "Node not found\n";
        return;
    }

    Node *delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
}

// Function to delete a node by position
void deleteByPosition(Node *&head, int position)
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }

    if (position == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *temp = head;
    int count = 0;

    while (temp != nullptr && count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr || temp->next == nullptr)
    {
        cout << "Position out of bounds\n";
        return;
    }

    Node *delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
}

// Function to display the linked list
void display(Node *head)
{
    if (!head)
    {
        cout << "List is empty\n";
        return;
    }
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr\n";
}

// Function to search for an element
bool search(Node *head, int val)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Function to count the number of nodes
int countNodes(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to reverse the list
void reverse(Node *&head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Function to detect cycle (Floyd's Cycle Detection)
bool detectCycle(Node *head)
{
    if (!head || !head->next)
        return false;

    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true; // Cycle detected
        }
    }
    return false; // No cycle
}

// Function to delete the entire list
void deleteList(Node *&head)
{
    Node *temp = head;
    while (head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node *head = nullptr;

    // Inserting nodes
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    cout << "Initial list: ";
    display(head);

    insertAtBeginning(head, 5);
    cout << "After insertAtBeginning: ";
    display(head);

    insertAfter(head->next->next, 25); // Insert 25 after the 3rd node
    cout << "After insertAfter: ";
    display(head);

    // Deleting by value and position
    deleteByValue(head, 30);
    deleteByPosition(head, 2);
    cout << "After deletions: ";
    display(head);

    cout << "Searching for 40: " << (search(head, 40) ? "Found" : "Not Found") << endl;
    cout << "Number of nodes: " << countNodes(head) << endl;

    reverse(head);
    cout << "Reversed list: ";
    display(head);

    cout << "Cycle detection: " << (detectCycle(head) ? "Cycle found" : "No cycle") << endl;

    // Clean up the list
    deleteList(head);

    return 0;
}
