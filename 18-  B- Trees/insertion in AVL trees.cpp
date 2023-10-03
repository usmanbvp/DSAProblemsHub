//nsertion in AVL trees involves the same basic steps as inserting in a binary search tree (BST), but with an additional step to balance the tree to maintain the AVL property (the balance factor of each node is either -1, 0, or 1)

#include <iostream>
#include <algorithm>

struct TreeNode {
    int key;
    int height;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : key(val), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    TreeNode* root;

    int height(TreeNode* node) {
        return (node == nullptr) ? 0 : node->height;
    }

    int getBalance(TreeNode* node) {
        return (node == nullptr) ? 0 : height(node->left) - height(node->right);
    }

    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return x;
    }

    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        return y;
    }

    TreeNode* insertNode(TreeNode* node, int key) {
        if (node == nullptr)
            return new TreeNode(key);

        if (key < node->key)
            node->left = insertNode(node->left, key);
        else if (key > node->key)
            node->right = insertNode(node->right, key);
        else
            return node;  // Duplicate keys are not allowed in AVL trees

        node->height = 1 + std::max(height(node->left), height(node->right));

        int balance = getBalance(node);

        // Left Heavy
        if (balance > 1) {
            if (key < node->left->key)
                return rightRotate(node);
            else {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        // Right Heavy
        if (
