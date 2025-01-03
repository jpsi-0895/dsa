#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode
{
public:
    int data;
    vector<TreeNode *> children;
    TreeNode(int val)
    {
        data = val;
    }
    void addChild(TreeNode *child)
    {
        children.push_back(child);
    }
};

class Tree
{
public:
    TreeNode *root;
    Tree(int rootVal)
    {
        root = new TreeNode(rootVal);
    }

    void BFS(TreeNode *start)
    {
        if (start == nullptr)
            return;
        queue<TreeNode *> q;
        q.push(start);

        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();

            cout << current->data << " ";

            for (TreeNode *child : current->children)
            {
                q.push(child);
            }
        }
        cout << endl;
    }
};

int main()
{
    Tree tree(1);

    TreeNode *root = tree.root;
    TreeNode *child1 = new TreeNode(2);
    TreeNode *child2 = new TreeNode(3);
    TreeNode *child3 = new TreeNode(4);

    root->addChild(child1);
    root->addChild(child2);
    root->addChild(child3);

    TreeNode *child11 = new TreeNode(5);
    TreeNode *child12 = new TreeNode(6);

    child1->addChild(child11);
    child1->addChild(child12);

    TreeNode *child21 = new TreeNode(7);

    child2->addChild(child21);

    cout << "BFS traversal of the tree: ";

    tree.BFS(root);
    return 0;
}