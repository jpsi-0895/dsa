Here’s how you can implement node deletion in a Binary Search Tree (BST) in C++:

### Steps:
1. If the node to be deleted has no children (leaf node), simply remove it.
2. If the node to be deleted has one child, replace it with its only child.
3. If the node to be deleted has two children, find the **in-order successor** (the smallest node in the right subtree) or the **in-order predecessor** (the largest node in the left subtree), copy its value to the node to be deleted, and then delete the successor or predecessor.

### C++ Code:

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to find the node with the minimum value
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

// Function to delete a node in the BST
Node* deleteNode(Node* root, int key) {
    // Base case: If the tree is empty
    if (root == nullptr)
        return root;

    // If the key to be deleted is smaller than the root's value, then it lies in the left subtree
    if (key < root->value)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is larger than the root's value, then it lies in the right subtree
    else if (key > root->value)
        root->right = deleteNode(root->right, key);

    // If key is same as root's value, then this is the node to be deleted
    else {
        // Node with one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->value = temp->value;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

// Function to do inorder traversal
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    // Delete node with value 20
    root = deleteNode(root, 20);

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    // Delete node with value 30 (node with one child)
    root = deleteNode(root, 30);

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    // Delete node with value 50 (node with two children)
    root = deleteNode(root, 50);

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
```

### Explanation:
1. **Node class:** Represents a node in the tree, containing a value and two child pointers (`left` and `right`).
2. **minValueNode function:** Finds the node with the minimum value in the tree. This is useful to find the in-order successor when the node has two children.
3. **deleteNode function:** Deletes a node with the given `key` from the tree. It handles three cases:
   - The node has no children (leaf node).
   - The node has one child.
   - The node has two children.
4. **inorder function:** Prints the tree nodes in ascending order using an in-order traversal.

### Example Output:
```
Inorder traversal before deletion: 20 30 40 50 60 70 80 
Inorder traversal after deletion: 30 40 50 60 70 80 
Inorder traversal after deletion: 40 50 60 70 80 
Inorder traversal after deletion: 40 60 70 80 
```

### How to run the code:
1. First, it will print the inorder traversal of the tree before deleting any node.
2. After deleting a node (for example, node `20`), it prints the inorder traversal after the deletion.
3. This process repeats for the nodes `30` (which has one child) and `50` (which has two children).