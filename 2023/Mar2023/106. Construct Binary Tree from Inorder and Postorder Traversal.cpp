Given two integer arrays inorder and postorder where inorder is the inorder traversal 
of a binary tree and postorder is the postorder traversal of the same tree, construct 
and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]
 
Constraints:
1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree

class Solution {
public:
    TreeNode* inPost(vector<int>& postorder, int postS, int postE, 
                     vector<int>& inorder, int inS, int inE) {
        if(postS > postE || inS > inE) return NULL;
        int i=inS;
        while(inorder[i] != postorder[postE]) i++;
        
        TreeNode* root=new TreeNode(postorder[postE]);
        
        int inRoot=i;
        int numsLeft = inRoot-inS;
        
        root->left = inPost(postorder, postS, postS + numsLeft - 1, inorder, inS, inRoot-1);
        root->right = inPost(postorder, postS + numsLeft, postE-1, inorder, inRoot+1, inE);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return inPost(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
