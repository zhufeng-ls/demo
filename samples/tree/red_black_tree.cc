#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

enum COLOR {
    RED,
    BLACK
};

enum ERROR {
    NoError = 0,
    Exist,
};

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    COLOR color; 

    TreeNode(int val)
    {
        this->color = RED;
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    } 
};

void printTree(TreeNode* node)
{
    if (!node)
    {
        cout << "tree is empty!" << endl;
    }
    std::queue<TreeNode*> que;
    que.push(node);
    cout << "tree: ";
    while (!que.empty())
    {
        auto front = que.front();
        que.pop();

        cout << front->val << '\t';
        if (front->left)
        {
            que.push(front->left);
        }
        if (front->right)
        {
            que.push(front->right);
        }
    }

    cout << endl;
}

class RedBlackTree 
{
public:
    RedBlackTree()
    {
        root_ = nullptr;
        index_node_ = nullptr;
        error_ = NoError;
    }
    ~RedBlackTree() = default;

    void add(int val);
    void del(int val);

    void init_tree();
    TreeNode* root()
    {
        return root_;
    }

private:
    void inset_case1(TreeNode* node);
    void inset_case2(TreeNode* node);
    void inset_case3(TreeNode* node);
    void inset_case4(TreeNode* node);
    void inset_case5(TreeNode* node);

    void find_node(int val);
    void reset()
    {
        error_ = NoError;
    }

    void rolate_left();
    void rolate_right();

    TreeNode* uncle(TreeNode* node)
    {
        auto grand_father = grandfather(node);
        if (node->parent == grand_father->left)
        {
            return grand_father->right;
        }
        else
        {
            return grand_father->left;
        }
    }
    TreeNode* grandfather(TreeNode* node)
    {
        return node->parent->parent;
    }

    TreeNode* root_;
    TreeNode* index_node_;
    int error_;
};

void RedBlackTree::find_node(int val)
{
    if (!root_)
    {
        cout << "root 节点为空" << endl;
        return;
    }
    
    auto cur = root_;
    auto pre = cur;
    while (cur)
    {
        if (val < cur->val)
        {
            pre = cur;
            cur = cur->left;
        }
        else if (val > cur->val)
        {
            pre = cur;
            cur = cur->right;
        }
        else
        {
            error_ = Exist;
            cur = pre = nullptr;
            break;
        }
    }
    index_node_ = pre;
}

void RedBlackTree::add(int val)
{
    find_node(val);
    if (error_ != 0)
    {
        std::cout << "error: " << error_ << endl;
        reset();
        return;
    }

    TreeNode* node = new TreeNode(val);
    if (!root_)
    {
        root_ = node;
        root_->color = BLACK;
    } 
    else
    {
        cout << "indexNode-val: " << index_node_->val << endl;
        if (node->val > index_node_->val)
        {
            index_node_->right = node;
        }
        else
        {
            index_node_->left = node;
        }

        inset_case1(node);
    }
}



void RedBlackTree::inset_case1(TreeNode* node)
{
}

int main()
{
    RedBlackTree tree;
    tree.add(1);
    tree.add(2);
    printTree(tree.root());
}