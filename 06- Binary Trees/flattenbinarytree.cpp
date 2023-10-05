#include <iostream>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void flatten(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Flatten the left and right subtrees recursively
    flatten(root->left);
    flatten(root->right);

    // Store the right subtree in a temporary variable
    TreeNode* temp = root->right;

    // Make the left subtree the new right subtree
    root->right = root->left;
    root->left = nullptr;

    // Find the end of the current flattened subtree
    TreeNode* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }

    // Attach the temporary right subtree to the end of the current subtree
    current->right = temp;
}

// Helper function to print the flattened linked list
void printFlattenedList(TreeNode* root) {
    while (root != nullptr) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << "Original tree:" << endl;
    printFlattenedList(root);

    flatten(root);

    cout << "Flattened tree (linked list):" << endl;
    printFlattenedList(root);

    // Clean up the memory (not shown in this simple example)
    
    return 0;
}
