// link to ques : https://leetcode.com/problems/range-sum-of-bst/

#include <bits/stdc++.h>
using namespace std;

void get_sum(TreeNode* temp,int l,int h,int &k){
    if(temp==nullptr){
        return;
    }
    if(l<=temp->val && h>=temp->val){
        k+=temp->val;
    }
    get_sum(temp->left,l,h,k);
    get_sum(temp->right,l,h,k);
}
int rangeSumBST(TreeNode* root, int low, int high) {
    int k = 0;
    get_sum(root,low,high,k);
    return k;
}

int main()
{
    
    return 0;
}