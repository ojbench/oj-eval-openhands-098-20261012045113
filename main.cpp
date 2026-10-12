#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to insert a value into BST
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        
        return root;
    }
    
    // Function to perform reverse in-order traversal to get elements in descending order
    void reverseInorder(TreeNode* root, std::vector<int>& result) {
        if (!root) return;
        
        // Visit right subtree first (larger values)
        reverseInorder(root->right, result);
        // Visit current node
        result.push_back(root->val);
        // Visit left subtree (smaller values)
        reverseInorder(root->left, result);
    }
    
    // Function to find kth largest element in BST
    int kthLargest(TreeNode* root, int k) {
        std::vector<int> values;
        reverseInorder(root, values);
        
        // Return kth largest (k-1 index since 0-based indexing)
        return values[k-1];
    }
};

int main() {
    // Read 7 node values and cnt
    std::vector<int> nodeValues(7);
    int cnt;
    
    for (int i = 0; i < 7; i++) {
        std::cin >> nodeValues[i];
    }
    std::cin >> cnt;
    
    // Build BST from the node values
    TreeNode* root = nullptr;
    Solution solution;
    for (int val : nodeValues) {
        root = solution.insertIntoBST(root, val);
    }
    
    // Find and output the cnt-th largest element
    int result = solution.kthLargest(root, cnt);
    std::cout << result << std::endl;
    
    // Clean up memory by deleting all tree nodes
    std::function<void(TreeNode*)> deleteTree = [&](TreeNode* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    };
    
    deleteTree(root);
    
    return 0;
}