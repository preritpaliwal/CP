// link to ques : https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

long long min(long long a,long long b){
    if(a>b){
        return b;
    }
    return a;
}
long long nextmin(TreeNode *temp){
    long long k;
    if(temp->left==NULL){
        k = INT_MAX;
        return k + 1;
    }
    if(temp->left->val==temp->val && temp->right->val==temp->val){
        k = min(nextmin(temp->left),nextmin(temp->right));
    }
    else if(temp->left->val==temp->val){
        k = min(temp->right->val,nextmin(temp->left));
    }
    else{
        k =  min(temp->left->val,nextmin(temp->right));
    }
    return k;
}

int findSecondMinimumValue(TreeNode* root) {
    long long k = nextmin(root);
    if(k-1==INT_MAX){
        return -1;
    }
    return k;
}

int main()
{
    
    return 0;
}