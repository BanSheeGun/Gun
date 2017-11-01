class Solution {
public:
    /*
     * @param root: the root of tree
     * @return: the max node
     */
    TreeNode * maxNode(TreeNode * root) {
        if (root ==NULL)
            return root;
        TreeNode * ans = root;
        if (root->left != NULL) {
            TreeNode * tmp = maxNode(root->left);
            if (ans->val < tmp->val)
                ans = tmp;
        }
        if (root->right != NULL) {
            TreeNode * tmp = maxNode(root->right);
            if (ans->val < tmp->val)
                ans = tmp;
        }
        return ans;
    }
};
