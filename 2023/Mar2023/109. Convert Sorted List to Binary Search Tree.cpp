Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.
Example 1:
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

Example 2:
Input: head = []
Output: []

Constraints:
The number of nodes in head is in the range [0, 2 * 104].
-105 <= Node.val <= 105

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        if(nums.size()==1) return new TreeNode(nums[0]);
        
        int mid = nums.size() / 2;
        
        TreeNode *root = new TreeNode(nums[mid]);
        
        vector<int> leftSide(nums.begin(),nums.begin()+mid);
        vector<int> rightSide(nums.begin()+mid+1,nums.end());
        
        root->left = sortedArrayToBST(leftSide);
        root->right = sortedArrayToBST(rightSide);
        
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        
        vector<int> nums;
        ListNode* t=head;
        while(t) {
            nums.push_back(t->val);
            t=t->next;
        }
        return sortedArrayToBST(nums);
        
    }
};
