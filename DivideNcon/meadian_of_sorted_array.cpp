// link to ques : https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int x;
    if(m+n%2){
        x = (m+n)/2;
    }
    else{
        x = -1 + (m+n)/2;
    }

    int l = 0;
    int r = m;
    int k = -1;
    while(l<=r){
        int mid = (l+r)/2;
        int prev = max(nums1[mid-1],nums2[x-mid-1]);
        if(prev<nums1[mid] && prev<nums2[x-mid]){
            k = mid;
            break;
        }
        else{
            if(nums1[mid-1]>nums2[x-mid]){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
    }
    if(k==-1){
        return 0;
    }
    if(m+n%2){
        return min(nums1[k],nums2[x-k]);
    }
    else{
        return (nums1[k]+nums2[x-k])/2;
    }
}

int main()
{
    
    return 0;
}