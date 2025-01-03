### AVL Tree in C++

An **AVL Tree** (Adelson-Velsky and Landis Tree) is a type of self-balancing binary search tree (BST). In an AVL tree, the heights of the two child subtrees of any node differ by at most one. This property is called the **balance factor** of a node, and it ensures that the tree remains balanced, meaning that the operations (insertion, deletion, and search) can be performed in O(log n) time.

### Key Concepts of AVL Tree:

1. **Balance Factor**:
   - The balance factor of a node is the difference between the heights of its left and right subtrees.
   - If the balance factor is between -1 and 1 (inclusive), the node is balanced.
   - A balance factor of `-1`, `0`, or `1` means the node is balanced; otherwise, it requires rebalancing.

2. **Rotations**:
   - When a node becomes unbalanced (i.e., its balance factor is outside the range [-1, 1]), **rotations** are performed to restore balance.
   - There are four types of rotations:
     - **Left Rotation (LL)**: When the left subtree of the left child is higher.
     - **Right Rotation (RR)**: When the right subtree of the right child is higher.
     - **Left-Right Rotation (LR)**: A combination of left and right rotations.
     - **Right-Left Rotation (RL)**: A combination of right and left rotations.

### AVL Tree Operations:
- **Insertion**: Insert a node, then perform rotations if necessary to maintain balance.
- **Deletion**: Remove a node, then rebalance the tree.
- **Search**: Standard binary search tree search operation.
- **Height**: The height of a node is the maximum height of its left or right subtree plus 1.

### AVL Tree C++ Code Implementation

Below is the C++ implementation of an AVL tree with insertion and balancing operations:

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

// Structure for a node in the AVL Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        data = value;
        left = right = nullptr;
        height = 1; // New node is initially added at height 1
    }
};

// Class to manage AVL Tree
class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = nullptr;
    }

    // Function to get the height of the node
    int height(Node* node) {
        return (node == nullptr) ? 0 : node->height;
    }

    // Function to get the balance factor of the node
    int getBalance(Node* node) {
        return (node == nullptr) ? 0 : height(node->left) - height(node->right);
    }

    // Right rotation (used in case of Right-Right imbalance)
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        // Return the new root
        return x;
    }

    // Left rotation (used in case of Left-Left imbalance)
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        // Return the new root
        return y;
    }

    // Left-Right Rotation (used in case of Left-Right imbalance)
    Node* leftRightRotate(Node* node) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right-Left Rotation (used in case of Right-Left imbalance)
    Node* rightLeftRotate(Node* node) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Insertion function to insert a node
    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        // Insert the node in the correct position
        if (key < node->data) {
            node->left = insert(node->left, key);
        } else if (key > node->data) {
            node->right = insert(node->right, key);
        } else {
            return node; // Duplicate keys are not allowed
        }

        // Update the height of the current node
        node->height = 1 + max(height(node->left), height(node->right));

        // Get the balance factor of the node
        int balance = getBalance(node);

        // If the node becomes unbalanced, then there are 4 cases:

        // Left-Left case
        if (balance > 1 && key < node->left->data) {
            return rightRotate(node);
        }

        // Right-Right case
        if (balance < -1 && key > node->right->data) {
            return leftRotate(node);
        }

        // Left-Right case
        if (balance > 1 && key > node->left->data) {
            return leftRightRotate(node);
        }

        // Right-Left case
        if (balance < -1 && key < node->right->data) {
            return rightLeftRotate(node);
        }

        // Return the (unchanged) node pointer
        return node;
    }

    // Public method to insert a key
    void insert(int key) {
        root = insert(root, key);
    }

    // Inorder traversal of the tree (to display elements)
    void inorder(Node* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Public inorder traversal
    void printInOrder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;

    // Insert nodes into the AVL tree
    tree.insert(20);
    tree.insert(25);
    tree.insert(30);
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    // Print the inorder traversal of the AVL tree
    cout << "Inorder traversal of the AVL tree: ";
    tree.printInOrder();

    return 0;
}
```

### Explanation of the Code:

1. **Node Structure**:
   - Each node stores the `data`, `left` and `right` pointers, and the `height` of the node.
   
2. **AVLTree Class**:
   - **Height Calculation**: `height()` function returns the height of a node.
   - **Balance Calculation**: `getBalance()` function calculates the balance factor of a node (difference between the heights of the left and right subtrees).
   - **Rotations**: The tree uses 4 types of rotations:
     - **Right Rotation**: Used for Left-Left imbalance.
     - **Left Rotation**: Used for Right-Right imbalance.
     - **Left-Right Rotation**: Used for Left-Right imbalance.
     - **Right-Left Rotation**: Used for Right-Left imbalance.
   - **Insert Function**: The `insert()` function recursively inserts a node, updates the height of the node, and checks if the tree is balanced. If unbalanced, it calls the appropriate rotation function.
   
3. **Inorder Traversal**: The `inorder()` function is used to traverse the tree in ascending order and print the elements.

### Example:

#### Tree Structure:
Inserting the following sequence of values: `20, 25, 30, 10, 5, 15`.

1. **Insert 20**: Root node.
2. **Insert 25**: Right child of 20.
3. **Insert 30**: Right child of 25 (Right-Right imbalance on 20, left rotate).
4. **Insert 10**: Left child of 20.
5. **Insert 5**: Left child of 10.
6. **Insert 15**: Right child of 10.

#### Output:
```
Inorder traversal of the AVL tree: 5 10 15 20 25 30
```

### Time Complexity:
- **Insertion**: O(log n), where `n` is the number of nodes in the tree. Due to the balancing property of the AVL tree, the height of the tree is always kept in the range of O(log n).
- **Search**: O(log n), because the tree is balanced.
- **Rotation Operations**: Each rotation takes constant time, O(1), but may be performed up to O(log n) times for balancing. Thus, the total time complexity remains O(log n) for insertion, deletion, and searching.

### Space Complexity:
- The space complexity is O(n), where `n` is the number of nodes in the tree, as each node requires storage for its left and right children, height, and data.