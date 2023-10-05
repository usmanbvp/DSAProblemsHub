#include <iostream>
#include <map>
#include <vector>
#include <queue>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to perform vertical order traversal
void verticalOrderTraversal(TreeNode* root) {
    if (!root) {
        return;
    }

    // Create a map to store nodes at each vertical level
    std::map<int, std::vector<int>> verticalLevels;

    // Create a queue to perform level order traversal
    std::queue<std::pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int verticalLevel = q.front().second;
        q.pop();

        // Add the current node's value to the corresponding vertical level
        verticalLevels[verticalLevel].push_back(node->val);

        // Enqueue the left and right child nodes with updated vertical levels
        if (node->left) {
            q.push({node->left, verticalLevel - 1});
        }
        if (node->right) {
            q.push({node->right, verticalLevel + 1});
        }
    }

    // Print nodes at each vertical level
    for (const auto& pair : verticalLevels) {
        std::cout << "Vertical Level " << pair.first << ": ";
        for (int val : pair.second) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::cout << "Vertical Order Traversal:" << std::endl;
    verticalOrderTraversal(root);

    // Clean up memory (not shown in detail in this example)
    
    return 0;
}
