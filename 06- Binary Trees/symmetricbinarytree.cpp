#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetric(TreeNode* leftSubtree, TreeNode* rightSubtree) {
    if (!leftSubtree && !rightSubtree) {
        return true;
    }

    if (!leftSubtree || !rightSubtree) {
        return false;
    }

    // Check if the current nodes have the same value and their subtrees are symmetric.
    return (leftSubtree->val == rightSubtree->val) &&
           isSymmetric(leftSubtree->left, rightSubtree->right) &&
           isSymmetric(leftSubtree->right, rightSubtree->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) {
        return true; // An empty tree is symmetric.
    }
    
    return isSymmetric(root->left, root->right);
}

int main() {
    // Create a symmetric binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    bool result = isSymmetric(root);

    if (result) {
        std::cout << "The tree is symmetric." << std::endl;
    } else {
        std::cout << "The tree is not symmetric." << std::endl;
    }

    // Clean up memory (not shown in detail in this example)
    
    return 0;
}
