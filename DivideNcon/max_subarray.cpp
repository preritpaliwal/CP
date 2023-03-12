// link to ques : https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>
using namespace std;

int maxsubarray(vector<int> v,int l,int r){
    if(l>r){
        return INT_MIN;
    }
    int m  = (l+r)/2,ml = 0,mr = 0;
    int lmax = maxsubarray(v,l,m-1);
    int rmax = maxsubarray(v,m+1,r);
    int sum = 0;
    for(int i = m-1;i>=l;i--){
        sum += v[i];
        ml = max(sum,ml);
    }
    sum = 0;
    for(int i = m+1;i<=r;i++){
        sum += v[i];
        mr = max(sum,mr);
    }
    return max(max(lmax,rmax),ml+mr+v[m]);
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    for (int i = 0;i<n;i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }

// solution using DP

    // int k = 0,max = 0;
    // for(int i = 0;i<n;i++){
    //     if(k<0){
    //         k = 0;
    //     }
    //     k+=nums[i];
    //     if(k>max){
    //         max = k;
    //     }
    // }
    // cout<<max;

// solution using divide and conquer
    cout<<maxsubarray(nums,0,nums.size()-1);

    return 0;
}


/*
9
-2 1 -3 4 -1 2 1 -5 4
*/