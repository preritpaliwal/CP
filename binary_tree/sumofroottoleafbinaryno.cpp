// link to ques : https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

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

bool isleaf(TreeNode* r){
    if(!r){
        return false;
    }
    if(!(r->left) && !(r->right)){
        return true;
    }
    return false;
}

int get(stack<TreeNode *> v){
    int k = 0;
    int i = 0;
    while(!v.empty()){
        k += (v.top()->val)*(pow(2,i));
        v.pop();
        i++;
    }
    return k;
}

bool sumRootToLeaf(TreeNode* root) {
    stack<TreeNode *> v;
    int sum = 0;
    int dir = 1;
    v.push(root);
    while(v.size()!=0){
        TreeNode *temp = v.top();
        if(isleaf(temp)){
            sum += get(v);
            v.pop();
            dir = -1;
            continue;
        }
        if(dir == 1){
            if(temp->left){
                v.push(temp->left);
            }
        }
        else{
            if(temp->right){
                v.push(temp->right);
                dir = 1;
            }
        }
    }
    return sum;
}

int main()
{
    
    return 0;
}