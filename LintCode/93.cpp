/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
     
    int work(TreeNode * root, bool & ans) {
        int l = 0, r = 0;
        if (root->left != NULL) {
            l = work(root->left, ans);
        }
        if (root->right != NULL) {
            r = work(root->right, ans);
        }
        if (abs(l - r) > 1)
            ans = false;
        return max(l, r) + 1;
    }
     
    bool isBalanced(TreeNode * root) {
        bool ans = true;
        if (root != NULL) {
            work(root, ans);
        }
        return ans;
    }
    
};