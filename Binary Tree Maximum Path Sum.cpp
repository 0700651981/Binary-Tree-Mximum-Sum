#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to find the maximum path sum.
int findMaxPathSum(TreeNode* node, int &maxSum) {
    if (node == NULL) return 0;

    // Recursively get the maximum path sum of left and right subtrees
    int left = max(0, findMaxPathSum(node->left, maxSum));
    int right = max(0, findMaxPathSum(node->right, maxSum));

    // Update the maximum path sum for the current node
    int currentMax = node->val + left + right;
    maxSum = max(maxSum, currentMax);

    // Return the maximum path sum including the current node
    return node->val + max(left, right);
}

// Function to return the maximum path sum of the binary tree
int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    findMaxPathSum(root, maxSum);
    return maxSum;
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout << "Maximum Path Sum: " << maxPathSum(root) << endl; 

    return 0;
}
