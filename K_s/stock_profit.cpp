// link to ques : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;

// divide and conquer (memory limit exceded)

int profit(vector<int> v,int l,int r){
    if(l==r){
        return 0;
    }
    else if(r-l==1){
        if(v[l]<v[r]){
            return v[r]-v[l];
        }
        else{
            return 0;
        }
    }
    int m = (l+r)/2;
    int pl = profit(v,l,m);
    int pr = profit(v,m+1,r);
    int min = v[l],maxi = v[r];
    for(int i = l+1;i<m+1;i++){
        if(min>v[i]){
            min = v[i];
        }
    }
    for(int i = m+1;i<r+1;i++){
        if(maxi<v[i]){
            maxi = v[i];
        }
    }
    return max(max(pl,pr),maxi-min);
}

int maxProfit(vector<int>& prices) {
    return profit(prices,0,prices.size()-1);
}

int main()
{
    int n;
    cin>>n;
    vector<int> p;
    for(int i = 0;i<n;i++){
        int a;
        cin>>a;
        p.push_back(a);
    }
    cout<<maxProfit(p);
    return 0;
}