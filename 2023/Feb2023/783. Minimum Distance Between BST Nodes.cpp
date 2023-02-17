Given the root of a Binary Search Tree (BST), return the minimum difference 
between the values of any two different nodes in the tree.

Example 1:
Input: root = [4,2,6,1,3]
Output: 1

Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1

Constraints:
The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 10^5

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        if(!root) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        int distance = inorder[1]-inorder[0];
        
        for(int i=1;i<inorder.size()-1;i++) {
            int currDis = inorder[i+1]-inorder[i];
            distance = min(distance, currDis);
        }
        return distance;
    }
};
