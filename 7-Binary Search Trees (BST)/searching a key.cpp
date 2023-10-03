#include <iostream.h>
//program to searching a key in BST
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : key(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* root, int key) {
        if (root == nullptr) {
            return new TreeNode(key);
        }

        if (key < root->key) {
            root->left = insert(root->left, key);
        } else {
            root->right = insert(root->right, key);
        }

        return root;
    }

    TreeNode* search(TreeNode* root, int key) {
        if (root == nullptr || root->key == key) {
            return root;
        }

        if (key < root->key) {
            return search(root->left, key);
        } else {
            return search(root->right, key);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    TreeNode* search(int key) {
        return search(root, key);
    }
};

int main() {
    BST bst;
    int keys[] = {5, 3, 7, 1, 4, 6, 8};
    int num_keys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < num_keys; i++) {
        bst.insert(keys[i]);
    }

    // Search for a key in the BST
    int key_to_search = 4;
    TreeNode* result_node = bst.search(key_to_search);

    if (result_node) {
        std::cout << "Key " << key_to_search << " found in the BST." << std::endl;
    } else {
        std::cout << "Key " << key_to_search << " not found in the BST." << std::endl;
    }

    return 0;
}
