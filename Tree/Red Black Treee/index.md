### Red-Black Tree in C++

A **Red-Black Tree** (RBT) is a type of self-balancing binary search tree (BST) with additional properties that ensure the tree remains balanced during insertions and deletions. These properties guarantee that the tree remains balanced and ensures O(log n) time complexity for search, insertion, and deletion operations.

The main properties of a Red-Black Tree are:

1. **Each node is either red or black.**
2. **The root is always black.**
3. **All leaves (NIL nodes) are black.**
4. **If a red node has children then, the children are always black (no two red nodes can be adjacent).**
5. **Every path from a given node to its descendant NIL nodes must have the same number of black nodes.**

### Red-Black Tree Structure

- Each node stores a color (`red` or `black`).
- Nodes also store `left`, `right`, and `parent` pointers.

### Basic Operations
- **Insertion**: Insertions are done as in a normal binary search tree, followed by fixing any violations of the Red-Black properties.
- **Deletion**: Deletions involve removing a node, followed by rebalancing to restore Red-Black properties.
- **Search**: The search is similar to a standard binary search tree.

### C++ Code for Red-Black Tree

Below is a simplified version of a **Red-Black Tree** in C++ with the insertion operation. We will focus on implementing the insertion logic, which includes fixing the tree to maintain its Red-Black properties.

```cpp
#include <iostream>
using namespace std;

// Enum to represent colors
enum Color { RED, BLACK };

// Structure for a Red-Black Tree Node
struct Node {
    int data;
    Color color;
    Node* left, * right, * parent;

    Node(int data) {
        this->data = data;
        left = right = parent = nullptr;
        color = RED; // New nodes are always red initially
    }
};

// Red-Black Tree Class
class RedBlackTree {
public:
    Node* root;

    RedBlackTree() {
        root = nullptr;
    }

    // Left rotate operation (used during balancing)
    void leftRotate(Node*& root, Node*& x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    // Right rotate operation (used during balancing)
    void rightRotate(Node*& root, Node*& x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nullptr) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    // Fix the tree after insertion
    void fixInsert(Node*& root, Node*& z) {
        while (z->parent != nullptr && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                Node* y = z->parent->parent->right; // Uncle node
                if (y != nullptr && y->color == RED) {
                    // Case 1: Uncle is red
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        // Case 2: z is right child, left rotate
                        z = z->parent;
                        leftRotate(root, z);
                    }
                    // Case 3: z is left child, right rotate
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(root, z->parent->parent);
                }
            } else {
                Node* y = z->parent->parent->left; // Uncle node
                if (y != nullptr && y->color == RED) {
                    // Case 1: Uncle is red
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        // Case 2: z is left child, right rotate
                        z = z->parent;
                        rightRotate(root, z);
                    }
                    // Case 3: z is right child, left rotate
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(root, z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    // Insertion method
    void insert(int data) {
        Node* z = new Node(data);
        Node* y = nullptr;
        Node* x = root;

        // Standard BST insert
        while (x != nullptr) {
            y = x;
            if (z->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        z->parent = y;
        if (y == nullptr) {
            root = z; // Tree was empty
        } else if (z->data < y->data) {
            y->left = z;
        } else {
            y->right = z;
        }

        // Fix the tree after insertion
        fixInsert(root, z);
    }

    // Inorder traversal (for testing)
    void inorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Function to print the tree (for testing)
    void printTree() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    RedBlackTree tree;

    // Insert nodes into the Red-Black Tree
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);

    // Print the tree using inorder traversal
    cout << "Inorder traversal of the Red-Black Tree: ";
    tree.printTree();

    return 0;
}
```

### Explanation of Code:

1. **Node Structure**:
   - Each node in the tree stores an integer (`data`), a color (`RED` or `BLACK`), and pointers to its left, right, and parent nodes.

2. **Insert Method**:
   - The `insert` method inserts a new node following the usual binary search tree rules and then fixes any Red-Black violations using the `fixInsert` method.
   
3. **FixInsert Method**:
   - This method ensures that the Red-Black tree properties are maintained after each insertion. It checks if the inserted node violates the Red-Black properties and performs rotations and recoloring to fix the violations.

4. **Rotations**:
   - `leftRotate` and `rightRotate` methods are used to perform tree rotations, which are crucial for maintaining the balance of the tree.

5. **Inorder Traversal**:
   - The `inorder` method prints the elements of the tree in sorted order, useful for testing if the tree is correctly balanced.

### Sample Output:

```plaintext
Inorder traversal of the Red-Black Tree: 10 15 20 25 30
```

### Time Complexity:
- **Insertion**: O(log n), where `n` is the number of nodes in the tree.
- **Fixing Insertions**: O(log n), due to rotations and re-coloring.
- **Search**: O(log n), same as binary search trees due to balancing properties.
