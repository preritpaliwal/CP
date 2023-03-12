// link to ques : https://leetcode.com/problems/construct-string-from-binary-tree/

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

void solve(TreeNode *t,string &s){
    s.push_back('(');
    s += to_string(t->val);
    if(t->left){
        solve(t->left,s);
        if(t->right){
            solve(t->right,s);
        }
    }
    else{
        if(t->right){
            s.push_back('(');
            s.push_back(')');
            solve(t->right,s);
        }
    }
    s.push_back(')');
}

string tree2str(TreeNode* root) {
    string s;
    s += to_string(root->val);
    if(root->left){
        solve(root->left,s);
        if(root->right){
            solve(root->right,s);
        }
    }
    else{
        if(root->right){
            s.push_back('(');
            s.push_back(')');
            solve(root->right,s);
        }
    }
    return s;
}

int main()
{
    
    return 0;
}