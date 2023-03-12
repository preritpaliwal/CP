// link to ques : https://leetcode.com/problems/majority-element/

#include <bits/stdc++.h>
using namespace std;

int count(vector<int> v,int num,int l,int r){
    int k = 0;
    for(int i = 0;i<v.size();i++){
        if(num == v[i]){
            k++;
        }
    }
    return k;
}

int majority_element(vector<int> v,int l,int r){
    if(l==r){
        return v[l];
    }
    int m = (l+r)/2;
    int lm = majority_element(v,l,m);
    int rm = majority_element(v,m+1,r);
    if(lm==rm){
        return lm;
    }
    if(count(v,lm,l,r)>count(v,rm,l,r)){
        return lm;
    }
    else{
        return rm;
    }
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

    // using MAP;


    // map<int,int> m;
    // for(int i = 0;i<n;i++){
    //     if(m.find(nums[i])==m.end()){
    //         m[nums[i]] = 1;
    //     }
    //     else{
    //         m[nums[i]]++;
    //     }
    // }
    // map<int, int>::iterator itr;
    // for(itr = m.begin();itr!=m.end();itr++){
    //     if(itr->second > (nums.size()/2)){
    //         cout<<itr->first;
    //     }
    // }

    // using divide and conquer  (wont be submitted as it crossses memory limit)

    cout<<majority_element(nums,0,nums.size()-1);
    return 0;
}