#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> x(n);
    for(int &i:x)cin>>i;
    // vector<int> dp(1e5+5,0);
    // dp[0]=1;
    // for(int c:x){
    //     for(int i=(int)dp.size()-1;i>=c;i--){
    //         dp[i]|=dp[i-c];
    //     }
    // }
    // int cnt=0;
    // for(int i:dp){
    //     if(i>0)cnt++;
    // }
    // cout<<cnt-1<<endl;
    // for(int i=1;i<(int)dp.size();i++){
    //     if(dp[i]>0)cout<<i<<" ";
    // }
    // cout<<endl;
    vector<int> sums;
    sums.push_back(0);
    for(int c:x){
        vector<int> tmp,tmp2(sums.size()*2);
        for(int i=0;i<sums.size();i++){
            tmp.push_back(sums[i]+c);
        }
        auto end=set_union(sums.begin(),sums.end(),tmp.begin(),tmp.end(),tmp2.begin());
        tmp2.resize(end-tmp2.begin());
        sums=tmp2;
    }
    cout<<sums.size()-1<<endl;
    for(int i=1;i<sums.size();i++)cout<<sums[i]<<" ";
    cout<<endl;
}