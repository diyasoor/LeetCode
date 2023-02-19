Given the root of a binary tree, return the zigzag level order traversal of 
its nodes' values. (i.e., from left to right, then right to left for the 
next level and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
  
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        
        // 0: left->right
        // 1: right->left
        int flag=0;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        
        while(!q.empty()) {
            vector<int> v;
            int size=q.size();
            while(size-- > 0) {
                auto temp=q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                v.push_back(temp->val);
            }
            if(flag) {
                reverse(v.begin(), v.end());
                ans.push_back(v);
                flag=0;
            } 
            else {
                ans.push_back(v);
                flag=1;
            }
        }
        return ans;
    }
};
