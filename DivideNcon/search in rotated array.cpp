// link to ques : https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    if(target==nums[0]){
        return 0;
    }
    int i_min = 0;
    int l = 0;
    int r = nums.size()-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(nums[mid]<nums[i_min]){
            i_min = mid;
        }
        if(nums[0]>nums[mid]){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
        cout<<"l,r = "<<l<<r<<endl;
    }
    cout<<i_min;
    if(nums[0]>target || i_min==0){
        l = i_min;
        r = nums.size()-1;
    }else{
        l = 0;
        r = i_min-1;
    }
    while(l<=r){
        int mid=(l+r)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;
}

int main()
{
    
    return 0;
}