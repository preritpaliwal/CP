// link to ques : https://leetcode.com/problems/jump-game/

#include <bits/stdc++.h>
using namespace std;

bool jump(vector<int> nums,int k){
        if(k+nums[k]>=nums.size()-1){
            return true;
        }
        for(int i = 1;i<=nums[k];i++){
            if(jump(nums,k+i)){
                return true;
            }
        }
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        return jump(nums,0);
    }

int main()
{
    
    return 0;
}