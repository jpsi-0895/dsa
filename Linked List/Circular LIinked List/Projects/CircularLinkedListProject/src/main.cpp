#include <iostream>
#include "CircularLinkedList.h"

int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);
    
    std::cout << "Circular Linked List: ";
    cll.display();
    
    std::cout << "Searching for 20: " << (cll.search(20) ? "Found" : "Not Found") << std::endl;
    
    cll.deleteNode(30);
    std::cout << "After deleting 30: ";
    cll.display();
    
    cll.deleteNode(100);
    
    return 0;
}
