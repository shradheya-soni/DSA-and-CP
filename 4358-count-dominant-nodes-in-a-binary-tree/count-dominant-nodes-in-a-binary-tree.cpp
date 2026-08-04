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
    int cnt = 0;
    int f(TreeNode* root){
        if(root == nullptr) return -1e9;

        if (root->left == nullptr && root->right == nullptr) {
            cnt++;
            return root->val;
        }

        auto m1 = f(root->left);
        auto m2 = f(root->right);
        
        int num = max(m1,m2);

        if(root->val >= num) cnt++;

        return max({root->val,m1,m2});

    }
    int countDominantNodes(TreeNode* root) {
        f(root);
        return cnt;
    }
};