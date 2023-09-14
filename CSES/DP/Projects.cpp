#include <bits/stdc++.h>
using namespace std;
using ll=long long;

bool comp(vector<ll> &a,vector<ll> &b){
    return a[1]<b[1];
}

bool comp2(pair<ll,ll> &a,ll b){
    return a.second<b;
}

int main(){
    ll n;cin>>n;
    vector<vector<ll>> p(n+1,vector<ll> (3,0));
    for(int i=1;i<=n;i++)cin>>p[i][0]>>p[i][1]>>p[i][2]; 
    sort(p.begin(),p.end(),comp);   
    vector<pair<ll,ll>> dp(n+1,{0,1e9});
    dp[0].second=0;
    for(int i=1;i<=n;i++){
        int j=lower_bound(dp.begin(),dp.end(),p[i][0],comp2)-dp.begin()-1;
        if(dp[i-1].first>=dp[j].first+p[i][2])dp[i]=dp[i-1];
        else dp[i].first=dp[j].first+p[i][2],dp[i].second=p[i][1];
    }
    cout<<dp[n].first<<endl;
    return 0;
}