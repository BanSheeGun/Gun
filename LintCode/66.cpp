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
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        vector<int> p1;
        p1.clear();
        vector<int> p;
        p.clear();
        vector<int> p2;
        p2.clear();
        if (root == NULL)
            return p1;
        if (root->left != NULL)
            p1 = preorderTraversal(root->left);
        if (root->right != NULL)
            p2 = preorderTraversal(root->right);
        p.push_back(root->val);
        p.insert(p.end(), p1.begin(), p1.end());
        p.insert(p.end(), p2.begin(), p2.end());
        return p;
    }
};