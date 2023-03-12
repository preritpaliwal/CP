// link to ques : https://leetcode.com/problems/non-decreasing-array/

#include <bits/stdc++.h>
using namespace std;

bool checkPossibility(vector<int>& nums) {
    int k = 0,z = -1;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i+1]-nums[i]<0){
            k+=1;
            z = i;
        }
    }
    if(k<2){
        if(z==-1){
           return true;
        }
        if(z==0 || z==nums.size()-2){
            return true;
        }
        if(nums[z-1]<=nums[z+1]){
            return true;
        }
        if(nums[z]<=nums[z+2]){
            return true;
        }
    }
    return false;
}


int main()
{
    
    return 0;
}