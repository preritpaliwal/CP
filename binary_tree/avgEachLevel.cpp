// link to ques : https://leetcode.com/problems/average-of-levels-in-binary-tree/

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

vector<double> averageOfLevels(TreeNode* root){
    vector<double> v;
    queue<TreeNode *> q;
    q.push(root);
    int k = 1;
    
    while(!q.empty()){
        int avg = 0;
        int new_k = 0;
        for(int i = 0;i<k;i++){
            TreeNode *temp = q.front();
            avg += temp->val;
            if(temp->left){
                new_k++;
                q.push(temp->left);
            }
            if(temp->right){
                new_k++;
                q.push(temp->right);
            }
            q.pop();
        }
        
        v.push_back((double)(avg/k));
        k = new_k;
    }
    return v;
}

int main()
{
    
    return 0;
}