// link to ques : https://leetcode.com/problems/binary-tree-preorder-traversal/

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

vector<int> preorder(TreeNode *n,vector<int> &v){
    if(!n){
        return v;
    }
    v.push_back(n->val);
    preorder(n->left,v);
    preorder(n->right,v);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> v;
    preorder(root,v);
    return v;
}

int main()
{
    
    return 0;
}