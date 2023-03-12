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

int h(TreeNode *c){
    if(!c){
        return 0;
    }
    return 1 + max(h(c->right),h(c->left));
}

bool isBalanced(TreeNode* root) {
    if(!root){
        return true;
    }
    if(abs(h(root->left) - h(root->right))<2)
    {
        if(isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }
    }
    return false;
}

int main()
{
    
    return 0;
}