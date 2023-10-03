#include <iostream>

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : key(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    TreeNode* findLCA(TreeNode* node, int key1, int key2) {
        if (node == nullptr)
            return nullptr;

        if (node->key > key1 && node->key > key2)
            return findLCA(node->left, key1, key2);
        if (node->key < key1 && node->key < key2)
            return findLCA(node->right, key1, key2);

        return node;
    }

    TreeNode* insert(TreeNode* node, int key) {
        if (node == nullptr)
            return new TreeNode(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);

        return node;
    }

public:
    BST() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    TreeNode* findLCA(int key1, int key2) {
        return findLCA(root, key1, key2);
    }
};

int main() {
    BST bst;
    int keys[] = {5, 3, 7, 1, 4, 6, 8};
    int num_keys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < num_keys; i++) {
        bst.insert(keys[i]);
    }

    int key1 = 1, key2 = 4;
    TreeNode* lcaNode = bst.findLCA(key1, key2);

    if (lcaNode) {
        std::cout << "Lowest Common Ancestor of " << key1 << " and " << key2 << " is: " << lcaNode->key << std::endl;
    } else {
        std::cout << "Keys " << key1 << " and " << key2 << " are not present in the BST." << std::endl;
    }

    return 0;
}
