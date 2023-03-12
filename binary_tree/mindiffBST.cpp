// link to ques : https://leetcode.com/problems/balanced-binary-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int minDiffInBST(TreeNode* root) {
    if(root->left){
        if(root->right){
            return min(min(root->val - root->left->val , root->right->val - root->val),min( minDiffInBST(root->left), minDiffInBST(root->right)));
        }
        return min(root->val - root->left->val, minDiffInBST(root->left));
    }
    if(root->right){
        return min(root->right->val - root->val, minDiffInBST(root->right));
    }
    return INT_MAX;
}

int main()
{
    
    return 0;
}