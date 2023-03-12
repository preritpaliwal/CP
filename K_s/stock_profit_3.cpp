// link to ques : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <bits/stdc++.h>
using namespace std;

int Profit(vector<int>& prices,int l,int r) {
    int profit = 0;
    int mi = prices[l];
    for(int i = l;i<=r;i++){
        profit = max(profit,prices[i]-mi);
        mi = min(mi,prices[i]);
    }
    return profit;
}

int maxProfit(vector<int>& prices) {
    vector<int> localmax;
    if(prices[0]>prices[1]){
        localmax.push_back(0);
    }
    for (int i = 1;i<prices.size()-1;i++){
        if(prices[i]>prices[i-1]&&prices[i]>prices[i+1]){
            localmax.push_back(i);
        }
    }
    if(prices[prices.size()-1]>prices[prices.size()-2]){
        localmax.push_back(prices.size()-1);
    }

    int max_sum = 0;
    for(int i = 0;i<localmax.size();i++){
        max_sum = max(max_sum,Profit(prices,0,localmax[i]) + Profit(prices,localmax[i],prices.size()-1));
    }
    return max_sum;
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

/*
8
3 3 5 0 0 3 1 4

*/