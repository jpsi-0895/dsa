### Binary Tree Implementation in C++

A **binary tree** is a hierarchical data structure in which each node has at most two children, referred to as the left child and the right child. It is commonly used for efficient searching, sorting, and organizing data.

In this implementation, we'll create a basic **binary tree** in C++ and include some essential operations such as:
1. **Insertion**
2. **Traversal** (In-order, Pre-order, Post-order)
3. **Searching for an element**
4. **Deletion**
5. **Displaying the tree**

### Basic Binary Tree Structure

1. **Node Structure**: Each node has:
   - `data`: The value stored in the node.
   - `left`: A pointer to the left child.
   - `right`: A pointer to the right child.

2. **Tree Structure**: The tree itself is represented by a pointer to the root node.

### C++ Code for Binary Tree

```cpp
#include <iostream>
using namespace std;

// Binary Tree Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Binary Tree class
class BinaryTree {
private:
    Node* root;

    // Helper function for in-order traversal
    void inOrderHelper(Node* node) {
        if (node != nullptr) {
            inOrderHelper(node->left);
            cout << node->data << " ";
            inOrderHelper(node->right);
        }
    }

    // Helper function for pre-order traversal
    void preOrderHelper(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preOrderHelper(node->left);
            preOrderHelper(node->right);
        }
    }

    // Helper function for post-order traversal
    void postOrderHelper(Node* node) {
        if (node != nullptr) {
            postOrderHelper(node->left);
            postOrderHelper(node->right);
            cout << node->data << " ";
        }
    }

    // Helper function to search for an element
    bool searchHelper(Node* node, int val) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == val) {
            return true;
        }
        return searchHelper(node->left, val) || searchHelper(node->right, val);
    }

    // Helper function to delete a node (returns the new root of the subtree)
    Node* deleteHelper(Node* node, int val) {
        if (node == nullptr) {
            return node;
        }
        // Search for the node to be deleted
        if (val < node->data) {
            node->left = deleteHelper(node->left, val);
        } else if (val > node->data) {
            node->right = deleteHelper(node->right, val);
        } else {
            // Node to be deleted found
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteHelper(node->right, temp->data);
        }
        return node;
    }

    // Helper function to find the node with the minimum value
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

public:
    // Constructor to initialize the root
    BinaryTree() : root(nullptr) {}

    // Function to insert a node in the binary tree
    void insert(int val) {
        Node* newNode = new Node(val);
        if (root == nullptr) {
            root = newNode;
        } else {
            Node* temp = root;
            while (true) {
                if (val < temp->data) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        break;
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        break;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        }
    }

    // Function to display the tree (In-order traversal)
    void inOrder() {
        cout << "In-order Traversal: ";
        inOrderHelper(root);
        cout << endl;
    }

    // Function to display the tree (Pre-order traversal)
    void preOrder() {
        cout << "Pre-order Traversal: ";
        preOrderHelper(root);
        cout << endl;
    }

    // Function to display the tree (Post-order traversal)
    void postOrder() {
        cout << "Post-order Traversal: ";
        postOrderHelper(root);
        cout << endl;
    }

    // Function to search for a value in the tree
    bool search(int val) {
        return searchHelper(root, val);
    }

    // Function to delete a node from the tree
    void deleteNode(int val) {
        root = deleteHelper(root, val);
    }

    // Destructor to free the allocated memory
    ~BinaryTree() {
        while (root) {
            deleteNode(root->data);
        }
    }
};

int main() {
    BinaryTree tree;

    // Insert nodes into the binary tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // Display the tree using different traversal methods
    tree.inOrder();
    tree.preOrder();
    tree.postOrder();

    // Search for an element in the tree
    int searchVal = 40;
    if (tree.search(searchVal)) {
        cout << "Element " << searchVal << " found in the tree.\n";
    } else {
        cout << "Element " << searchVal << " not found in the tree.\n";
    }

    // Delete a node from the tree
    tree.deleteNode(20);
    cout << "After deleting 20:\n";
    tree.inOrder();

    tree.deleteNode(30);
    cout << "After deleting 30:\n";
    tree.inOrder();

    return 0;
}
```

### Explanation of the Code:

1. **Node Structure**:
   - Each `Node` has:
     - `data`: Stores the value of the node.
     - `left`: Pointer to the left child.
     - `right`: Pointer to the right child.

2. **BinaryTree Class**:
   - **Private Members**:
     - `root`: A pointer to the root of the binary tree.
   - **Helper Functions**:
     - `inOrderHelper`, `preOrderHelper`, `postOrderHelper`: These functions recursively perform the different types of tree traversal.
     - `searchHelper`: A helper function to search for a value in the tree.
     - `deleteHelper`: A function to delete a node from the tree and return the new root.
     - `minValueNode`: A function to find the node with the minimum value in the right subtree (used in deletion).
   - **Public Functions**:
     - `insert`: Insert a value into the tree.
     - `inOrder`, `preOrder`, `postOrder`: Display the tree using different traversals.
     - `search`: Search for a value in the tree.
     - `deleteNode`: Delete a node from the tree.
   - **Destructor**: The destructor deletes all nodes in the tree to prevent memory leaks.

3. **Main Function**:
   - Demonstrates how to create a binary tree, insert nodes, perform different tree traversals, search for an element, and delete nodes.

### Example Output:

```
In-order Traversal: 20 30 40 50 60 70 80
Pre-order Traversal: 50 30 20 40 70 60 80
Post-order Traversal: 20 40 30 60 80 70 50
Element 40 found in the tree.
After deleting 20:
In-order Traversal: 30 40 50 60 70 80
After deleting 30:
In-order Traversal: 40 50 60 70 80
```

### Time Complexity:

- **Insertion**: \(O(n)\) in the worst case (if the tree is unbalanced), where \(n\) is the number of nodes in the tree.
- **Traversal** (In-order, Pre-order, Post-order): \(O(n)\) since every node is visited once.
- **Search**: \(O(n)\) in the worst case (if the tree is unbalanced).
- **Deletion**: \(O(n)\) in the worst case (if the tree is unbalanced).

### Space Complexity:

- **Space Complexity**: \(O(n)\) for storing the nodes in the tree, where \(n\) is the number of nodes in the tree.

### Conclusion:

This C++ implementation provides a basic **binary tree** with support for insertion, deletion, traversal, and searching. It demonstrates how to build and manipulate binary trees effectively in C++. You can easily extend this implementation to support more advanced tree operations like balancing, height calculation, etc.